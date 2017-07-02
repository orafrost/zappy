//
// Commands.cpp for zappy in /home/kerma/Projets/Epitech/PSU/zappy/src/graphic
//
// Made by kerma
// Login   <kerma@epitech.net>
//
// Started on  Wed Jun 28 17:40:38 2017 kerma
// Last update Sun Jul  2 12:52:55 2017 kerma
//

#include "Commands.hpp"

Commands::Commands() : _ai(new AI()), _socket(NULL)
{
  _ai->SetSender(this);

  _cmd["WELCOME"] = &Commands::HandlerWELCOME;

  _init["WELCOME"] = false;

}

Commands::~Commands() {}

void	Commands::SetSocket(Socket *socket) { _socket = socket; }
void	Commands::SetTeamName(const std::string &name) { _team = name; }

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

  _socket->AddCommand(_team);
  _init["WELCOME"] = true;
}

void	Commands::SendFORWARD() const
{
  _socket->AddCommand("Forward");
}

void	Commands::SendRIGHT() const
{
  _socket->AddCommand("Right");
}

void	Commands::SendLEFT() const
{
  _socket->AddCommand("Left");
} 

void	Commands::SendLOOK() const
{
  _socket->AddCommand("Look");
}

void	Commands::SendFORK() const
{
  _socket->AddCommand("Fork");
}

void	Commands::SendEJECT() const
{
  _socket->AddCommand("Eject");
}

void	Commands::SendINVENTORY() const
{
  _socket->AddCommand("Inventory");
} 

void	Commands::SendCONNECTED() const
{
  _socket->AddCommand("Connected_nbr");
}

void	Commands::SendINCANTATION() const
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
