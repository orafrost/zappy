/*
** inventory.c for zappy in /home/kerma/Projets/Epitech/PSU/zappy/src/server/cmd/init
**
** Made by kerma
** Login   <kerma@epitech.net>
**
** Started on  Fri Jun 30 22:40:39 2017 kerma
** Last update Sat Jul  1 14:20:39 2017 kerma
*/

#include "zappy.h"

int	cmd_inventory(t_zappy *game, t_player *cur)
{
  if (cur->action.arg != NULL)
    {
      add_msg(&cur->client->out, "ko");
      return (0);
    }
  cur->action.response = res_inventory;
  cur->action.dure = 1 / game->frequency;
  return (0);
}
