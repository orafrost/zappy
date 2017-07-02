/*
** connect_nbr.c for zappy in /home/kerma/Projets/Epitech/PSU/zappy/src/server/cmd/init
**
** Made by kerma
** Login   <kerma@epitech.net>
**
** Started on  Sun Jun 25 17:24:06 2017 kerma
** Last update Sun Jul  2 06:04:14 2017 kerma
*/

#include "zappy.h"

int		cmd_connect_nbr(t_zappy *game, t_player *cur)
{
  t_teamRoot	*team;
  char		msg[1024];

  if (cur->action.arg != NULL ||
      (team = find_team(game, cur)) == NULL)
    {
      add_msg(&cur->client->out, "ko");
      return (0);
    }
  memset(msg, 0, 1024);
  sprintf(msg, "%d", team->max - team->nb);
  add_msg(&cur->client->out, msg);
  cur->action.start = 0;
  return (0);
}
