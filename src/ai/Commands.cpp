//
// Commands.cpp for zappy in /home/kerma/Projets/Epitech/PSU/zappy/src/graphic
//
// Made by kerma
// Login   <kerma@epitech.net>
//
// Started on  Wed Jun 28 17:40:38 2017 kerma
// Last update Sun Jul  2 21:56:13 2017 kerma
//

#include "Commands.hpp"

Commands::Commands() : _count(0), _needResponse(false), _init(false), _socket(NULL), _resp(NULL) {}
Commands::~Commands() {}

void	Commands::SetAI(AI *ai)
{
  _ai = ai;
  _ai->SetSender(this);
}

void	Commands::IncCount() { _count++; }
void	Commands::SetSocket(Socket *socket) { _socket = socket; }
void	Commands::SetTeamName(const std::string &name) { _team = name; }
int	Commands::IsResponse(const std::string &cmd)
{
  if (cmd.size() > 11 && cmd.substr(0, 7) == "message")
    return 1;
  if (cmd.size() > 7 && cmd.substr(0, 5) == "eject")
    return 1;
  return 0;
}

void	Commands::CommandParser(const std::string &cmd)
{
  if (_socket == NULL)
    return ;

  if (_count == 2)
    _ai->SetWait();

  Utils::TAB tab = _utils.Split(cmd);
  for (Utils::TIT it = tab.begin(); it != tab.end(); ++it) {
    if (*it == "dead")
      exit(0);
    if (_needResponse == true && IsResponse(*it) == 0 && _resp != NULL) {
      (this->*(_resp))(*it);
      _needResponse = false;
      _resp = NULL;
    }
    else if (*it == "WELCOME")
      HandlerWELCOME();    
  }
}

void	Commands::reset(const std::string &arg) { _ai->reset(arg); }
void	Commands::getVision(const std::string &arg) { _ai->getVision(arg); }

void	Commands::HandlerWELCOME()
{
  if (_init == true)
    return ;

  _socket->AddCommand(_team);
  _init = true;
}

void	Commands::SendFORWARD() 
{
  _socket->AddCommand("Forward");
  _needResponse = true;
  _resp = &Commands::reset;
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
  _resp = &Commands::getVision;
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
  _resp = &Commands::reset;
}

void	Commands::SendTAKE(const std::string &object) 
{
  _socket->AddCommand("Take " + object);
  _needResponse = true;
  _resp = &Commands::reset;
}

void	Commands::SendSET(const std::string &object) 
{
  _socket->AddCommand("Set " + object);
  _needResponse = true;
  _resp = &Commands::reset;
}

void	Commands::SendBROADCAST(const std::string &text) 
{
  _socket->AddCommand("Broadcast " + text);
  _needResponse = true;
}
