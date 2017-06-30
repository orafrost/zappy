/*
** move.c for zappy in /home/orafrost/rendu/tek2/psu/zappy/src/server/
**
** Made by Guillaume Verrier
** Login   <verrier_g@epitech.eu>
**
** Started on  Mon Jun 26 11:41:15 2017 Guillaume Verrier
** Last update Thu Jun 29 14:18:29 2017 Guillaume Verrier
*/

#include "zappy.h"

void move(t_zappy *game, t_player *cur, int vx, int vy)
{
  map[cur->x][cur->y].player = del_elem(map[cur->x][cur->y].player, cur);
  cur->x += vx;
  if (cur->x < 0)
    cur->x = game->width - 1;
  if (cur->x >= game->width)
    cur->x = 0;
  cur->y += vy;
  if (cur->y < 0)
    cur->y = game->height - 1;
  if (cur->y >= game->height)
    cur->y = 0;
  map[cur->x][cur->y].player = add_elem(map[cur->x][cur->y].player, cur);
}

void get_vector(t_player *cur, int *vx, int *vy)
{
  if (cur->_dir == UP)
  {
    *vx = 0;
    *vy = -1;
  }
  else if (cur->_dir == RIGHT)
  {
    *vx = 1;
    *vy = 0;
  }
  else if (cur->_dir == DOWN)
  {
    *vx = 0;
    *vy = 1;
  }
  else
  {
    *vx = -1;
    *vy = 0;
  }
}

int move_up(t_zappy *game, t_player *cur)
{
  int vx;
  int vy;

  if (cur->action.arg != NULL)
  {
    add_msg(cur->client->out, "KO\n");
    return (0);
  }
  get_vector(cur, &vx, &vy);
  move(game, player, vx, vy);
  cut->action.reponse = resp_ok;
  cur->acton.dure  = 7 / game->frequency;
  return (0);
}

void turn_right(t_zappy *game, t_player *cur)
{
  int a;

  if (cur->action.arg != NULL)
  {
    add_msg(cur->client->out, "KO\n");
    return (0);
  }
  a = cur->_dir;
  a = (a + 1) % 5;
  cur->_dir = a;
  cut->action.reponse = resp_ok;
  cur->acton.dure  = 7 / game->frequency;
  return (0);
}

void turn_left(t_zappy *game, t_player *cur)
{
  int a;

  if (cur->action.arg != NULL)
  {
    add_msg(cur->client->out, "KO\n");
    return (0);
  }
  a = cur->_dir;
  a = (a - 1);
  if (a == -1)
    a = 4;
  cur->_dir = a;
  cut->action.reponse = resp_ok;
  cur->acton.dure  = 7 / game->frequency;
  return (0);
}

t_tile *get_tile(t_zappy *game, int pos[2])
{
  if (pos[0] < 0)
    pos[0] = game->width - pos[0];
  if (pos[0] >= game->width)
    pos[0] = pos[0] - game->width;
  pos[1] += vy;
  if (pos[1] < 0)
    pos[1] = game->height - pos[1];
  if (pos[1] >= game->height)
    pos[1] = pos[1] - game->height;
  return (game->map[pos[0]] + pos[1]);
}
