//
// Commands.hpp for zappy in /home/kerma/Projets/Epitech/PSU/zappy/src/graphic/include
//
// Made by kerma
// Login   <kerma@epitech.net>
//
// Started on  Wed Jun 28 17:41:22 2017 kerma
// Last update Thu Jun 29 15:21:00 2017 kerma
//

#ifndef COMMANDS_HPP_
# define COMMANDS_HPP_

# include <iostream>
# include <sstream>
# include <iterator>
# include <vector>
# include <map>

# include <Graphic.hpp>
# include <Socket.hpp>
class	Socket;

class	Commands
{
  typedef std::vector<std::string>							ARGS;
  typedef std::map<std::string, bool>							INIT;
  typedef std::map<std::string, void (Commands::*)(const ARGS &)>			CMDS;

  typedef std::vector<std::string>::const_iterator					VCIT;
  typedef std::map<std::string, void (Commands::*)(const ARGS &)>::const_iterator	MCIT;
  
private:
  CMDS		_cmd;
  ARGS		_tmp;
  INIT		_init;
  Socket	*_socket;
  Graphic	*_graphic;

private:
  void		Bufferized(const ARGS &arg);
  std::string	ConcatARGS(const ARGS &arg, int i) const;
  void		HandlerWELCOME(const ARGS &arg);
  void		HandlerMSZ(const ARGS &arg);
  void		HandlerBCT(const ARGS &arg);
  void		HandlerTNA(const ARGS &arg);
  void		HandlerPNW(const ARGS &arg);
  void		HandlerPPO(const ARGS &arg);
  void		HandlerPLV(const ARGS &arg);
  void		HandlerPIN(const ARGS &arg);
  void		HandlerPEX(const ARGS &arg);
  void		HandlerPBC(const ARGS &arg);
  void		HandlerSGT(const ARGS &arg);
  
public:
  void		SetSocket(Socket *socket);
  void		SetGraphic(Graphic *graphic);
  void		CommandParser(const std::string &cmd);
  
public:
  Commands();
  ~Commands();
};

#endif
