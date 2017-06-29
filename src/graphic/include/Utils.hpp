//
// Utils.hpp for zappy in /home/kerma/Projets/Epitech/PSU/zappy/src/graphic/include
//
// Made by kerma
// Login   <kerma@epitech.net>
//
// Started on  Wed Jun 28 19:25:39 2017 kerma
// Last update Wed Jun 28 19:58:31 2017 kerma
//

#ifndef UTILS_HPP_
# define UTILS_HPP_

# include <iterator>
# include <iostream>
# include <sstream>
# include <string>

# define ERROR	(84)

class	Utils
{
  typedef std::string::const_iterator	SIT;

private:
  bool	isNum(const std::string &str) const;
  void	Usage(std::ostream &os, int ret) const;
  int	StringToInt(const std::string &str) const;

public:
  int	ParsArg(int ac, char **av);

public:
  Utils();
  ~Utils();
};

#endif
