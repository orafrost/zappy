/*
** arg2.c for zappy in /home/kerma/Projets/Epitech/PSU/zappy/src/server/args
**
** Made by kerma
** Login   <kerma@epitech.net>
**
** Started on  Tue Jun 20 16:46:47 2017 kerma
** Last update Sun Jul  2 05:47:42 2017 kerma
*/

#include "zappy.h"

static int	is_validname(char **av, int start, int current)
{
  while (start != current)
    {
      if (strcmp(av[start], av[current]) == 0)
	return (1);
      start++;
    }
  return (0);
}

static int	get_nb_teams(char **av, int i)
{
  int		nb;

  nb = 0;
  while (av[i] != NULL && av[i][0] != '-')
    {
      nb++;
      i++;
    }
  return (nb);
}

static int	stock_names(t_zappy *zappy, char **av, int *i)
{
  int		len;
  int		ref;
  int		k;

  k = 0;
  ref = *i + 1;
  len = get_nb_teams(av, ref);
  while (k < len)
    {
      if (strcmp(av[*i + 1], "GRAPHIC") == 0)
	return (puterr("Team name \'GRAPHIC\' is reserved."));
      if (is_validname(av, ref, *i + 1) == 1)
	return (puterr("Team names must be unique."));
      if ((zappy->teams[k++] = team_init(av[*i + 1])) == NULL)
	return (ERROR);
      zappy->nb_teams++;
      *i += 1;
    }
  zappy->teams[k] = NULL;
  return (0);
}

int	arg_names(t_zappy *zappy, char **av, int *i, int *nb)
{
  int	len;
  int	j;

  (void)nb;
  j = *i + 1;
  if (av[j] == NULL)
    return (puterr("Invalid \'-n\' argument."));
  free_teams(zappy);
  len = get_nb_teams(av, j);
  if ((zappy->teams = malloc(8 * (len + 1))) == NULL)
    return (puterr("Function \'malloc\' failed."));
  if (stock_names(zappy, av, i) == ERROR)
    {
      free_teams(zappy);
      return (ERROR);
    }
  return (0);
}
