//
// Commands.hpp for zappy in /home/kerma/Projets/Epitech/PSU/zappy/src/graphic/include
//
// Made by kerma
// Login   <kerma@epitech.net>
//
// Started on  Wed Jun 28 17:41:22 2017 kerma
// Last update Sun Jul  2 13:01:22 2017 kerma
//

#ifndef COMMANDS_HPP_
# define COMMANDS_HPP_

# include <iostream>
# include <sstream>
# include <iterator>
# include <vector>
# include <map>

# include "Utils.hpp"
# include "Socket.hpp"
class	Socket;

# include "AI.hpp"
class	AI;

class	Commands
{

  typedef std::vector<std::string>								ARGS;
  typedef std::map<std::string, bool>								INIT;
  typedef std::map<std::string, void (Commands::*)(const ARGS &)>				CMDS;

  typedef std::vector<std::string>::const_iterator						VCIT;
  typedef std::map<std::string, void (Commands::*)(const ARGS &)>::const_iterator		MCIT;

private:
  AI		*_ai;
  CMDS		_cmd;
  ARGS		_tmp;
  INIT		_init;
  Utils		_utils;
  Socket	*_socket;
  std::string	_team;

private:
  void		Bufferized(const ARGS &arg);
  std::string	ConcatARGS(const ARGS &arg, int i) const;
  void		HandlerWELCOME(const ARGS &arg);
  
public:
  void	        SendFORWARD()const;
  void		SendRIGHT() const;
  void		SendLEFT() const;
  void		SendLOOK() const;
  void		SendINVENTORY() const;
  void		SendCONNECTED() const;
  void		SendFORK() const;
  void	        SendEJECT() const;
  void		SendBROADCAST(const std::string &text) const;
  void		SendTAKE(const std::string &object) const;
  void		SendSET(const std::string &object) const;
  void		SendINCANTATION() const;

public:
  void		SetTeamName(const std::string &name);
  void		SetSocket(Socket *socket);
  void		CommandParser(const std::string &cmd);
  
public:
  Commands();
  ~Commands();
};

#endif
