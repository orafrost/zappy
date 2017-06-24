/*
** arg2.c for zappy in /home/kerma/Projets/Epitech/PSU/zappy/src/server/args
**
** Made by kerma
** Login   <kerma@epitech.net>
**
** Started on  Tue Jun 20 16:46:47 2017 kerma
** Last update Sat Jun 24 16:37:12 2017 kerma
*/

#include "zappy.h"

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

int	arg_names(t_zappy *zappy, char **av, int *i, int *nb)
{
  int	j;
  int	k;

  (void)nb;
  k = 0;
  j = *i + 1;
  if (av[j] == NULL)
    return (puterr("Invalid '-n' argument."));
  free_teams(zappy);
  get_nb_teams(zappy, av, j);
  if ((zappy->teams = malloc(8 * (zappy->nb_teams + 1))) == NULL)
    return (puterr("Function 'malloc' failed."));
  while (k < zappy->nb_teams)
    {
      if ((zappy->teams[k++] = team_init(av[j++])) == NULL)
	return (ERROR);
      *i += 1;
    }
  zappy->teams[k] = NULL;
  return (0);
}
