//
// Commands.hpp for zappy in /home/kerma/Projets/Epitech/PSU/zappy/src/graphic/include
//
// Made by kerma
// Login   <kerma@epitech.net>
//
// Started on  Wed Jun 28 17:41:22 2017 kerma
// Last update Sun Jul  2 17:15:49 2017 kerma
//

#ifndef COMMANDS_HPP_
# define COMMANDS_HPP_

# include <iostream>
# include <sstream>
# include <iterator>
# include <vector>
# include <map>

# include "Utils.hpp"
# include "Graphic.hpp"
# include "Socket.hpp"
class	Socket;

class	Commands
{
  typedef std::vector<int>								TILE;
  typedef std::vector<std::string>							ARGS;
  typedef std::map<std::string, bool>							INIT;
  typedef std::map<std::string, int (Commands::*)(const ARGS &)>			CMDS;

  typedef std::vector<std::string>::const_iterator					VCIT;
  typedef std::map<std::string, int (Commands::*)(const ARGS &)>::const_iterator	MCIT;
  
private:
  CMDS		_cmd;
  INIT		_init;
  ARGS		_buffer;
  Utils		_utils;
  Socket	*_socket;
  Graphic	*_graphic;

private:
  std::string	ConcatARGS(const ARGS &arg, int i) const;
  int		HandlerWELCOME(const ARGS &arg);
  int		HandlerMSZ(const ARGS &arg);
  int		HandlerBCT(const ARGS &arg);
  int		HandlerTNA(const ARGS &arg);
  int		HandlerPNW(const ARGS &arg);
  int		HandlerPPO(const ARGS &arg);
  int		HandlerPLV(const ARGS &arg);
  int		HandlerPBC(const ARGS &arg);
  int		HandlerPIC(const ARGS &arg);
  int		HandlerPIE(const ARGS &arg);
  int		HandlerPDR(const ARGS &arg);
  int		HandlerPGT(const ARGS &arg);
  int		HandlerPDI(const ARGS &arg);
  int		HandlerENW(const ARGS &arg);
  int		HandlerEHT(const ARGS &arg);
  int		HandlerSGT(const ARGS &arg);
  int		HandlerSEG(const ARGS &arg);
  
public:
  void		SetSocket(Socket *socket);
  void		SetGraphic(Graphic *graphic);
  void		CommandParser(const std::string &cmd);
  
public:
  Commands();
  ~Commands();
};

#endif
