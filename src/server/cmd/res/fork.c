/*
** fork.c for zappy in /home/kerma/Projets/Epitech/PSU/zappy/src/server/cmd
**
** Made by kerma
** Login   <kerma@epitech.net>
**
** Started on  Fri Jun 30 21:56:06 2017 kerma
** Last update Sun Jul  2 04:15:41 2017 kerma
*/

#include "zappy.h"

int		res_fork(t_zappy *game, t_player *cur)
{
  t_teamRoot	*team;
  t_egg		*new;
  char		buff[1024];

  memset(buff, 0, 1024);
  team = find_team(game, cur);
  if ((new = add_egg(&game->eggs, team->name, cur->y, cur->x)) == NULL)
    return (ERROR);
  sprintf(buff, "enw %d %d %d %d", new->id, cur->id, new->x, new->y);
  if (game->graphic != NULL)
    add_msg(&game->graphic->out, buff);
  add_msg(&cur->client->out, "ok");
  return (0);
}
