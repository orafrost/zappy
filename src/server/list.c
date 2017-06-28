/*
** list.c for list in /home/orafrost/rendu/tek2/psu/zappy/src/server/
**
** Made by Guillaume Verrier
** Login   <verrier_g@epitech.eu>
**
** Started on  Tue Jun 20 12:24:50 2017 Guillaume Verrier
** Last update Wed Jun 28 15:20:16 2017 kerma
*/

#include "zappy.h"

static t_player	*create_player(int fd)
{
  t_player	*player;
  int		i;

  i = 0;
  if ((player = malloc(sizeof(t_player))) == NULL)
    return (pputerr("Function \'malloc\' failed."));
  if ((player->client = init_tcp(player->client, fd)) == NULL)
    return (NULL);  
  player->resources[i++] = 10;
  while (i < 7)
    player->resources[i++] = 0;
  player->_dir = rand() % 3;
  return (player);
}

t_tcp	*init_tcp(t_tcp *tcp, int fd)
{
  if ((tcp = malloc(sizeof(t_tcp))) == NULL)
    return (pputerr("Function \'malloc\' failed."));
  tcp->fd = fd;
  tcp->init = 0;
  tcp->out = NULL;
  return (tcp);
}

t_team		*add_player(t_team **team, int fd)
{
  t_team	*tmp;
  t_team	*new;

  if ((new = malloc(sizeof(t_team))) == NULL)
    return (NULL);
  if ((new->player = create_player(fd)) == NULL)
    return (NULL);
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
  return (new);
}

void	free_team(t_team **node)
{
  free_buffer((*node)->player->client->out);
  free((*node)->player->client);
  free((*node)->player);
  free(*node);
  *node = NULL;
}

t_team		*del_elem(t_team *start, t_team **elem)
{
  t_team	*temp;

  if (start == NULL)
    return (NULL);
  if (start == *elem)
    {
      start = start->next;
      free_team(elem);
      return (start);
    }
  temp = start;
  while (temp->next != *elem && temp->next != NULL)
    temp = temp->next;
  if (temp->next != NULL)
    {
      temp->next = temp->next->next;
      free_team(elem);
    }
  return (start);
}

