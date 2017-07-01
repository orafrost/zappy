/*
** look.c for zappy in /home/kerma/Projets/Epitech/PSU/zappy/src/server/cmd
**
** Made by kerma
** Login   <kerma@epitech.net>
**
** Started on  Fri Jun 30 21:56:06 2017 kerma
** Last update Sat Jul  1 16:35:22 2017 kerma
*/

#include "zappy.h"

static int	get_size_look(int level)
{
  int		a;
  int		i;

  a = 4;
  i = 1;
  while (i < level)
    {
      a = a + 2 * (i - 1) + 5;
      i += 1;
    }
  return (a);
}

void	move_iterator(int pos[2], int vx, int vy)
{
  pos[0] = pos[0] - vy;
  pos[1] = pos[1] + vx;
}

static t_tile	**set_vis(t_zappy *game, t_player *cur, t_tile **vis)
{
  int		nb_case;
  int		var[3];
  int		vx;
  int		vy;
  int		pos[2];

  var[0] = 0;
  var[1] = 0;
  nb_case = 1;
  get_vector(cur, &vx, &vy);
  while (var[0] <= cur->level)
    {
      pos[0] = cur->x + vx * var[0] + (nb_case - 1) / 2 * vy;
      pos[1] = cur->y + vy * var[0] + (nb_case - 1) / 2 * (vx * -1);
      var[2] = 0;
      while (var[2] < nb_case)
	{
	  vis[var[1]++] = get_tile(game, pos);
	  move_iterator(pos, vx, vy);
	  var[2] += 1;
	}
      nb_case += 2;
      var[0] += 1;
    }
  return (vis);
}

int		res_look(t_zappy *game, t_player *cur)
{
  // TODO handel eggs
  t_tile	**vis;
  int		len;

  len = get_size_look(cur->level);
  if ((vis = malloc(sizeof(t_tile *) * len)) == NULL)
    return (puterr("Function \'malloc\' failed."));
  vis = set_vis(game, cur, vis);
  if (send_look(vis, cur, len) == ERROR)
    return (ERROR);
  free(vis);
  return (0);
}
