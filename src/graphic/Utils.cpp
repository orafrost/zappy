//
// Utils.cpp for zappy in /home/kerma/Projets/Epitech/PSU/zappy/src/graphic
//
// Made by kerma
// Login   <kerma@epitech.net>
//
// Started on  Wed Jun 28 19:26:29 2017 kerma
// Last update Sun Jul  2 16:53:44 2017 kerma
//

#include "Utils.hpp"

Utils::Utils() {}
Utils::~Utils() {}

bool	Utils::isNum(const std::string &str) const
{
  for (SIT it = str.begin(); it != str.end(); ++it) {
    if (*it < '0' || *it > '9')
      return (false);
  }
  return (true);
}

void	Utils::Usage(std::ostream &os, int ret) const
{
  os << "USAGE: ./zappy_graphic port" << std::endl;
  exit(ret);
}

int	Utils::StringToInt(const std::string &str) const
{
  std::istringstream	iss(str);
  int			nb;

  iss >> nb;
  return nb;
}

int	Utils::ParsArg(int ac, char **av)
{
  int	port;

  port = 4242;
  if (ac == 2)
    {
      std::string arg(av[1]);

      if (arg == "-h" || arg == "-help" || arg == "--help")
	Usage(std::cout, 0);
      if (isNum(arg) == false)
	Usage(std::cerr, ERROR);
      port = StringToInt(arg);
    }
  if (ac > 2)
    Usage(std::cerr, ERROR);
  return port;
}

Utils::TAB	Utils::Split(const std::string &str)
{
  TAB		tab;
  SIT		it;
  SIT		c;
  std::string	chunk;
  

  for (it = str.begin(); it != str.end(); ++it) {
    for (c = it; *c != '\n' && c != str.end(); ++c)
      chunk += *c;
    tab.push_back(chunk);
    chunk.clear();
    if ((it = c) == str.end())
      return tab;
  }
  return tab;
}
