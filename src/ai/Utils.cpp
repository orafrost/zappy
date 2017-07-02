//
// Utils.cpp for zappy in /home/kerma/Projets/Epitech/PSU/zappy/src/graphic
//
// Made by kerma
// Login   <kerma@epitech.net>
//
// Started on  Wed Jun 28 19:26:29 2017 kerma
// Last update Sun Jul  2 10:40:14 2017 kerma
//

#include "Utils.hpp"

Utils::Utils()
{
  _option["-p"] = &Utils::SetPort;
  _option["-n"] = &Utils::SetName;
  _option["-h"] = &Utils::SetMachine;
}

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
  os << "USAGE: ./zappy_ai -p port -n name -h machine" << std::endl
     << "\tport\tis the port number" << std::endl
     << "\tname\tis the name of the team" << std::endl
     << "\tmachine\tis the name of the machine; localhost by default" << std::endl;
  exit(ret);
}

int	Utils::StringToInt(const std::string &str) const
{
  std::istringstream	iss(str);
  int			nb;

  iss >> nb;
  return nb;
}

void	Utils::SetPort(t_arg *args, const std::string &arg)
{
  if (isNum(arg) == false)
    Usage(std::cerr, ERROR);
  args->port = StringToInt(arg);  
}

void	Utils::SetName(t_arg *args, const std::string &arg) { args->name = arg; }
void	Utils::SetMachine(t_arg *args, const std::string &arg) { args->machine = arg; }

t_arg	Utils::ParsArg(int ac, char **av)
{
  t_arg	args;
  int	i = 1;

  args.port = 4242;
  args.name = "Team1";
  args.machine = "127.0.0.1";
  while (i < ac)
    {
      if (std::string(av[i]) == "-help")
	Usage(std::cout, 0);	
      for (MIT it = _option.begin(); it != _option.end(); ++it) {
	if (it->first == std::string(av[i])) {
	  if (av[++i] == NULL)
	    Usage(std::cerr, ERROR);
	  (this->*(_option[it->first]))(&args, std::string(av[i]));
	}
      }
      i++;
    }
  return args;
}
