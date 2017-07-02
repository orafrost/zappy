//
// Commands.hpp for zappy in /home/kerma/Projets/Epitech/PSU/zappy/src/graphic/include
//
// Made by kerma
// Login   <kerma@epitech.net>
//
// Started on  Wed Jun 28 17:41:22 2017 kerma
// Last update Sun Jul  2 21:48:14 2017 kerma
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
public:
  typedef void (Commands::*CALLBACK)(const std::string &arg);

private:
  int		_count;
  bool		_needResponse;
  AI		*_ai;
  bool		_init;
  Utils		_utils;
  Socket	*_socket;
  std::string	_team;
  CALLBACK	_resp;

private:
  void		HandlerWELCOME();
  void		reset(const std::string &);
  void	        getVision(const std::string &);
  int		IsResponse(const std::string &);

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
  void	        IncCount();
  void		SetTeamName(const std::string &name);
  void		SetSocket(Socket *socket);
  void		SetAI(AI *ai);
  void		CommandParser(const std::string &cmd);
  
public:
  Commands();
  ~Commands();
};

#endif
