/*
** incantation.c for zappy in /home/kerma/Projets/Epitech/PSU/zappy/src/server/cmd/init
**
** Made by kerma
** Login   <kerma@epitech.net>
**
** Started on  Fri Jun 30 22:40:39 2017 kerma
** Last update Sun Jul  2 05:49:58 2017 kerma
*/

#include "zappy.h"

int	cmd_incantation(t_zappy *game, t_player *cur)
{
  if (cur->action.arg != NULL)
    {
      add_msg(&cur->client->out, "ko");
      return (0);
    }
  cur->action.response = res_incantation;
  cur->action.dure = 300 / game->frequency;
  add_msg(&cur->client->out, "Elevation underway");
  return (0);
}
