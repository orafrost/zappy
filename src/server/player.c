/*
** player.c for zappy in /home/kerma/Projets/Epitech/PSU/zappy/src/server
**
** Made by kerma
** Login   <kerma@epitech.net>
**
** Started on  Fri Jun 30 23:25:54 2017 kerma
** Last update Sun Jul  2 19:31:03 2017 kerma
*/

#include "zappy.h"

int		add_player(t_team **team, t_player *player)
{
  t_team	*tmp;
  t_team	*new;

  if ((new = malloc(sizeof(t_team))) == NULL)
    return (ERROR);
  new->player = player;
  new->next = NULL;
  if (*team == NULL)
    *team = new;
  else
    {
      tmp = *team;
      while (tmp->next != NULL)
	tmp = tmp->next;
      tmp->next = new;
    }
  return (0);
}

void		free_player(t_team *start, t_player **node)
{
  t_team	*tmp;

  tmp = start;
  while (tmp->player != *node)
    tmp = tmp->next;
  free(tmp);
  tmp = NULL;
}

t_team		*del_player(t_team *start, t_player **elem)
{
  t_team	*temp;
  t_team	*temp2;

  if (start == NULL)
    return (NULL);
  if (start->player == *elem)
    {
      temp = start;
      start = start->next;
      free_player(temp, elem);
      return (start);
    }
  temp = start;
  while (temp->next->player != *elem && temp->next != NULL)
    temp = temp->next;
  if (temp->next != NULL)
    {
      temp2 = temp->next;
      temp->next = temp->next->next;
      free_player(temp2, elem);
    }
  return (start);
}
