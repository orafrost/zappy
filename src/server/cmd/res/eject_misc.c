/*
** eject_misc.c for zappy in /home/kerma/Projets/Epitech/PSU/zappy/src/server/cmd/res
**
** Made by kerma
** Login   <kerma@epitech.net>
**
** Started on  Sun Jul  2 19:41:23 2017 kerma
** Last update Sun Jul  2 20:02:41 2017 kerma
*/

#include "zappy.h"

static int	get_k_down(t_player *cur)
{
  if (cur->_dir == LEFT)
    return (RIGHT);
  if (cur->_dir == RIGHT)
    return (LEFT);
  if (cur->_dir == UP)
    return (DOWN);
  if (cur->_dir == DOWN)
    return (UP);
  return (0);
}

static int	get_k_left(t_player *cur)
{
  if (cur->_dir == LEFT)
    return (UP);
  if (cur->_dir == RIGHT)
    return (DOWN);
  if (cur->_dir == UP)
    return (RIGHT);
  if (cur->_dir == DOWN)
    return (LEFT);
  return (0);
}

static int	get_k_right(t_player *cur)
{
  if (cur->_dir == LEFT)
    return (DOWN);
  if (cur->_dir == RIGHT)
    return (UP);
  if (cur->_dir == UP)
    return (LEFT);
  if (cur->_dir == DOWN)
    return (RIGHT);
  return (0);
}

int	get_k_eject(t_player *cur, t_player *tmp)
{
  if (tmp->_dir == UP)
    return (cur->_dir);
  if (tmp->_dir == DOWN)
    return (get_k_down(cur));
  if (tmp->_dir == LEFT)
    return (get_k_left(cur));
  if (tmp->_dir == RIGHT)
    return (get_k_right(cur));
  return (0);
}
