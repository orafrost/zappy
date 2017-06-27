/*
** list.c for list in /home/orafrost/rendu/tek2/psu/zappy/src/server/
**
** Made by Guillaume Verrier
** Login   <verrier_g@epitech.eu>
**
** Started on  Tue Jun 20 12:24:50 2017 Guillaume Verrier
** Last update Tue Jun 27 19:39:41 2017 kerma
*/

#include "zappy.h"

static t_player	*create_player(int fd)
{
  t_player	*player;
  int		a;

  a = 0;
  if ((player = malloc(sizeof(t_player))) == NULL)
    return (pputerr("Function \'malloc\' failed."));
  if ((player->client = init_tcp(player->client, fd, PLAYING)) == NULL)
    return (NULL);
  
  // TODO find default ressources values
  player->resources[a++] = 10;
  while (a < 7)
    player->resources[a++] = 0;

  player->_dir = rand() % 3;
  return (player);
}

t_tcp	*init_tcp(t_tcp *tcp, int fd, e_state state)
{
  if ((tcp = malloc(sizeof(t_tcp))) == NULL)
    return (pputerr("Function \'malloc\' failed."));
  tcp->fd = fd;
  tcp->out = NULL;
  if (state == PLAYING)
    {
      tcp->fct_read = client_read;
      tcp->fct_write = client_write;
    }
  else if (state == WAITING)
    {
      tcp->fct_read = NULL;
      tcp->fct_write = NULL;
    }
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
  if ((*node)->player->client->out != NULL)
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
