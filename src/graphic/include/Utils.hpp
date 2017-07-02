//
// Utils.hpp for zappy in /home/kerma/Projets/Epitech/PSU/zappy/src/graphic/include
//
// Made by kerma
// Login   <kerma@epitech.net>
//
// Started on  Wed Jun 28 19:25:39 2017 kerma
// Last update Sun Jul  2 17:20:00 2017 kerma
//

#ifndef UTILS_HPP_
# define UTILS_HPP_

# include <iterator>
# include <iostream>
# include <sstream>
# include <string>
# include <vector>

# define ERROR	(84)

class	Utils
{
public:
  typedef std::vector<std::string>		TAB;
  typedef std::vector<std::string>::iterator	TIT;
  typedef std::string::const_iterator		SIT;

private:
  void	Usage(std::ostream &os, int ret) const;

public:
  bool	isNum(const std::string &str) const;
  int	StringToInt(const std::string &str) const;
  int	ParsArg(int ac, char **av);
  TAB	Split(const std::string &str);
    
public:
  Utils();
  ~Utils();
};

#endif
