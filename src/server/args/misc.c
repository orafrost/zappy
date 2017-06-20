/*
** misc.c for zappy in /home/kerma/Projets/Epitech/PSU/zappy/src/server/args
**
** Made by kerma
** Login   <kerma@epitech.net>
**
** Started on  Tue Jun 20 16:38:28 2017 kerma
** Last update Tue Jun 20 16:39:11 2017 kerma
*/

#include "zappy.h"

int	is_num(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    {
      if (str[i] < '0' || str[i] > '9')
	return (1);
      i++;
    }
  return (0);
}

void	puterr(char *err)
{
  fprintf(stderr, "%s\n", err);
  exit(ERROR);
}
