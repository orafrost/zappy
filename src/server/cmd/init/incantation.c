/*
** incantation.c for zappy in /home/kerma/Projets/Epitech/PSU/zappy/src/server/cmd/init
**
** Made by kerma
** Login   <kerma@epitech.net>
**
** Started on  Fri Jun 30 22:40:39 2017 kerma
** Last update Sun Jul  2 11:53:55 2017 kerma
*/

#include "zappy.h"

int	cmd_incantation(t_zappy *game, t_player *cur)
{
  char	buff[1024];

  if (cur->action.arg != NULL)
    {
      add_msg(&cur->client->out, "ko");
      return (0);
    }
  cur->action.response = res_incantation;
  cur->action.dure = 300 / game->frequency;
  add_msg(&cur->client->out, "Elevation underway");
  memset(buff, 0, 1024);
  sprintf(buff, "pic %d %d", cur->x, cur->y);
  if (game->graphic != NULL)
    add_msg(&game->graphic->out, buff);
  return (0);
}
