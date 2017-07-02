/*
** eject.c for zappy in /home/kerma/Projets/Epitech/PSU/zappy/src/server/cmd
**
** Made by kerma
** Login   <kerma@epitech.net>
**
** Started on  Fri Jun 30 21:56:06 2017 kerma
** Last update Sun Jul  2 20:12:45 2017 kerma
*/

#include "zappy.h"

void	move_player(t_zappy *zappy, e_dir dir, int *y, int *x)
{
  if (dir == UP)
    {
      if ((unsigned int)(*y -= 1) <= 0)
	*y = zappy->height;
    }
  if (dir == DOWN)
    {
      if ((unsigned int)(*y += 1) >= zappy->height)
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

void	send_new_position(t_zappy *game, t_player *player)
{
  char	buff[1024];

  memset(buff, 0, 1024);
  sprintf(buff, "ppo %d %d %d %d\n", player->id, player->x,
	  player->y, player->_dir + 1);
  if (game->graphic != NULL)
    add_msg(&game->graphic->out, buff);
}

void	send_eject_msg(t_player *cur, t_player *player)
{
  char	buff[1024];

  memset(buff, 0, 1024);
  sprintf(buff, "eject: %d\n", get_k_eject(cur, player) + 1);
  add_msg(&player->client->out, buff);
}

int		send_eject(t_zappy *game, t_player *cur, int *init)
{
  t_team	*tmp;
  t_player	*player;

  tmp = game->map[cur->y][cur->x].player;
  while (tmp != NULL)
    {
      if (tmp->player != cur)
	{
	  *init = 1;
	  player = tmp->player;
	  game->map[cur->y][cur->x].player =
	    del_player(game->map[cur->y][cur->x].player, &tmp->player);
	  tmp = NULL;
	  move_player(game, cur->_dir, &player->y, &player->x);
	  if (add_player(&game->map[player->y][player->x].player,
			 player) == ERROR)
	    return (ERROR);
	  send_eject_msg(cur, player);
	  send_new_position(game, player);
	}
      if (tmp != NULL)
	tmp = tmp->next;
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
