/*
** forward.c for zappy in /home/kerma/Projets/Epitech/PSU/zappy/src/server/cmd
**
** Made by kerma
** Login   <kerma@epitech.net>
**
** Started on  Fri Jun 30 21:56:06 2017 kerma
** Last update Sat Jul  1 02:55:34 2017 kerma
*/

#include "zappy.h"

static int	move(t_zappy *game, t_player *cur, int vx, int vy)
{
  game->map[cur->x][cur->y].player =
    del_player(game->map[cur->x][cur->y].player, &cur);
  cur->x += vx;
  if (cur->x < 0)
    cur->x = game->width - 1;
  if ((unsigned int)cur->x >= game->width)
    cur->x = 0;
  cur->y += vy;
  if (cur->y < 0)
    cur->y = game->height - 1;
  if ((unsigned int)cur->y >= game->height)
    cur->y = 0;
  if (add_player(&game->map[cur->x][cur->y].player, cur) == ERROR)
    return (ERROR);
  return (0);
}

int	res_forward(t_zappy *game, t_player *cur)
{
  int	vx;
  int	vy;

  get_vector(cur, &vx, &vy);
  if (move(game, cur, vx, vy) == ERROR)
    return (ERROR);
  add_msg(&cur->client->out, "ok");
  return (0);
}
