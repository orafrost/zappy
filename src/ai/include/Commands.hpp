//
// Commands.hpp for zappy in /home/kerma/Projets/Epitech/PSU/zappy/src/graphic/include
//
// Made by kerma
// Login   <kerma@epitech.net>
//
// Started on  Wed Jun 28 17:41:22 2017 kerma
// Last update Sun Jul  2 15:14:24 2017 kerma
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
  typedef std::vector<std::string>							ARGS;
  typedef void (Commands::*CALLBACK)(const ARGS &);
  typedef std::map<std::string, bool>							INIT;
  typedef std::map<std::string, void (Commands::*)(const ARGS &)>			CMDS;

  typedef std::vector<std::string>::const_iterator					VCIT;
  typedef std::map<std::string, void (Commands::*)(const ARGS &)>::const_iterator	MCIT;

private:
  bool		_needResponse;
  AI		*_ai;
  CMDS		_cmd;
  ARGS		_tmp;
  INIT		_init;
  Utils		_utils;
  Socket	*_socket;
  CALLBACK	_callback;
  std::string	_team;

private:
  void		Bufferized(const ARGS &arg);
  std::string	ConcatARGS(const ARGS &arg, int i) const;
  void		HandlerWELCOME(const ARGS &arg);
  
public:
  void	        SendFORWARD();
  void		SendRIGHT() ;
  void		SendLEFT() ;
  void		SendLOOK() ;
  void		SendINVENTORY() ;
  void		SendCONNECTED() ;
  void		SendFORK() ;
  void	        SendEJECT() ;
  void		SendBROADCAST(const std::string &text) ;
  void		SendTAKE(const std::string &object) ;
  void		SendSET(const std::string &object) ;
  void		SendINCANTATION() ;

public:
  void		SetCallback(CALLBACK callback);
  void		SetTeamName(const std::string &name);
  void		SetSocket(Socket *socket);
  void		SetAI(AI *ai);
  void		CommandParser(const std::string &cmd);
  
public:
  Commands();
  ~Commands();
};

#endif
