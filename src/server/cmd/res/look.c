/*
** look.c for zappy in /home/kerma/Projets/Epitech/PSU/zappy/src/server/cmd
**
** Made by kerma
** Login   <kerma@epitech.net>
**
** Started on  Fri Jun 30 21:56:06 2017 kerma
** Last update Sat Jul  1 02:19:05 2017 kerma
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

void	concat_resources(t_tile *tile, char *buff)
{
  int	b;
  int	c;
  char  *name[7];

  name[0] = "food";
  name[1] = "linemate";
  name[2] = "deraumere";
  name[3] = "sibur";
  name[4] = "mendiane";
  name[5] = "phiras";
  name[6] = "thystame";
  b = 0;
  while (b < 7)
    {
      c = 0;
      while (c < tile->resources[b])
	{
	  if (buff[0] != '[')
	    strcat(buff, " ");
	  strcat(buff, name[b]);
	  c += 1;
	}
      b += 1;
    }
}

int		send_look(t_tile **vis, t_player *cur, int len)
{
  char		*buff;
  int		a;
  t_team	*tmp;

  if ((buff = malloc(1024 * len)) == NULL)
    return (puterr("Function \'malloc\' failed."));
  a = 0;
  buff[0] = '[';
  while (a < len)
    {
      tmp = vis[a]->player;
      while (tmp != NULL)
	{
	  if (buff[0] != '[')
	    strcat(buff, " ");
	  strcat(buff, "player");
	  tmp = tmp->next;
	}
      concat_resources(vis[a], buff);
      a += 1;
      if (a != len)
	strcat(buff, ",");
    }
  strcat(buff, "]");
  add_msg(&cur->client->out, buff);
  return (0);
}

int		res_look(t_zappy *game, t_player *cur)
{
  // TODO handel eggs
  // TODO fix memory leaks + free vis/buffers
  t_tile	**vis;
  int		a;
  int		i;
  int		nb_case;
  int		b;
  int		vx;
  int		vy;
  int		len;
  int		pos[2];

  len = get_size_look(cur->level);
  if ((vis = malloc(sizeof(t_tile *) * len)) == NULL)
    return (puterr("Function \'malloc\' failed."));
  a = 0;
  i = 0;
  nb_case = 1;
  get_vector(cur, &vx, &vy);
  while (a <= cur->level)
    {
      pos[0] = cur->x + vx * a + (nb_case - 1) / 2 * vy;
      pos[1] = cur->y + vy * a + (nb_case - 1) / 2 * (vx * -1);
      b = 0;
      while (b < nb_case)
	{
	  vis[i++] = get_tile(game, pos, vy);
	  move_iterator(pos, vx, vy);
	  b += 1;
	}
      nb_case += 2;
      a += 1;
    }
  if (send_look(vis, cur, len) == ERROR)
    return (ERROR);
  return (0);
}
