/*
** left.c for zappy in /home/kerma/Projets/Epitech/PSU/zappy/src/server/cmd
**
** Made by kerma
** Login   <kerma@epitech.net>
**
** Started on  Fri Jun 30 21:56:06 2017 kerma
** Last update Sun Jul  2 06:05:20 2017 kerma
*/

#include "zappy.h"

int	res_left(t_zappy *game, t_player *cur)
{
  char	buff[1024];
  int	a;

  a = cur->_dir;
  a = (a - 1);
  if (a == -1)
    a = 3;
  cur->_dir = a;
  memset(buff, 0, 1024);
  add_msg(&cur->client->out, "ok");
  sprintf(buff, "ppo %d %d %d %d", cur->id, cur->x, cur->y, cur->_dir + 1);
  if (game->graphic != NULL)
    add_msg(&game->graphic->out, buff);
  return (0);
}
