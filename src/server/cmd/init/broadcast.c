/*
** broadcast.c for zappy in /home/kerma/Projets/Epitech/PSU/zappy/src/server/cmd/init
**
** Made by kerma
** Login   <kerma@epitech.net>
**
** Started on  Fri Jun 30 22:40:39 2017 kerma
** Last update Sat Jul  1 16:50:02 2017 kerma
*/

#include "zappy.h"

int	cmd_broadcast(t_zappy *game, t_player *cur)
{
  if (cur->action.arg == NULL)
    {
      add_msg(&cur->client->out, "ko");
      return (0);
    }
  if ((cur->action.arg = strdup(cur->action.arg)) == NULL)
    return (puterr("Function \'strdup\' failed."));
  cur->action.response = res_broadcast;
  cur->action.dure = 7 / game->frequency;
  return (0);
}
