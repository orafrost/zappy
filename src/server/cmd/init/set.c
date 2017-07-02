/*
** set.c for zappy in /home/kerma/Projets/Epitech/PSU/zappy/src/server/cmd/init
**
** Made by kerma
** Login   <kerma@epitech.net>
**
** Started on  Fri Jun 30 22:40:39 2017 kerma
** Last update Sat Jul  1 15:05:52 2017 kerma
*/

#include "zappy.h"

static int	is_validobject(t_player *cur, char *arg)
{
  int		resource;

  if ((resource = find_resource(arg)) == WRONG_RESOURCE)
    return (1);
  if (cur->resources[resource] == 0)
    return (1);
  return (0);
}

int	cmd_set(t_zappy *game, t_player *cur)
{
  if (cur->action.arg == NULL ||
      is_validobject(cur, cur->action.arg) == 1)
    {
      add_msg(&cur->client->out, "ko");
      return (0);
    }
  if ((cur->action.arg = strdup(cur->action.arg)) == NULL)
    return (puterr("Function \'strdup\' failed."));
  cur->action.response = res_set;
  cur->action.dure = 7 / game->frequency;
  return (0);
}
