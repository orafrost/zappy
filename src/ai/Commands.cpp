//
// Commands.cpp for zappy in /home/kerma/Projets/Epitech/PSU/zappy/src/graphic
//
// Made by kerma
// Login   <kerma@epitech.net>
//
// Started on  Wed Jun 28 17:40:38 2017 kerma
// Last update Sun Jul  2 15:13:49 2017 kerma
//

#include "Commands.hpp"

Commands::Commands() : _needResponse(false), _socket(NULL), _callback(NULL)
{
  _cmd["WELCOME"] = &Commands::HandlerWELCOME;

  _init["WELCOME"] = false;
}

Commands::~Commands() {}

void	Commands::SetAI(AI *ai)
{
  _ai = ai;
  _ai->SetSender(this);
}

void	Commands::SetSocket(Socket *socket) { _socket = socket; }
void	Commands::SetTeamName(const std::string &name) { _team = name; }
void	Commands::SetCallback(CALLBACK callback) { _callback = callback; }

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

void	Commands::SendFORWARD() 
{
  _socket->AddCommand("Forward");
  _needResponse = true;
}

void	Commands::SendRIGHT() 
{
  _socket->AddCommand("Right");
  _needResponse = true;
}

void	Commands::SendLEFT() 
{
  _socket->AddCommand("Left");
  _needResponse = true;
} 

void	Commands::SendLOOK() 
{
  _socket->AddCommand("Look");
  _needResponse = true;
}

void	Commands::SendFORK() 
{
  _socket->AddCommand("Fork");
  _needResponse = true;
}

void	Commands::SendEJECT() 
{
  _socket->AddCommand("Eject");
  _needResponse = true;
}

void	Commands::SendINVENTORY() 
{
  _socket->AddCommand("Inventory");
  _needResponse = true;
} 

void	Commands::SendCONNECTED() 
{
  _socket->AddCommand("Connected_nbr");
  _needResponse = true;
}

void	Commands::SendINCANTATION() 
{
  _socket->AddCommand("Incantation");
  _needResponse = true;
}

void	Commands::SendTAKE(const std::string &object) 
{
  _socket->AddCommand("Take " + object);
  _needResponse = true;
}

void	Commands::SendSET(const std::string &object) 
{
  _socket->AddCommand("Set " + object);
  _needResponse = true;
}

void	Commands::SendBROADCAST(const std::string &text) 
{
  _socket->AddCommand("Broadcast " + text);
  _needResponse = true;
}
