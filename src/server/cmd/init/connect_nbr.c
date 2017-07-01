/*
** connect_nbr.c for zappy in /home/kerma/Projets/Epitech/PSU/zappy/src/server/cmd/init
**
** Made by kerma
** Login   <kerma@epitech.net>
**
** Started on  Sun Jun 25 17:24:06 2017 kerma
** Last update Sat Jul  1 01:54:43 2017 kerma
*/

#include "zappy.h"

static t_teamRoot	*find_team(t_zappy *zappy, t_player *player)
{
  t_team		*tmp;
  int			i;

  i = 0;
  while (zappy->teams[i] != NULL)
    {
      tmp = zappy->teams[i]->players;
      while (tmp != NULL)
	{
	  if (tmp->player == player)
	    return (zappy->teams[i]);
	  tmp = tmp->next;
	}
      i++;
    }
  return (NULL);
}

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
  return (0);
}
