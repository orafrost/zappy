//
// Commands.hpp for zappy in /home/kerma/Projets/Epitech/PSU/zappy/src/graphic/include
//
// Made by kerma
// Login   <kerma@epitech.net>
//
// Started on  Wed Jun 28 17:41:22 2017 kerma
// Last update Thu Jun 29 21:37:45 2017 kerma
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

class	Commands
{

  enum	CommandType
    {
      WELCOME		= 0,
      FORWARD		= 1,
      RIGHT		= 2,
      LEFT		= 3,
      LOOK		= 4,
      INVENTORY		= 5,
      BROADCAST		= 6,
      CONNECTED		= 7,
      FORK		= 8,
      EJECT		= 9,
      DEATH		= 10,
      TAKE		= 11,
      SET		= 12,
      INCANTATION	= 13,
    };

  // typedef std::vector<int>								TILE;
  typedef std::vector<std::string>							ARGS;
  typedef std::map<std::string, bool>							INIT;
  typedef std::map<std::string, void (Commands::*)(const ARGS &)>			CMDS;

  typedef std::vector<std::string>::const_iterator					VCIT;
  typedef std::map<std::string, void (Commands::*)(const ARGS &)>::const_iterator	MCIT;  

private:
  CMDS		_cmd;
  ARGS		_tmp;
  INIT		_init;
  Utils		_utils;
  Socket	*_socket;

private:
  void		Bufferized(const ARGS &arg);
  std::string	ConcatARGS(const ARGS &arg, int i) const;
  void		HandlerWELCOME(const ARGS &arg);
  void		HandlerMOVE(const ARGS &arg);
  
public:
  void	        SendFORWARD(const std::string &none)const;
  void		SendRIGHT(const std::string &none) const;
  void		SendLEFT(const std::string &none) const;
  void		SendLOOK(const std::string &none) const;
  void		SendINVENTORY(const std::string &none) const;
  void		SendBROADCAST(const std::string &text) const;
  void		SendCONNECTED(const std::string &none) const;
  void		SendFORK(const std::string &none) const;
  void	        SendEJECT(const std::string &none) const;
  void		SendTAKE(const std::string &object) const;
  void		SendSET(const std::string &object) const;
  void		SendINCANTATION(const std::string &none) const;

public:
  void		SetSocket(Socket *socket);
  void		CommandParser(const std::string &cmd);
  
public:
  Commands();
  ~Commands();
};

#endif
