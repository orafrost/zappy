/*
** init.c for zappy in /home/kerma/Projets/Epitech/PSU/zappy/src/server/args
**
** Made by kerma
** Login   <kerma@epitech.net>
**
** Started on  Sat Jun 24 16:17:37 2017 kerma
** Last update Fri Jun 30 19:38:24 2017 kerma
*/

#include "zappy.h"

void	arg_init(t_args *args)
{
  args->nb = -1;
  args->arg[0] = "-p";
  args->arg[1] = "-x";
  args->arg[2] = "-y";
  args->arg[3] = "-n";
  args->arg[4] = "-c";
  args->arg[5] = "-f";
  args->func[0] = &arg_port;
  args->func[1] = &arg_width;
  args->func[2] = &arg_height;
  args->func[3] = &arg_names;
  args->func[4] = &arg_clients;
  args->func[5] = &arg_freq;
}

void	waiting_init(t_zappy *zappy)
{
  int	i;

  i = 0;
  while (i < MAX)
    zappy->waiting[i++] = NULL;
}

int     default_init(t_zappy *zappy)
{
  zappy->port = 4242;
  zappy->width = 10;
  zappy->height = 10;
  zappy->nb_teams = 4;
  zappy->frequency = 100;
  if (map_init(zappy) == ERROR)
    return (ERROR);
  if ((zappy->server = malloc(sizeof(t_tcp))) == NULL)
    return (puterr("Function \'malloc\' failed."));
  if ((zappy->teams = malloc(8 * (zappy->nb_teams + 1))) == NULL)
    return (puterr("Function \'malloc\' failed."));
  if ((zappy->teams[0] = team_init("Team1")) == NULL)
    return (ERROR);
  if ((zappy->teams[1] = team_init("Team2")) == NULL)
    return (ERROR);
  if ((zappy->teams[2] = team_init("Team3")) == NULL)
    return (ERROR);
  if ((zappy->teams[3] = team_init("Team4")) == NULL)
    return (ERROR);
  zappy->teams[4] = NULL;
  zappy->graphic = NULL;
  waiting_init(zappy);
  return (0);
}

int		map_init(t_zappy *zappy)
{
  size_t	i;
  size_t	j;
  int		k;

  i = 0;
  if ((zappy->map = malloc(8 * (zappy->height + 1))) == NULL)
    return (puterr("Function \'malloc\' failed."));
  while (i < zappy->height)
    {
      j = 0;
      if ((zappy->map[i] = malloc(sizeof(t_tile) * zappy->width)) == NULL)
	return (puterr("Function \'malloc\' failed."));
      while (j < zappy->width)
	{
	  k = 0;
	  while (k < 7)
	    zappy->map[i][j].resources[k++] = rand() % 9;
	  zappy->map[i][j++].player = NULL;
	}
      i++;
    }
  zappy->map[i] = NULL;
  return (0);
}

t_teamRoot	*team_init(char *name)
{
  t_teamRoot	*team;

  if ((team = malloc(sizeof(t_teamRoot))) == NULL)
    return (pputerr("Function \'malloc\' failed."));
  team->nb = 0;
  team->max = 3;
  team->players = NULL;
  if ((team->name = strdup(name)) == NULL)
    return (pputerr("Function \'strdup\' failed."));
  return (team);
}
