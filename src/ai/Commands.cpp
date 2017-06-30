//
// Commands.cpp for zappy in /home/kerma/Projets/Epitech/PSU/zappy/src/graphic
//
// Made by kerma
// Login   <kerma@epitech.net>
//
// Started on  Wed Jun 28 17:40:38 2017 kerma
// Last update Fri Jun 30 13:49:28 2017 kerma
//

#include "Commands.hpp"

Commands::Commands() : _socket(NULL)
{
  _cmd["WELCOME"] = &Commands::HandlerWELCOME;

  _init["WELCOME"] = false;
}

Commands::~Commands() {}

void	Commands::SetSocket(Socket *socket) { _socket = socket; }

void	Commands::Bufferized(const ARGS &arg)
{
  for (VCIT it = arg.begin(); it != arg.end(); ++it)
    _tmp.push_back(*it);
}

std::string	Commands::ConcatARGS(const ARGS &arg, int i) const
{
  std::string	line;
  
  for (VCIT it = arg.begin() + i; it != arg.end(); ++it) {
    line += *it;
    if (it != arg.end() - 1)
      line += " ";
  }
  return line;
}

void	Commands::CommandParser(const std::string &cmd)
{
  std::istringstream	iss(cmd);
  std::string		line;
  std::string		tmp;
  ARGS			arg;

  if (_socket == NULL)
    return ;

  while (!_tmp.empty()) {
    arg.push_back(*(_tmp.begin()));
    _tmp.erase(_tmp.begin());
  }
  while (std::getline(iss, line, '\n')) {
    std::istringstream	liss(line);

    while (liss >> tmp)
      arg.push_back(tmp);
    if (arg.empty())
      return ;

    for (MCIT it = _cmd.begin(); it != _cmd.end(); ++it) {
      if (it->first == arg.front()) {
	(this->*(_cmd[arg.front()]))(arg);
      }
    }
    arg.clear();
  }
}

void	Commands::HandlerWELCOME(const ARGS &arg)
{
  if (arg.size() != 1 || _init["WELCOME"] == true)
    return ;

  // TODO get TeamName from AI class
  _socket->AddCommand("TeamName");
  _init["WELCOME"] = true;
}

void	Commands::SendFORWARD([[gnu::unused]] const std::string &none) const
{
  _socket->AddCommand("Forward");
}

void	Commands::SendRIGHT([[gnu::unused]] const std::string &none) const
{
  _socket->AddCommand("Right");
}

void	Commands::SendLEFT([[gnu::unused]] const std::string &none) const
{
  _socket->AddCommand("Left");
}

void	Commands::SendLOOK([[gnu::unused]] const std::string &none) const
{
  _socket->AddCommand("Look");
}

void	Commands::SendFORK([[gnu::unused]] const std::string &none) const
{
  _socket->AddCommand("Fork");
}

void	Commands::SendEJECT([[gnu::unused]] const std::string &none) const
{
  _socket->AddCommand("Eject");
}

void	Commands::SendINVENTORY([[gnu::unused]] const std::string &none) const
{
  _socket->AddCommand("Inventory");
}

void	Commands::SendCONNECTED([[gnu::unused]] const std::string &none) const
{
  _socket->AddCommand("Connected_nbr");
}

void	Commands::SendINCANTATION([[gnu::unused]] const std::string &none) const
{
  _socket->AddCommand("Incantation");
}

void	Commands::SendTAKE(const std::string &object) const
{
  _socket->AddCommand("Take " + object);
}

void	Commands::SendSET(const std::string &object) const
{
  _socket->AddCommand("Set " + object);
}

void	Commands::SendBROADCAST(const std::string &text) const
{
  _socket->AddCommand("Broadcast " + text);
}
