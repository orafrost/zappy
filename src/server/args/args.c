/*
** args.c for zappy in /home/kerma/Projets/Epitech/PSU/zappy/src/server/args
**
** Made by kerma
** Login   <kerma@epitech.net>
**
** Started on  Tue Jun 20 14:30:23 2017 kerma
** Last update Wed Jun 21 13:17:55 2017 kerma
*/

#include "zappy.h"

void		init_map(t_zappy *zappy)
{
  size_t	i;
  size_t	j;

  i = 0;
  if ((zappy->map = malloc(8 * (zappy->height + 1))) == NULL)
    puterr("Function 'malloc' failed.");
  while (i < zappy->height)
    {
      j = 0;
      if ((zappy->map[i] = malloc(sizeof(t_tile) * zappy->width)) == NULL)
	puterr("Function 'malloc' failed.");
      while (j < zappy->width)
	{
	  memset(zappy->map[i][j].resources, 0, 7);
	  zappy->map[i][j++].player = NULL;
	}
      i++;
    }
  zappy->map[i] = NULL;
}

void	arg_pars(t_zappy *zappy, char **av, t_args *args, int *i)
{
  int	k;

  k = 0;
  while (k < 6)
    {
      if (strcmp(av[*i], args->arg[k]) == 0)
	{
	  args->func[k](zappy, av, i, &args->nb);
	  args->done[k] = 1;
	  return ;
	}
      k++;
    }
  puterr("Unknown argument.");
}

void		args(t_zappy *zappy, int ac, char **av)
{
  t_args	args;
  int		i;

  i = 1;
  arg_init(&args);
  zappy->map = NULL;
  zappy->teams = NULL;
  zappy->server = NULL;
  if (ac < 2)
    usage(stderr, ERROR);
  while (i < ac)
    {
      if (strcmp(av[i], "-help") == 0)
	usage(stdin, 0);
      else
	arg_pars(zappy, av, &args, &i);
      i++;
    }
  if (is_set(args) == 1)
    puterr("Missing argument.");
  init_map(zappy);
}
