//
// Commands.cpp for zappy in /home/kerma/Projets/Epitech/PSU/zappy/src/graphic
//
// Made by kerma
// Login   <kerma@epitech.net>
//
// Started on  Wed Jun 28 17:40:38 2017 kerma
// Last update Thu Jun 29 16:42:31 2017 kerma
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

  if (_utils.isNum(arg[1]) == false ||
      _utils.isNum(arg[2]) == false)
    return ;
  
  int	width = _utils.StringToInt(arg[1]);
  int	height = _utils.StringToInt(arg[2]);

  _graphic->setMapDimensions(width, height);
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

  if (_utils.isNum(arg[1]) == false ||
      _utils.isNum(arg[2]) == false)
    return ;
  
  int	X = _utils.StringToInt(arg[1]);
  int	Y = _utils.StringToInt(arg[2]);
  TILE	tile;

  tile.push_back(_utils.StringToInt(*(arg.begin() + 3)));
  tile.push_back(_utils.StringToInt(*(arg.begin() + 4)));
  tile.push_back(_utils.StringToInt(*(arg.begin() + 5)));
  tile.push_back(_utils.StringToInt(*(arg.begin() + 6)));
  tile.push_back(_utils.StringToInt(*(arg.begin() + 7)));
  tile.push_back(_utils.StringToInt(*(arg.begin() + 8)));
  tile.push_back(_utils.StringToInt(*(arg.begin() + 9)));
  _graphic->setBlock(X, Y, tile);
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
  _graphic->addTeam(name);
}

void	Commands::HandlerPNW(const ARGS &arg)
{
  if (_init["WELCOME"] == false)
    return ;
  if (arg.size() < 7) {
    Bufferized(arg);
    return ;
  }

  if (_utils.isNum(arg[1]) == false ||
      _utils.isNum(arg[2]) == false ||
      _utils.isNum(arg[3]) == false ||
      _utils.isNum(arg[4]) == false ||
      _utils.isNum(arg[5]) == false)
    return ;
  
  std::string	name = ConcatARGS(arg, 6);
  int		id = _utils.StringToInt(arg[1]);		
  int		X = _utils.StringToInt(arg[2]);		
  int		Y = _utils.StringToInt(arg[3]);		
  int		dir = _utils.StringToInt(arg[4]);		
  int		level = _utils.StringToInt(arg[5]);		

  _graphic->addPayer(id, X, Y, dir, level, name);
}

void	Commands::HandlerPPO(const ARGS &arg)
{
  if (_init["WELCOME"] == false)
    return ;
  if (arg.size() != 5) {
    Bufferized(arg);
    return ;
  }

  if (_utils.isNum(arg[1]) == false ||
      _utils.isNum(arg[2]) == false ||
      _utils.isNum(arg[3]) == false ||
      _utils.isNum(arg[4]) == false)
    return ;

  int	id = _utils.StringToInt(arg[1]);		
  int	X = _utils.StringToInt(arg[2]);		
  int	Y = _utils.StringToInt(arg[3]);		
  int	dir = _utils.StringToInt(arg[4]);		

  _graphic->setPlayerPostion(id, X, Y, dir);
}

void	Commands::HandlerPLV(const ARGS &arg)
{
  if (_init["WELCOME"] == false)
    return ;
  if (arg.size() != 3) {
    Bufferized(arg);
    return ;
  }

  if (_utils.isNum(arg[1]) == false ||
      _utils.isNum(arg[2]) == false)
    return ;

  int	id = _utils.StringToInt(arg[1]);		
  int	level = _utils.StringToInt(arg[2]);		

  _graphic->setLevel(id, level);
}

void	Commands::HandlerPBC(const ARGS &arg)
{
  if (_init["WELCOME"] == false)
    return ;
  if (arg.size() < 3) {
    Bufferized(arg);
    return ;
  }

  if (_utils.isNum(arg[1]) == false)
    return ;

  int	id = _utils.StringToInt(arg[1]);		

  _graphic->playerBroadcast(id);
}

void	Commands::HandlerSGT(const ARGS &arg)
{
  if (_init["WELCOME"] == false)
    return ;
  if (arg.size() != 2 || _init["sgt"] == true) {
    Bufferized(arg);
    return ;
  }

  if (_utils.isNum(arg[1]) == false)
    return ;

  int	frequence = _utils.StringToInt(arg[1]);		

  _graphic->setFrequence(frequence);
  _init["sgt"] = true;
}
