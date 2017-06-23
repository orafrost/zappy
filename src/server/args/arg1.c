/*
** arg1.c for zappy in /home/kerma/Projets/Epitech/PSU/zappy/src/server/args
**
** Made by kerma
** Login   <kerma@epitech.net>
**
** Started on  Tue Jun 20 16:43:48 2017 kerma
** Last update Fri Jun 23 15:58:22 2017 kerma
*/

#include "zappy.h"

void	arg_port(t_zappy *zappy, char **av, int *i, int *nb)
{
  int	j;

  (void)nb;
  j = *i + 1;
  if (av[j] == NULL || is_num(av[j]) == 1)
    puterr("Invalid '-p' argument.");
  zappy->port = atoi(av[j]);
  *i += 1;
}

void	arg_width(t_zappy *zappy, char **av, int *i, int *nb)
{
  int	j;

  (void)nb;
  j = *i + 1;
  if (av[j] == NULL || is_num(av[j]) == 1)
    puterr("Invalid '-x' argument.");
  zappy->width = atoi(av[j]);
  if (zappy->width < 10 || zappy->width > 30)
    puterr("Invalid '-x' argument: must be between 10 and 30'.");
  *i += 1;
}

void	arg_height(t_zappy *zappy, char **av, int *i, int *nb)
{
  int	j;

  (void)nb;
  j = *i + 1;
  if (av[j] == NULL || is_num(av[j]) == 1)
    puterr("Invalid '-y' argument.");
  zappy->height = atoi(av[j]);
  if (zappy->height < 10 || zappy->height > 30)
    puterr("Invalid '-y' argument: must be between 10 and 30'.");
  *i += 1;
}

void	arg_clients(t_zappy *zappy, char **av, int *i, int *nb)
{
  int	j;

  j = *i + 1;
  (void)zappy;
  if (av[j] == NULL || is_num(av[j]) == 1)
    puterr("Invalid '-c' argument.");
  if ((*nb = atoi(av[j])) == 0)
    puterr("Invalid '-c' argument: must be greater than 0.");
  *i += 1;
}

void	arg_freq(t_zappy *zappy, char **av, int *i, int *nb)
{
  int	j;

  (void)nb;
  j = *i + 1;
  if (av[j] == NULL || is_num(av[j]) == 1)
    puterr("Invalid '-f' argument.");
  zappy->frequency = atoi(av[j]);
  if (zappy->frequency < 2 || zappy->frequency > 10000)
    puterr("Invalid '-f' argument: must be between 2 and 10000'.");
  *i += 1;
}
