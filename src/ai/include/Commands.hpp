//
// Commands.hpp for zappy in /home/kerma/Projets/Epitech/PSU/zappy/src/graphic/include
//
// Made by kerma
// Login   <kerma@epitech.net>
//
// Started on  Wed Jun 28 17:41:22 2017 kerma
// Last update Sun Jul  2 20:56:31 2017 kerma
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
private:
  bool		_needResponse;
  AI		*_ai;
  bool		_init;
  Utils		_utils;
  Socket	*_socket;
  std::string	_team;

private:
  void		HandlerWELCOME();
  
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
  void		SetTeamName(const std::string &name);
  void		SetSocket(Socket *socket);
  void		SetAI(AI *ai);
  void		CommandParser(const std::string &cmd);
  
public:
  Commands();
  ~Commands();
};

#endif
