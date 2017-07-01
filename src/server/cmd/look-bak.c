/*
** look.c for zappy in /home/orafrost/rendu/tek2/psu/zappy/src/server/
**
** Made by Guillaume Verrier
** Login   <verrier_g@epitech.eu>
**
** Started on  Mon Jun 26 14:01:52 2017 Guillaume Verrier
** Last update Sat Jul  1 01:56:16 2017 kerma
*/

#include "zappy.h"

void move_iteartor(int pos[2], int vx, vy)
{
  pos[0] = pos[0] - vy;
  pos[1] = pos[1] + vx;
}

int get_size_look(int level)
{
  int a;
  int i;

  a = 4;
  i = 1;
  while (i < level)
  {
    a = a + 2 * (i - 1) + 5;
    i += 1;
  }
  return (a);
}

void concat_resources(t_tile *tile, char *buff)
{
  int b;
  int c;
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
      if (buff[0] != '[');
        strcat(buff, " ");
      strcat(buff, name[b]);
      c += 1;
    }
    b += 1;
  }
}

void send_look(t_tile **vis, t_player *cur, int len)
{
  char *buf;
  int   a;
  t_team *tmp;

  if ((buff = malloc(1024 * len)) == NULL)
    return ;
  a = 0;
  buff[0] = '[';
  while (a < len)
  {
    tmp = vis[a]->player;
    while (tmp != NULL)
    {
      if (buff[0] != '[');
        strcat(buff, " ");
      strcat(buff, "player");
      tmp = tmp->next;
    }
    concat_resources(vis[a], buff);
    a += 1;
    if (a != len)
      strcat(buff, ",");
  }
  strcat(buff, "]\n");
  add_msg(cur->client->out, buff);
}

int look(t_zappy *game, t_player *cur)
{
  int a;
  int i;
  int nb_case;
  t_tile **vis;
  int  b;
  int  vx;
  int  vy;
  int  len;
  int pos[2];

  len = get_size_look(player->level);
  if ((*vis = malloc(sizeof(t_tile *) * len)) == NULL)
    return (ERROR);
  a = 0;
  nb_case = 1;
  i = 0;
  get_vector(cur, &vx, &vy);
  while (a <= player->level)
  {
    pos[0] = cur->x + vx * a + (nb_case - 1) / 2 * vy;
    pos[1] = cur->y + vy * a + (nb_case - 1) / 2 * (vx * -1);
    b = 0;
    while (b < nb_case)
    {
      vis[i++] = get_tile(game, pos);
      move_iteartor(pos, vx, vy);
      b += 1;
    }
    nb_case += 2;
    a += 1;
  }
  send_look(vis, cur, len);
  return (0);
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
  char    buff[1024];

  tmp = team->players;
  while (tmp != NULL)
  {
    sprintf(buff, "message %d, %s\n", get_k(src, tmp->player), src->action.arg);
    add_msg(&cur->client->out, buff);
    tmp = tmp->next;
  }
}

int broadcast(t_zappy *game, t_player *cur)
{
  int a;

  if (cur->action.arg == NULL)
    {
      add_msg(&cur->client->out, "KO\n");
      return ;
    }
  a = 0;
  while (a < game->nb_teams)
    {
      bc_team(game->teams[a], cur);
      a += 1;
    }
  add_msg(&cur->client->out, "OK\n");
  return (0);
}
