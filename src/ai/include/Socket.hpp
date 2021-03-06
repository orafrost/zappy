//
// Socket.hpp for zappy in /home/kerma/Projets/Epitech/PSU/zappy/src/graphic/include
//
// Made by kerma
// Login   <kerma@epitech.net>
//
// Started on  Wed Jun 28 17:41:22 2017 kerma
// Last update Sun Jul  2 15:12:43 2017 kerma
//

#ifndef SOCKET_HPP_
# define SOCKET_HPP_

# include <sys/socket.h>
# include <netinet/in.h>
# include <sys/types.h>
# include <arpa/inet.h>
# include <string.h>
# include <unistd.h>
# include <netdb.h>

# include <iostream>
# include <iterator>
# include <queue>

# include "Commands.hpp"
class Commands;
class AI;

# define ERROR	(84) 

class	Socket
{
  typedef std::queue<std::string>	BUFFER;
  
private:
  int			_fd;
  int			_cmd;
  BUFFER		_out;
  fd_set		_fd_read;
  fd_set		_fd_write;
  Commands		*_parser;
  struct sockaddr_in    _sIn;
  
private:
  int	Error(const std::string &err) const;
  int	InitSocket(int port, const std::string &ip);
  void	ReadSocket();
  void	WriteSocket();

public:
  void	SetAI(AI *ai);
  void	SetTeamName(const std::string &name);
  int	Connect(int port, const std::string &ip);
  void	AddCommand(const std::string &cmd);
  void	ServerTalk();

public:
  Socket();
  ~Socket();
};

#endif
