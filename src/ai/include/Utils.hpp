//
// Utils.hpp for zappy in /home/kerma/Projets/Epitech/PSU/zappy/src/graphic/include
//
// Made by kerma
// Login   <kerma@epitech.net>
//
// Started on  Wed Jun 28 19:25:39 2017 kerma
// Last update Sun Jul  2 20:46:40 2017 kerma
//

#ifndef UTILS_HPP_
# define UTILS_HPP_

# include <iterator>
# include <iostream>
# include <sstream>
# include <string>
# include <vector>
# include <map>

# define ERROR	(84)

typedef struct	s_arg
{
  int		port;
  std::string	name;
  std::string	machine;
}		t_arg;

class	Utils
{
public:
  typedef std::vector<std::string>								TAB;
  typedef std::vector<std::string>::iterator							TIT;
  typedef std::map<std::string, void (Utils::*)(t_arg *args, const std::string &arg)>		OPT;
  typedef std::map<std::string, void (Utils::*)(t_arg *args, const std::string &arg)>::iterator	MIT;
  typedef std::string::const_iterator								SIT;

private:
  OPT		_option;

private:
  void	Usage(std::ostream &os, int ret) const;
  void	SetPort(t_arg *args, const std::string &arg);
  void	SetName(t_arg *args, const std::string &arg);
  void	SetMachine(t_arg *args, const std::string &arg);
  
public:
  bool		isNum(const std::string &str) const;
  int		StringToInt(const std::string &str) const;
  t_arg		ParsArg(int ac, char **av);
  TAB		Split(const std::string &str);
  
public:
  Utils();
  ~Utils();
};

#endif
