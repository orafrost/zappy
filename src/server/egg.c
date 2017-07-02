/*
** egg.c for list in /home/orafrost/rendu/tek2/psu/zappy/src/server/
**
** Made by Guillaume Verrier
** Login   <verrier_g@epitech.eu>
**
** Started on  Tue Jun 20 12:24:50 2017 Guillaume Verrier
** Last update Sun Jul  2 04:14:34 2017 kerma
*/

#include "zappy.h"

t_egg		*add_egg(t_egg **eggs, char *team, int y, int x)
{
  static int	id = 0;
  t_egg		*tmp;
  t_egg		*new;

  if ((new = malloc(sizeof(t_egg))) == NULL)
    return (pputerr("Function \'malloc\' failed."));
  if ((new->team = strdup(team)) == NULL)
    return (pputerr("Function \'strdup\' failed."));
  new->start = time(NULL);
  new->id = id++;
  new->y = y;
  new->x = x;
  new->next = NULL;
  if (*eggs == NULL)
    *eggs = new;
  else
    {
      tmp = *eggs;
      while (tmp->next != NULL)
	tmp = tmp->next;
      tmp->next = new;
    }
  return (new);
}

void	free_egg(t_egg **node)
{
  free((*node)->team);
  free(*node);
  *node = NULL;
}

t_egg	*del_egg(t_egg *start, t_egg **elem)
{
  t_egg	*temp;

  if (start == NULL)
    return (NULL);
  if (start == *elem)
    {
      start = start->next;
      free_egg(elem);
      return (start);
    }
  temp = start;
  while (temp->next != *elem && temp->next != NULL)
    temp = temp->next;
  if (temp->next != NULL)
    {
      temp->next = temp->next->next;
      free_egg(elem);
    }
  return (start);
}

void	use_egg(t_zappy *zappy, t_team **new, int team_id)
{
  t_egg	*tmp;

  tmp = zappy->eggs;
  while (tmp != NULL)
    {
      if (strcmp(tmp->team, zappy->teams[team_id]->name) == 0 &&
	  tmp->start == 0)
	{
	  zappy->teams[team_id]->max--;
	  (*new)->player->x = tmp->x;
	  (*new)->player->y = tmp->y;
	  zappy->eggs = del_egg(zappy->eggs, &tmp);
	  return ;
	}
      tmp = tmp->next;
    }
}
