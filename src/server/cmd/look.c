/*
** look.c for zappy in /home/orafrost/rendu/tek2/psu/zappy/src/server/
**
** Made by Guillaume Verrier
** Login   <verrier_g@epitech.eu>
**
** Started on  Mon Jun 26 14:01:52 2017 Guillaume Verrier
** Last update Mon Jun 26 14:38:34 2017 Guillaume Verrier
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
