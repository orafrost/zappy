/*
** take.c for zappy in /home/kerma/Projets/Epitech/PSU/zappy/src/server/cmd
**
** Made by kerma
** Login   <kerma@epitech.net>
**
** Started on  Fri Jun 30 21:56:06 2017 kerma
** Last update Sun Jul  2 03:59:46 2017 kerma
*/

#include "zappy.h"

int	res_take(t_zappy *game, t_player *cur)
{
  int	resource;
  char	buff[1024];

  memset(buff, 0, 1024);
  if (cur->action.arg == NULL ||
      (resource = find_resource(cur->action.arg)) == WRONG_RESOURCE ||
      game->map[cur->y][cur->x].resources[resource] == 0)
    {
      add_msg(&cur->client->out, "ko");
      return (0);
    }
  game->map[cur->y][cur->x].resources[resource]--;
  cur->resources[resource]++;
  sprintf(buff, "pgt %d %d", cur->id, resource);
  if (game->graphic != NULL)
    add_msg(&game->graphic->out, buff);
  add_msg(&cur->client->out, "ok");
  free(cur->action.arg);
  return (0);
}
