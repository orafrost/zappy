/*
** left.c for zappy in /home/kerma/Projets/Epitech/PSU/zappy/src/server/cmd
**
** Made by kerma
** Login   <kerma@epitech.net>
**
** Started on  Fri Jun 30 21:56:06 2017 kerma
** Last update Sat Jul  1 02:26:04 2017 kerma
*/

#include "zappy.h"

int	res_left(t_zappy *game, t_player *cur)
{
  int	a;

  (void)game;
  a = cur->_dir;
  a = (a - 1);
  if (a == -1)
    // TODO
    a = 4;
  cur->_dir = a;
  add_msg(&cur->client->out, "ok");
  return (0);
}
