/*
** args.c for zappy in /home/kerma/Projets/Epitech/PSU/zappy/src/server/args
**
** Made by kerma
** Login   <kerma@epitech.net>
**
** Started on  Tue Jun 20 14:30:23 2017 kerma
** Last update Sat Jun 24 16:58:13 2017 kerma
*/

#include "zappy.h"

static int	arg_pars(t_zappy *zappy, char **av, t_args *args, int *i)
{
  int		k;

  k = 0;
  while (k < 6)
    {
      if (strcmp(av[*i], args->arg[k]) == 0)
	{
	  if (args->func[k](zappy, av, i, &args->nb) == ERROR)
	    return (ERROR);
	  else
	    return (0);
	}
      k++;
    }
  return (puterr("Unknown argument."));
}

int		args(t_zappy *zappy, int ac, char **av)
{
  t_args	args;
  int		i;

  i = 1;
  arg_init(&args);
  if (default_init(zappy) == ERROR)
    return (ERROR);
  while (i < ac)
    {
      if (strcmp(av[i], "-help") == 0)
	usage(zappy);
      else if (arg_pars(zappy, av, &args, &i) == ERROR)
	return (ERROR);
      i++;
    }
  if (args.nb != -1)
    {
      i = 0;
      while (zappy->teams[i] != NULL)
	zappy->teams[i++]->max = args.nb;
    }
  return (0);
}
