/*
** utils.c for zappy in /home/kerma/Projets/Epitech/PSU/zappy/src/server
**
** Made by kerma
** Login   <kerma@epitech.net>
**
** Started on  Sun Jun 25 17:40:01 2017 kerma
** Last update Mon Jun 26 15:13:22 2017 kerma
*/

#include "zappy.h"

int	intlen(int nb)
{
  int	i;

  i = 0;
  if (nb == 0)
    return (1);
  if (nb < 0)
    nb = nb * (-1);
  while (nb > 0)
    {
      nb /= 10;
      i++;
    }
  return (i);
}


t_teamRoot	*find_team(t_zappy *zappy, t_player *player)
{
  t_team	*tmp;
  int		i;

  i = 0;
  while (zappy->teams[i] != NULL)
    {
      tmp = zappy->teams[i]->players;
      while (tmp != NULL)
	{
	  if (tmp->player == player)
	    return (zappy->teams[i]);
	  tmp = tmp->next;
	}
      i++;
    }
  return (NULL);
}
