/*
** args.c for zappy in /home/kerma/Projets/Epitech/PSU/zappy/src/server/args
**
** Made by kerma
** Login   <kerma@epitech.net>
**
** Started on  Tue Jun 20 14:30:23 2017 kerma
** Last update Fri Jun 23 16:03:40 2017 kerma
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
	  memset(zappy->map[i][j].resources, 0, 7 * sizeof(int));
	  zappy->map[i][j++].player = NULL;
	}
      i++;
    }
  zappy->map[i] = NULL;
}

void	init_default(t_zappy *zappy)
{  
  zappy->port = 4242;
  zappy->width = 10;
  zappy->height = 10;
  zappy->nb_teams = 4;
  zappy->frequency = 100;
  init_map(zappy);
  if ((zappy->server = malloc(sizeof(t_tcp))) == NULL)
    puterr("Function 'malloc' failed.");
  if ((zappy->teams = malloc(8 * (zappy->nb_teams + 1))) == NULL)
    puterr("Function 'malloc' failed.");
  zappy->teams[0] = init_team("Team1");
  zappy->teams[1] = init_team("Team2");
  zappy->teams[2] = init_team("Team3");
  zappy->teams[3] = init_team("Team4");
  zappy->teams[4] = NULL;
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
	  return ;
	}
      k++;
    }
  puterr("Unknown argument.");
}

void	update_zappy(t_zappy *zappy, int nb)
{
  int	i;

  if (zappy->width != 10 || zappy->height != 10)
    {
      free_map(zappy, 10);
      init_map(zappy);
    }
  if (nb != -1)
    {
      i = 0;
      while (zappy->teams[i] != NULL)
	zappy->teams[i++]->max = nb;
    }
}

void		args(t_zappy *zappy, int ac, char **av)
{
  t_args	args;
  int		i;

  i = 1;
  arg_init(&args);
  init_default(zappy);
  while (i < ac)
    {
      if (strcmp(av[i], "-help") == 0)
	usage();
      else
	arg_pars(zappy, av, &args, &i);
      i++;
    }
  update_zappy(zappy, args.nb);
}
