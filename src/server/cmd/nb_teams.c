/*
** nb_teams.c for zappy in /home/kerma/Projets/Epitech/PSU/zappy/src/server/cmd
**
** Made by kerma
** Login   <kerma@epitech.net>
**
** Started on  Sun Jun 25 17:24:06 2017 kerma
** Last update Tue Jun 27 19:21:03 2017 kerma
*/

#include "zappy.h"

int		nb_teams(t_zappy *zappy, t_player *player)
{
  t_teamRoot	*team;
  char		*msg;
  int		size;

  if (player->action.arg != NULL)
    {
      add_msg(&player->client->out, "ko");
      return (0);
    }
  if ((team = find_team(zappy, player)) == NULL)
    return (puterr("Internal error: can\'t find team in \'nb_teams()\'."));
  size = intlen(team->max);
  if ((msg = malloc(size + 1)) == NULL)
    return (puterr("Function 'malloc' failed."));
  memset(msg, 0, size + 1);
  sprintf(msg, "%d", team->max);
  add_msg(&player->client->out, msg);
  free(msg);
  return (0);
}
