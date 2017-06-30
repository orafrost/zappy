//
// Commands.hpp for zappy in /home/kerma/Projets/Epitech/PSU/zappy/src/graphic/include
//
// Made by kerma
// Login   <kerma@epitech.net>
//
// Started on  Wed Jun 28 17:41:22 2017 kerma
// Last update Fri Jun 30 16:31:43 2017 kerma
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

  typedef std::vector<std::string>								ARGS;
  typedef std::map<std::string, bool>								INIT;
  typedef std::map<std::string, void (Commands::*)(const ARGS &)>				CMDS;

  typedef std::vector<Commands::CommandType>							LIST;
  typedef std::map<Commands::CommandType, void (Commands::*)(const ARGS &)>			RESP;

  typedef std::vector<std::string>::const_iterator						VCIT;
  typedef std::map<std::string, void (Commands::*)(const ARGS &)>::const_iterator		MCIT;

  typedef std::vector<Commands::CommandType>::const_iterator					LCIT;
  typedef std::map<Commands::CommandType, void (Commands::*)(const ARGS &)>::const_iterator	RCIT;

private:
  CMDS		_cmd;
  ARGS		_tmp;
  INIT		_init;
  LIST		_list;
  RESP		_resp;
  Utils		_utils;
  Socket	*_socket;
  
private:
  void		Bufferized(const ARGS &arg);
  std::string	ConcatARGS(const ARGS &arg, int i) const;
  void		HandlerWELCOME(const ARGS &arg);

  // void		ResponseWELCOME(const ARGS &arg);
  // void		ResponseFORWARD(const ARGS &arg);
  // void		ResponseRIGHT(const ARGS &arg);
  // void		ResponseLEFT(const ARGS &arg);
  // void		ResponseLOOK(const ARGS &arg);
  // void		ResponseINVENTORY(const ARGS &arg);
  // void		ResponseBROADCAST(const ARGS &arg);
  // void		ResponseCONNECTED(const ARGS &arg);
  // void		ResponseFORK(const ARGS &arg);
  // void		ResponseEJECT(const ARGS &arg);
  // void		ResponseDEATH(const ARGS &arg);
  // void		ResponseINCANTATION(const ARGS &arg);
  
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
  void		SetSocket(Socket *socket);
  void		CommandParser(const std::string &cmd);
  
public:
  Commands();
  ~Commands();
};

#endif
