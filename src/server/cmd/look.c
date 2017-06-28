/*
** look.c for zappy in /home/orafrost/rendu/tek2/psu/zappy/src/server/
**
** Made by Guillaume Verrier
** Login   <verrier_g@epitech.eu>
**
** Started on  Mon Jun 26 14:01:52 2017 Guillaume Verrier
** Last update Wed Jun 28 12:35:41 2017 Guillaume Verrier
*/

#include "zappy.h"

void look(t_player *cur)
{
  int a;
  int nb_case;
  int  b;
  int  vx;
  int  vy;
  int pos[2];

  a = 0;
  nb_case = 1;
  get_vector(cur, &vx, &vy);
  while (a <= 4)
  {
    pos[0] = cur->x + vx * a + (nb_case - 1) / 2 * vy;
    pos[1] = cur->y + vy * a + (nb_case - 1) / 2 * (vx * -1);
    b = 0;
    while (b < nb_case)
    {
      pos[0] = pos[0] - vy;
      pos[1] = pos[1] + vx;
      b += 1;
    }
    nb_case += 2;
    a += 1;
  }
}

void inventory(t_zappy *game, t_player *cur)
{
  char name[2048];

  sprintf(name, "[food %d, linemate %d, deraumere %d, sibur %d, mendiane %d, phiras %d, thystame %d]\n",
          cur->resources[0], cur->resources[1], cur->resources[2], cur->resources[3], cur->resources[4],
          cur->resources[5],cur->resources[6]);
}

double calc_angle(int vect[2], int dir[2])
{
  double angle;
  double len[2];

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

int get_k(t_player *src, t_player *dest)
{
  int vect[2];
  int dir[2];
  float angle;

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

void bc_team(t_teamRoot *team, t_player *src)
{
  t_team *tmp;

  tmp = team->players;
  while (tmp != NULL)
  {
    get_k(src, tmp->player);
    tmp = tmp->next;
  }
}

void broadcast(t_zappy *game, t_player *cur)
{
  int a;

  if (cur->action.arg != NULL)
  {
    add_el
    return ;
  }
  a = 0;
  while (a < game->nb_teams)
  {
    bc_team(game->teams[a], cur);
    a += 1;
  }
}
