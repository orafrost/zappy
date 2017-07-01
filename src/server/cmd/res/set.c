/*
** set.c for zappy in /home/kerma/Projets/Epitech/PSU/zappy/src/server/cmd
**
** Made by kerma
** Login   <kerma@epitech.net>
**
** Started on  Fri Jun 30 21:56:06 2017 kerma
** Last update Sat Jul  1 15:03:56 2017 kerma
*/

#include "zappy.h"

int	res_set(t_zappy *game, t_player *cur)
{
  int	resource;
  
  if (cur->action.arg == NULL ||
      (resource = find_resource(cur->action.arg)) == WRONG_RESOURCE ||
      cur->resources[resource] == 0)
    {
      add_msg(&cur->client->out, "ko");
      return (0);
    }
  game->map[cur->y][cur->x].resources[resource]++;
  cur->resources[resource]--;
  add_msg(&cur->client->out, "ok");
  free(cur->action.arg);
  return (0);
}
