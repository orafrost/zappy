/*
** broadcast.c for zappy in /home/kerma/Projets/Epitech/PSU/zappy/src/server/cmd
**
** Made by kerma
** Login   <kerma@epitech.net>
**
** Started on  Fri Jun 30 21:56:06 2017 kerma
** Last update Sun Jul  2 05:51:14 2017 kerma
*/

#include "zappy.h"

static double	calc_angle(int vect[2], int dir[2])
{
  double	angle;
  double	len[2];

  angle = vect[0] * dir[1] - vect[1] * dir[0];
  len[0] = dir[0] * dir[0] + dir[1] * dir[1];
  len[0] = sqrt(len[0]);
  len[1] = vect[0] * vect[0] + vect[1] * vect[1];
  len[1] = sqrt(len[1]);
  angle = angle / (len[0] * len[1]);
  angle = acos(angle);
  angle = 360  - angle * 180 / 3.141592;
  return (angle);
}

static int	get_k(t_player *src, t_player *dest)
{
  int		vect[2];
  int		dir[2];
  float		angle;

  if (src->x == dest->x && src->y == dest->y)
    return (0);
  vect[0] = src->x - dest->x;
  vect[1] = src->y - dest->y;
  get_vector(dest, &dir[0], &dir[1]);
  angle = calc_angle(vect, dir);
  angle = angle / 45 + 1;
  if (angle > 8)
    angle = 8;
  return (angle);
}

void		bc_team(t_teamRoot *team, t_player *src)
{
  t_team	*tmp;
  char		buff[1024 + strlen(src->action.arg)];

  tmp = team->players;
  while (tmp != NULL)
    {
      if (tmp->player != src)
	{
	  memset(buff, 0, 1024 + strlen(src->action.arg));
	  sprintf(buff, "message %d, %s",
		  get_k(src, tmp->player),
		  src->action.arg);
	  add_msg(&tmp->player->client->out, buff);
	}
      tmp = tmp->next;
    }
}

int	res_broadcast(t_zappy *game, t_player *cur)
{
  char	buff[1024];
  int	a;

  a = 0;
  memset(buff, 0, 1024);
  if (cur->action.arg == NULL)
    {
      add_msg(&cur->client->out, "ko");
      return (0);
    }
  while (a < game->nb_teams)
    bc_team(game->teams[a++], cur);
  sprintf(buff, "pbc %d %s", cur->id, cur->action.arg);
  if (game->graphic != NULL)
    add_msg(&game->graphic->out, buff);
  add_msg(&cur->client->out, "ok");
  free(cur->action.arg);
  return (0);
}
