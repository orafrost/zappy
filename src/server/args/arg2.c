/*
** arg2.c for zappy in /home/kerma/Projets/Epitech/PSU/zappy/src/server/args
**
** Made by kerma
** Login   <kerma@epitech.net>
**
** Started on  Tue Jun 20 16:46:47 2017 kerma
** Last update Wed Jun 21 00:42:31 2017 kerma
*/

#include "zappy.h"

static t_teamRoot	*init_team(char *name)
{
  t_teamRoot		*team;

  if ((team = malloc(sizeof(t_team))) == NULL)
    puterr("Function 'malloc' failed.");
  team->nb = 0;
  team->max = 0;
  team->name = strdup(name);
  team->players = NULL;
  return (team);
}

void	get_nb_teams(t_zappy *zappy, char **av, int i)
{
  int	nb;

  nb = 0;
  while (av[i] != NULL && av[i][0] != '-')
    {
      nb++;
      i++;
    }
  zappy->nb_teams = nb;
}

void	arg_names(t_zappy *zappy, char **av, int *i, int *nb)
{
  int	j;
  int	k;

  (void)nb;
  j = *i + 1;
  if (av[j] == NULL)
    puterr("Invalid '-n' argument.");
  k = 0;
  get_nb_teams(zappy, av, j);
  if ((zappy->teams = malloc((8 * zappy->nb_teams) + 1)) == NULL)
    puterr("Function 'malloc' failed.");
  while (k < zappy->nb_teams)
    {
      zappy->teams[k++] = init_team(av[j++]);
      *i += 1;
    }
  zappy->teams[k] = NULL;
}
