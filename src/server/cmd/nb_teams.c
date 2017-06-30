/*
** nb_teams.c for zappy in /home/kerma/Projets/Epitech/PSU/zappy/src/server/cmd
**
** Made by kerma
** Login   <kerma@epitech.net>
**
** Started on  Sun Jun 25 17:24:06 2017 kerma
** Last update Fri Jun 30 18:22:40 2017 kerma
*/

#include "zappy.h"

int		nb_teams(t_zappy *zappy, t_player *player)
{
  t_teamRoot	*team;
  char		msg[4];

  if (player->action.arg != NULL ||
      (team = find_team(zappy, player)) == NULL)
    {
      add_msg(&player->client->out, "ko");
      return (0);
    }
  memset(msg, 0, 4);
  sprintf(msg, "%d", team->max - team->nb);
  add_msg(&player->client->out, msg);
  return (0);
}
