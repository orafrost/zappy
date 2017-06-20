/*
** arg1.c for zappy in /home/kerma/Projets/Epitech/PSU/zappy/src/server/args
**
** Made by kerma
** Login   <kerma@epitech.net>
**
** Started on  Tue Jun 20 16:43:48 2017 kerma
** Last update Wed Jun 21 00:13:37 2017 kerma
*/

#include "zappy.h"

void	arg_port(t_zappy *zappy, char **av, int *i, int *nb)
{
  int	j;
  
  (void)nb;
  j = *i + 1;
  if (av[j] == NULL || is_num(av[j]) == 1)
    puterr("Invalid '-p' argument.");
  if ((zappy->server = malloc(sizeof(t_tcp))) == NULL)
    puterr("Function 'malloc' failed.");
  zappy->server->port = atoi(av[j]);
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
  *i += 1;
}

void	arg_clients(t_zappy *zappy, char **av, int *i, int *nb)
{
  int	k;
  int	j;

  j = *i + 1;
  if (av[j] == NULL || is_num(av[j]) == 1)
    puterr("Invalid '-y' argument.");
  if (zappy->teams == NULL)
    *nb = atoi(av[j]);
  else
    {
      k = 0;
      while (zappy->teams[k] != NULL)
	zappy->teams[k++]->max = atoi(av[j]);
    }
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
  *i += 1;
}
