//
// Socket.cpp for zappy in /home/kerma/Projets/Epitech/PSU/zappy/src/graphic
//
// Made by kerma
// Login   <kerma@epitech.net>
//
// Started on  Wed Jun 28 17:40:38 2017 kerma
// Last update Sun Jul  2 16:27:36 2017 kerma
//

#include "Socket.hpp"

Socket::Socket() : _fd(-1), _parser(new Commands()) {}
Socket::~Socket()
{
  if (_fd != -1)
    close(_fd);
}

int	Socket::Error(const std::string &err) const
{
  std::cerr << "Error: " << err << std::endl;
  exit(ERROR);
}

int	Socket::InitSocket(int port)
{
  struct protoent	*pe;
  int			optval;

  optval = 1;
  _sIn.sin_family = AF_INET;
  _sIn.sin_port = htons(port);
  _sIn.sin_addr.s_addr = inet_addr("127.0.0.1");
  if ((pe = getprotobyname("TCP")) == NULL)
    Error("Function \'getprotobyname\' failed.");
  if ((_fd = socket(PF_INET, SOCK_STREAM, pe->p_proto)) == -1)
    Error("Function \'socket\' failed.");
  if (setsockopt(_fd, SOL_SOCKET, SO_REUSEADDR, &optval, sizeof(int)) == -1)
    Error("Function \'setsockopt\' failed.");
  return (0);
}

int	Socket::Connect(int port)
{
  std::cout << "Port: " << port << std::endl;
  InitSocket(port);
  if (connect(_fd, (const struct sockaddr *)&_sIn, sizeof(_sIn)) == -1)
    Error("Function \'connect\' failed.");
  _parser->SetSocket(this);
  return (0);
}

void	Socket::SetGraphicPtr(Graphic *graphic) { _parser->SetGraphic(graphic); }

void	Socket::AddCommand(const std::string &cmd)
{
  _out.push(cmd);
}

void	Socket::ReadSocket()
{
  char	buff[1024];

  memset(buff, 0, 1024);
  if (read(_fd, buff, 1020) <= 0) {
    std::cout << "Connexion closed by server" << std::endl;
    exit(0);
  }

  std::string command(buff);
  _parser->CommandParser(command);
}

void	Socket::WriteSocket()
{
  if (!_out.empty()) {
    _out.front().push_back('\n');
    write(_fd, _out.front().c_str(), _out.front().size());
    _out.pop();
  }
}

void	Socket::ServerTalk()
{
  FD_ZERO(&_fd_read);
  FD_ZERO(&_fd_write);
  FD_SET(_fd, &_fd_read);
  FD_SET(_fd, &_fd_write);
  if (select(_fd + 1, &_fd_read, &_fd_write, NULL, NULL) == -1)
    Error("Function \'select\' failed.");
  if (FD_ISSET(_fd, &_fd_read))
    ReadSocket();
  if (FD_ISSET(_fd, &_fd_write))
    WriteSocket();
}
