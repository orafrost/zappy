/*
** eject.c for zappy in /home/kerma/Projets/Epitech/PSU/zappy/src/server/cmd
**
** Made by kerma
** Login   <kerma@epitech.net>
**
** Started on  Fri Jun 30 21:56:06 2017 kerma
** Last update Sun Jul  2 06:04:45 2017 kerma
*/

#include "zappy.h"

void	move_player(t_zappy *zappy, e_dir dir, int *y, int *x)
{
  if (dir == UP)
    {
      if ((unsigned int)(*y += 1) <= 0)
	*y = zappy->height;
    }
  if (dir == DOWN)
    {
      if ((unsigned int)(*y -= 1) >= zappy->height)
	*y = 0;
    }
  if (dir == LEFT)
    {
      if ((unsigned int)(*x -= 1) <= 0)
	*x = zappy->width;
    }
  if (dir == RIGHT)
    {
      if ((unsigned int)(*x += 1) >= zappy->width)
	*x = 0;
    }
}

static int	get_k(t_player *cur, t_player *tmp)
{
  if (tmp->_dir == UP || tmp->_dir == DOWN)
    return (tmp->_dir == UP ? cur->_dir : -cur->_dir);
  if (tmp->_dir == LEFT)
    {
      if (cur->_dir == LEFT)
	return (UP);
      if (cur->_dir == RIGHT)
	return (DOWN);
      if (cur->_dir == UP)
	return (RIGHT);
      if (cur->_dir == DOWN)
	return (LEFT);
    }
  if (tmp->_dir == RIGHT)
    {
      if (cur->_dir == LEFT)
	return (DOWN);
      if (cur->_dir == RIGHT)
	return (UP);
      if (cur->_dir == UP)
	return (LEFT);
      if (cur->_dir == DOWN)
	return (RIGHT);
    }
  return (0);
}

int		send_eject(t_zappy *game, t_player *cur, int *init)
{
  t_team	*tmp;
  char		buff[1024];

  tmp = game->map[cur->y][cur->x].player;
  while (tmp != NULL)
    {
      if (tmp->player != cur)
	{
	  *init = 1;
	  memset(buff, 0, 1024);
	  game->map[cur->y][cur->x].player =
	    del_player(game->map[cur->y][cur->x].player, &tmp->player);
	  move_player(game, cur->_dir, &tmp->player->y, &tmp->player->x);
	  if (add_player(&game->map[tmp->player->y][tmp->player->x].player,
			 tmp->player) == ERROR)
	    return (ERROR);
	  sprintf(buff, "eject: %d\n", get_k(cur, tmp->player) + 1);
	  add_msg(&tmp->player->client->out, buff);
	}
    }
  return (0);
}

int	res_eject(t_zappy *game, t_player *cur)
{
  int	init;

  init = 0;
  if (send_eject(game, cur, &init) == ERROR)
    return (ERROR);
  if (init == 1)
    add_msg(&cur->client->out, "ok");
  else if (init == 0)
    add_msg(&cur->client->out, "ko");
  return (0);
}
