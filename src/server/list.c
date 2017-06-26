/*
** list.c for list in /home/orafrost/rendu/tek2/psu/zappy/src/server/
**
** Made by Guillaume Verrier
** Login   <verrier_g@epitech.eu>
**
** Started on  Tue Jun 20 12:24:50 2017 Guillaume Verrier
** Last update Mon Jun 26 15:47:34 2017 kerma
*/

#include "zappy.h"

t_player *create_player(int id, enum e_dir dir)
{
  int      a;
  t_player *player;

  if ((player = malloc(sizeof(t_player))) == NULL)
    return (NULL);
  if ((player->client = malloc(sizeof(t_player))) == NULL)
    return (NULL);
  a = 1;
  player->resources[0] = 10;
  while (a < 7)
  {
    player->resources[a] = 0;
    a += 1;
  }
  player->id = id;
  player->_dir = dir;
  return (player);
}

t_team *create_team_node(t_player *player)
{
  t_team *node;

  if ((node = malloc(sizeof(t_team))) == NULL)
    return (NULL);
  node->player = player;
  node->next = NULL;
  return (node);
}

t_team *add_elem(t_team *start, t_team *node)
{
  node->next = start;
  return (node);
}

void free_team(t_team *node)
{
  free(node->player);
  free(node);
}

t_team *del_elem(t_team *start, t_team *elem)
{
  t_team *temp;

  if (start == NULL)
    return (NULL);
  if (start == elem)
  {
    temp = start->next;
    free_team(start);
    return (temp);
  }
  while (start->next != elem && start->next != NULL)
  {
    start = start->next;
  }
  if (start->next != NULL)
  {
    temp = start->next;
    start->next = start->next->next;
    free_team(temp);
  }
  return (start);
}
