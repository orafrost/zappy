//
// Commands.cpp for zappy in /home/kerma/Projets/Epitech/PSU/zappy/src/graphic
//
// Made by kerma
// Login   <kerma@epitech.net>
//
// Started on  Wed Jun 28 17:40:38 2017 kerma
// Last update Sun Jul  2 17:52:47 2017 kerma
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
  _cmd["pic"] = &Commands::HandlerPIC;  
  _cmd["pie"] = &Commands::HandlerPIE;  
  _cmd["pdr"] = &Commands::HandlerPDR;  
  _cmd["pgt"] = &Commands::HandlerPGT;  
  _cmd["pdi"] = &Commands::HandlerPDI;  
  _cmd["enw"] = &Commands::HandlerENW;
  _cmd["eht"] = &Commands::HandlerEHT;
  _cmd["sgt"] = &Commands::HandlerSGT;
  _cmd["seg"] = &Commands::HandlerSEG;

  _init["WELCOME"] = false;
  _init["msz"] = false;
  _init["sgt"] = false;
  _init["seg"] = false;
}

Commands::~Commands() {}

void	Commands::SetSocket(Socket *socket) { _socket = socket; }
void	Commands::SetGraphic(Graphic *graphic) { _graphic = graphic; }

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
  std::string	elem;
  ARGS		arg;
  int		ret;
  bool		clean = true;	

  if (_socket == NULL)
    return ;

  while (!_buffer.empty()) {
    arg.push_back(*(_buffer.begin()));
    _buffer.erase(_buffer.begin());
  }

  Utils::TAB tab = _utils.Split(cmd);
  for (Utils::TIT it = tab.begin(); it != tab.end(); ++it) {
    
    std::istringstream	iss(*it);
    while (iss >> elem)
      arg.push_back(elem);
    if (arg.empty())
      return ;

    for (MCIT mit = _cmd.begin(); mit != _cmd.end(); ++mit) {
      if (mit->first == arg.front()) {
	if ((ret = (this->*(_cmd[arg.front()]))(arg)) == 1) {
	  std::cout << "KO" << std::endl;
	  clean = false;
	  _buffer = arg;
	} else if (ret == 0) {
	  std::cout << "OK" << std::endl;
	  break ;
	}	
      }
    }	  
    if (clean == true)
      arg.clear();
  }
}

int	Commands::HandlerWELCOME(const ARGS &arg)
{
  if (_init["WELCOME"] == true)
    return 0;
  if (arg.size() != 1)
    return 1;

  _socket->AddCommand("GRAPHIC");
  _init["WELCOME"] = true;
  return 0;
}

int	Commands::HandlerMSZ(const ARGS &arg)
{
  if (_init["WELCOME"] == false || _init["msz"] == true)
    return 0;
  if (arg.size() != 3)
    return 1;
  if (_utils.isNum(arg[1]) == false ||
      _utils.isNum(arg[2]) == false)
    return 0;
  
  int	width = _utils.StringToInt(arg[1]);
  int	height = _utils.StringToInt(arg[2]);

  _graphic->setMapDimensions(width, height);
  _init["msz"] = true;
  return 0;
}

int	Commands::HandlerBCT(const ARGS &arg)
{
  if (_init["WELCOME"] == false)
    return 0;
  if (arg.size() != 10)
    return 1;  
  if (_utils.isNum(arg[1]) == false ||
      _utils.isNum(arg[2]) == false)
    return 0;
  
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
  return 0;
}

int	Commands::HandlerTNA(const ARGS &arg)
{
  if (_init["WELCOME"] == false)
    return 0;
  if (arg.size() < 2)
    return 1;

  std::string name = ConcatARGS(arg, 1);
  _graphic->addTeam(name);
  return 0;
}

int	Commands::HandlerPNW(const ARGS &arg)
{
  if (_init["WELCOME"] == false)
    return 0;
  if (arg.size() < 7)
    return 1;
  if (_utils.isNum(arg[1]) == false ||
      _utils.isNum(arg[2]) == false ||
      _utils.isNum(arg[3]) == false ||
      _utils.isNum(arg[4]) == false ||
      _utils.isNum(arg[5]) == false)
    return 0;
  
  std::string	name = ConcatARGS(arg, 6);
  int		id = _utils.StringToInt(arg[1]);		
  int		X = _utils.StringToInt(arg[2]);		
  int		Y = _utils.StringToInt(arg[3]);		
  int		dir = _utils.StringToInt(arg[4]);		
  int		level = _utils.StringToInt(arg[5]);		

  _graphic->addPlayer(id, X, Y, dir - 1, level, name);
  return 0;
}

int	Commands::HandlerPPO(const ARGS &arg)
{
  if (_init["WELCOME"] == false)
    return 0;
  if (arg.size() != 5)
    return 1;
  if (_utils.isNum(arg[1]) == false ||
      _utils.isNum(arg[2]) == false ||
      _utils.isNum(arg[3]) == false ||
      _utils.isNum(arg[4]) == false)
    return 0;

  int	id = _utils.StringToInt(arg[1]);		
  int	X = _utils.StringToInt(arg[2]);		
  int	Y = _utils.StringToInt(arg[3]);		
  int	dir = _utils.StringToInt(arg[4]);		

  _graphic->setPlayerPosition(id, X, Y, dir - 1);
  return 0;
}

int	Commands::HandlerPLV(const ARGS &arg)
{
  if (_init["WELCOME"] == false)
    return 0;
  if (arg.size() != 3)
    return 1;
  if (_utils.isNum(arg[1]) == false ||
      _utils.isNum(arg[2]) == false)
    return 0;

  int	id = _utils.StringToInt(arg[1]);		
  int	level = _utils.StringToInt(arg[2]);		

  _graphic->setLevel(id, level);
  return 0;
}

int	Commands::HandlerPBC(const ARGS &arg)
{
  if (_init["WELCOME"] == false)
    return 0;
  if (arg.size() < 3)
    return 1;
  if (_utils.isNum(arg[1]) == false)
    return 0;

  int	id = _utils.StringToInt(arg[1]);		

  _graphic->playerBroadcast(id);
  return 0;
}

int	Commands::HandlerPIC(const ARGS &arg)
{
  if (_init["WELCOME"] == false)
    return 0;
  if (arg.size() != 3)
    return 1;
  if (_utils.isNum(arg[1]) == false ||
      _utils.isNum(arg[2]) == false)
    return 0;

  int	X = _utils.StringToInt(arg[1]);		
  int	Y = _utils.StringToInt(arg[2]);		

  _graphic->startIncantation(X, Y);
  return 0;
}

int	Commands::HandlerPIE(const ARGS &arg)
{
  if (_init["WELCOME"] == false)
    return 0;
  if (arg.size() != 3)
    return 1;
  if (_utils.isNum(arg[1]) == false ||
      _utils.isNum(arg[2]) == false)
    return 0;

  int	X = _utils.StringToInt(arg[1]);		
  int	Y = _utils.StringToInt(arg[2]);		

  _graphic->endIncantation(X, Y);
  return 0;
}

int	Commands::HandlerPDR(const ARGS &arg)
{
  if (_init["WELCOME"] == false)
    return 0;
  if (arg.size() != 3)
    return 1;
  if (_utils.isNum(arg[1]) == false ||
      _utils.isNum(arg[2]) == false)
    return 0;

  int	id = _utils.StringToInt(arg[1]);		
  int	ressource = _utils.StringToInt(arg[2]);		

  _graphic->addResource(id, ressource);
  return 0;
}

int	Commands::HandlerPGT(const ARGS &arg)
{
  if (_init["WELCOME"] == false)
    return 0;
  if (arg.size() != 3)
    return 1;
  if (_utils.isNum(arg[1]) == false ||
      _utils.isNum(arg[2]) == false)
      return 0;

  int	id = _utils.StringToInt(arg[1]);		
  int	ressource = _utils.StringToInt(arg[2]);		

  _graphic->removeResource(id, ressource);
  return 0;
}

int	Commands::HandlerPDI(const ARGS &arg)
{
  if (_init["WELCOME"] == false)
    return 0;
  if (arg.size() != 2)
    return 1;
  if (_utils.isNum(arg[1]) == false)
    return 0;

  int	id = _utils.StringToInt(arg[1]);		

  _graphic->killPlayer(id);
  return 0;
}

int	Commands::HandlerENW(const ARGS &arg)
{
  if (_init["WELCOME"] == false)
    return 0;
  if (arg.size() != 5)
    return 1;
  if (_utils.isNum(arg[1]) == false ||
      _utils.isNum(arg[2]) == false ||
      _utils.isNum(arg[3]) == false ||
      _utils.isNum(arg[4]) == false)
    return 0;

  int	id_egg = _utils.StringToInt(arg[1]);		
  int	X = _utils.StringToInt(arg[3]);		
  int	Y = _utils.StringToInt(arg[4]);		

  _graphic->addEgg(id_egg, X, Y);
  return 0;
}

int	Commands::HandlerEHT(const ARGS &arg)
{
  if (_init["WELCOME"] == false)
    return 0;
  if (arg.size() != 2)
   return 1;
  if (_utils.isNum(arg[1]) == false)
    return 0;

  int	id = _utils.StringToInt(arg[1]);		

  _graphic->hatchEgg(id);
  return 0;
}

int	Commands::HandlerSGT(const ARGS &arg)
{
  if (_init["WELCOME"] == false)
    return 0;
  if (arg.size() != 2 || _init["sgt"] == true)
    return 1;
  if (_utils.isNum(arg[1]) == false)
    return 0;

  int	frequence = _utils.StringToInt(arg[1]);		

  _graphic->setFrequence(frequence);
  _init["sgt"] = true;
  return 0;
}

int	Commands::HandlerSEG(const ARGS &arg)
{
  if (_init["WELCOME"] == false ||  _init["seg"] == true)
    return 0;
  if (arg.size() != 2)
    return 1;
  if (_graphic->endGame(arg[1]) == 0)
    _init["seg"] = true;
  return 0;
}
