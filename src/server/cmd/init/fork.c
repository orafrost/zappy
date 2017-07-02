/*
** fork.c for zappy in /home/kerma/Projets/Epitech/PSU/zappy/src/server/cmd/init
**
** Made by kerma
** Login   <kerma@epitech.net>
**
** Started on  Fri Jun 30 22:40:39 2017 kerma
** Last update Sun Jul  2 02:01:19 2017 kerma
*/

#include "zappy.h"

int	cmd_fork(t_zappy *game, t_player *cur)
{
  if (cur->action.arg != NULL)
    {
      add_msg(&cur->client->out, "ko");
      return (0);
    }
  cur->action.response = res_fork;
  cur->action.dure = 42 / game->frequency;
  return (0);
}
