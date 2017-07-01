/*
** utils.c for zappy in /home/kerma/Projets/Epitech/PSU/zappy/src/server/cmd/res
**
** Made by kerma
** Login   <kerma@epitech.net>
**
** Started on  Sat Jul  1 01:51:46 2017 kerma
** Last update Sat Jul  1 02:10:21 2017 kerma
*/

#include "zappy.h"

void	get_vector(t_player *cur, int *vx, int *vy)
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

t_tile	*get_tile(t_zappy *game, int pos[2], int vy)
{
  if (pos[0] < 0)
    pos[0] = game->width - pos[0];
  if ((unsigned int)pos[0] >= game->width)
    pos[0] = pos[0] - game->width;
  pos[1] += vy;
  if (pos[1] < 0)
    pos[1] = game->height - pos[1];
  if ((unsigned int)pos[1] >= game->height)
    pos[1] = pos[1] - game->height;
  return (game->map[pos[0]] + pos[1]);
}
