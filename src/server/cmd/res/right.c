/*
** right.c for zappy in /home/kerma/Projets/Epitech/PSU/zappy/src/server/cmd
**
** Made by kerma
** Login   <kerma@epitech.net>
**
** Started on  Fri Jun 30 21:56:06 2017 kerma
** Last update Sun Jul  2 06:44:15 2017 kerma
*/

#include "zappy.h"

int	res_right(t_zappy *game, t_player *cur)
{
  char	buff[1024];
  int	a;

  a = cur->_dir;
  a = (a + 1) % 4;
  cur->_dir = a;
  memset(buff, 0, 1024);
  sprintf(buff, "ppo %d %d %d %d", cur->id, cur->x, cur->y, cur->_dir + 1);
  if (game->graphic != NULL)
    add_msg(&game->graphic->out, buff);
  add_msg(&cur->client->out, "ok");
  return (0);
}
