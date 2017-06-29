//
// Commands.hpp for zappy in /home/kerma/Projets/Epitech/PSU/zappy/src/graphic/include
//
// Made by kerma
// Login   <kerma@epitech.net>
//
// Started on  Wed Jun 28 17:41:22 2017 kerma
// Last update Thu Jun 29 12:35:08 2017 kerma
//

#ifndef COMMANDS_HPP_
# define COMMANDS_HPP_

# include <iostream>
# include <sstream>
# include <iterator>
# include <vector>
# include <map>

# include <Socket.hpp>
class	Socket;

class	Commands
{
  typedef std::vector<std::string>							ARGS;
  typedef std::map<std::string, void (Commands::*)(const ARGS &)>			CMDS;

  typedef std::vector<std::string>::const_iterator					VCIT;
  typedef std::map<std::string, void (Commands::*)(const ARGS &)>::const_iterator	MCIT;
  
private:
  CMDS		_cmd;
  ARGS		_tmp;
  bool		_init;
  Socket	*_socket;

private:
  void	Bufferized(const ARGS &arg);
  void	HandlerWELCOME(const ARGS &arg);
  void	HandlerMSZ(const ARGS &arg);
  void	HandlerBCT(const ARGS &arg);
  void	HandlerTNA(const ARGS &arg);
  void	HandlerSGT(const ARGS &arg);
  
public:
  void	SetSocket(Socket *socket);
  void	CommandParser(const std::string &cmd);
  
public:
  Commands();
  ~Commands();
};

#endif
