/*
** arg1.c for zappy in /home/kerma/Projets/Epitech/PSU/zappy/src/server/args
**
** Made by kerma
** Login   <kerma@epitech.net>
**
** Started on  Tue Jun 20 16:43:48 2017 kerma
** Last update Mon Jun 26 19:58:02 2017 kerma
*/

#include "zappy.h"

int	arg_port(t_zappy *zappy, char **av, int *i, int *nb)
{
  int	j;

  (void)nb;
  j = *i + 1;
  if (av[j] == NULL || is_num(av[j]) == 1)
    return (puterr("Invalid \'-p\' argument."));
  zappy->port = atoi(av[j]);
  *i += 1;
  return (0);
}

int	arg_width(t_zappy *zappy, char **av, int *i, int *nb)
{
  int	width;
  int	j;

  (void)nb;
  j = *i + 1;
  if (av[j] == NULL || is_num(av[j]) == 1)
    return (puterr("Invalid \'-x\' argument."));
  width = atoi(av[j]);
  if (width < 10 || width > 30)
    return (puterr("Invalid \'-x\' argument: must be between 10 and 30'."));
  free_map(zappy);
  zappy->width = width;
  if (map_init(zappy) == ERROR)
    return (ERROR);
  *i += 1;
  return (0);
}

int	arg_height(t_zappy *zappy, char **av, int *i, int *nb)
{
  int	height;
  int	j;

  (void)nb;
  j = *i + 1;
  if (av[j] == NULL || is_num(av[j]) == 1)
    return (puterr("Invalid \'-y\' argument."));
  height = atoi(av[j]);
  if (height < 10 || height > 30)
    return (puterr("Invalid \'-y\' argument: must be between 10 and 30'."));
  free_map(zappy);
  zappy->height = height;
  if (map_init(zappy) == ERROR)
    return (ERROR);
  *i += 1;
  return (0);
}

int	arg_clients(t_zappy *zappy, char **av, int *i, int *nb)
{
  int	j;

  (void)zappy;
  j = *i + 1;
  if (av[j] == NULL || is_num(av[j]) == 1)
    return (puterr("Invalid \'-c\' argument."));
  if ((*nb = atoi(av[j])) == 0)
    return (puterr("Invalid \'-c\' argument: must be greater than 0."));
  *i += 1;
  return (0);
}

int	arg_freq(t_zappy *zappy, char **av, int *i, int *nb)
{
  int	j;

  (void)nb;
  j = *i + 1;
  if (av[j] == NULL || is_num(av[j]) == 1)
    return (puterr("Invalid \'-f\' argument."));
  zappy->frequency = atoi(av[j]);
  if (zappy->frequency < 2 || zappy->frequency > 10000)
    return (puterr("Invalid \'-f\' argument: must be between 2 and 10000'."));
  *i += 1;
  return (0);
}
