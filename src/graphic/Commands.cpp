//
// Commands.cpp for zappy in /home/kerma/Projets/Epitech/PSU/zappy/src/graphic
//
// Made by kerma
// Login   <kerma@epitech.net>
//
// Started on  Wed Jun 28 17:40:38 2017 kerma
// Last update Thu Jun 29 12:37:42 2017 kerma
//

#include "Commands.hpp"

Commands::Commands() :  _init(false), _socket(NULL)
{
  _cmd["WELCOME"] = &Commands::HandlerWELCOME;
  _cmd["msz"] = &Commands::HandlerMSZ;
  _cmd["bct"] = &Commands::HandlerBCT;
  _cmd["tna"] = &Commands::HandlerTNA;
  _cmd["sgt"] = &Commands::HandlerSGT;
}

Commands::~Commands() {}

void	Commands::SetSocket(Socket *socket) { _socket = socket; }

void	Commands::Bufferized(const ARGS &arg)
{
  for (VCIT it = arg.begin(); it != arg.end(); ++it)
    _tmp.push_back(*it);
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
	if (it->first == "WELCOME")
	  _init = true;
      }
    }
    arg.clear();
  }
}

void	Commands::HandlerWELCOME(const ARGS &arg)
{
  if (arg.size() != 1 || _init == true)
    return ;
  _socket->AddCommand("GRAPHIC");
}

void	Commands::HandlerMSZ(const ARGS &arg)
{
  if (arg.size() != 3)
    return ;
  std::cout << "Width: " << arg[1] << " - "
	    << "Height: " << arg[2] << std::endl;
}

void	Commands::HandlerBCT(const ARGS &arg)
{
  if (arg.size() != 10) {
    Bufferized(arg);
    return ;
  }
  std::cout << "Tile ["
	    << arg[1] << ", "
	    << arg[2] << "]: "
	    << arg[3] << " "
	    << arg[4] << " "
	    << arg[5] << " "
	    << arg[6] << " "
	    << arg[7] << " "
	    << arg[8] << " "
	    << arg[9] << " "
	    << std::endl;
  
}

void	Commands::HandlerTNA(const ARGS &arg)
{
  if (arg.size() != 2)
    return ;
  std::cout << "Team: " << arg[1] << std::endl;  
}

void	Commands::HandlerSGT(const ARGS &arg)
{
  if (arg.size() != 2)
    return ;
  std::cout << "Frequency: " << arg[1] << std::endl;  
}
