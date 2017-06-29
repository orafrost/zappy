//
// Commands.cpp for zappy in /home/kerma/Projets/Epitech/PSU/zappy/src/graphic
//
// Made by kerma
// Login   <kerma@epitech.net>
//
// Started on  Wed Jun 28 17:40:38 2017 kerma
// Last update Thu Jun 29 15:29:57 2017 kerma
//

#include "Commands.hpp"

Commands::Commands() : _socket(NULL), _graphic(NULL)
{
  _cmd["WELCOME"] = &Commands::HandlerWELCOME;
  _cmd["msz"] = &Commands::HandlerMSZ;
  _cmd["bct"] = &Commands::HandlerBCT;
  _cmd["tna"] = &Commands::HandlerTNA;
  _cmd["pnw"] = &Commands::HandlerPNW;
  _cmd["ppo"] = &Commands::HandlerPPO;
  _cmd["plv"] = &Commands::HandlerPLV;
  _cmd["pin"] = &Commands::HandlerPIN;
  _cmd["pex"] = &Commands::HandlerPEX;
  _cmd["pbc"] = &Commands::HandlerPBC;  
  _cmd["sgt"] = &Commands::HandlerSGT;

  _init["WELCOME"] = false;
  _init["msz"] = false;
  _init["sgt"] = false;
}

Commands::~Commands() {}

void	Commands::SetSocket(Socket *socket) { _socket = socket; }
void	Commands::SetGraphic(Graphic *graphic) { _graphic = graphic; }

void	Commands::Bufferized(const ARGS &arg)
{
  for (VCIT it = arg.begin(); it != arg.end(); ++it)
    _tmp.push_back(*it);
}

std::string	Commands::ConcatARGS(const ARGS &arg, int i) const
{
  std::string	line;
  
  for (VCIT it = arg.begin() + i; it != arg.end(); ++it)
    line += *it;
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

  _socket->AddCommand("GRAPHIC");
  _init["WELCOME"] = true;
}

void	Commands::HandlerMSZ(const ARGS &arg)
{
  if (_init["WELCOME"] == false)
    return ;
  if (arg.size() != 3 || _init["msz"] == true) {
    Bufferized(arg);
    return ;
  }
  std::cout << "Width: " << arg[1] << " - "
	    << "Height: " << arg[2] << std::endl;
  _init["msz"] = true;
}

void	Commands::HandlerBCT(const ARGS &arg)
{
  if (_init["WELCOME"] == false)
    return ;
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
  if (_init["WELCOME"] == false)
    return ;
  if (arg.size() < 2) {
    Bufferized(arg);
    return ;
  }

  std::string name = ConcatARGS(arg, 1);
  std::cout << "Team: " << name << std::endl;
}

void	Commands::HandlerPNW(const ARGS &arg)
{
  if (_init["WELCOME"] == false)
    return ;
  if (arg.size() < 7) {
    Bufferized(arg);
    return ;
  }

  std::string name = ConcatARGS(arg, 6);
  std::cout << "Player Connection: " << std::endl
	    << "  Id:\t" << arg[1] << std::endl  
	    << "  X:\t" << arg[2] << std::endl  
	    << "  Y:\t" << arg[3] << std::endl  
	    << "  Dir:\t" << arg[4] << std::endl  
	    << "  Level:\t" << arg[5] << std::endl  
	    << "  Team:\t" << name << std::endl;
}

void	Commands::HandlerPPO(const ARGS &arg)
{
  if (_init["WELCOME"] == false)
    return ;
  if (arg.size() != 5) {
    Bufferized(arg);
    return ;
  }
  std::cout << "Player Position: " << std::endl
	    << "  Id:\t" << arg[1] << std::endl  
	    << "  X:\t" << arg[2] << std::endl  
	    << "  Y:\t" << arg[3] << std::endl  
	    << "  Dir:\t" << arg[4] << std::endl;
}

void	Commands::HandlerPLV(const ARGS &arg)
{
  if (_init["WELCOME"] == false)
    return ;
  if (arg.size() != 3) {
    Bufferized(arg);
    return ;
  }
  std::cout << "Player Level: " << std::endl
	    << "  Id:\t" << arg[1] << std::endl  
	    << "  Level:\t" << arg[2] << std::endl;
}

void	Commands::HandlerPIN(const ARGS &arg)
{
  if (_init["WELCOME"] == false)
    return ;
  if (arg.size() != 11 ) {
    Bufferized(arg);
    return ;
  }
  std::cout << "Player Inventory: " << std::endl
	    << "  Id:\t" << arg[1] << std::endl  
	    << "  X:\t" << arg[2] << std::endl
	    << "  Y:\t" << arg[3] << std::endl
	    << "  Food:\t" << arg[4] << std::endl
    	    << "  Linemate:\t" << arg[5] << std::endl
    	    << "  Deraumere:\t" << arg[6] << std::endl
	    << "  Sibur:\t" << arg[7] << std::endl
	    << "  Mendiane:\t" << arg[8] << std::endl
	    << "  Phiras:\t" << arg[9] << std::endl
	    << "  Thystame:\t" << arg[10] << std::endl;
}

void	Commands::HandlerPEX(const ARGS &arg)
{
  if (_init["WELCOME"] == false)
    return ;
  if (arg.size() != 2) {
    Bufferized(arg);
    return ;
  }
  std::cout << "Player " << arg[1] << " eject's" << std::endl;
}

void	Commands::HandlerPBC(const ARGS &arg)
{
  if (_init["WELCOME"] == false)
    return ;
  if (arg.size() != 3) {
    Bufferized(arg);
    return ;
  }

  std::string message = ConcatARGS(arg, 2);
  std::cout << "Player " << arg[1] << " broadcast: "
	    << message << std::endl;
}

void	Commands::HandlerSGT(const ARGS &arg)
{
  if (_init["WELCOME"] == false)
    return ;
  if (arg.size() != 2 || _init["sgt"] == true) {
    Bufferized(arg);
    return ;
  }
  std::cout << "Frequency: " << arg[1] << std::endl;  
  _init["sgt"] = true;
}
