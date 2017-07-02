/*
** graphic_misc.c for zappy in /home/kerma/Projets/Epitech/PSU/zappy/src/server/sock
**
** Made by kerma
** Login   <kerma@epitech.net>
**
** Started on  Sun Jul  2 05:36:43 2017 kerma
** Last update Sun Jul  2 06:44:35 2017 kerma
*/

#include "zappy.h"

void		send_map(t_zappy *zappy)
{
  char		msg[1024];
  unsigned int	x;
  unsigned int	y;

  x = 0;
  while (x < zappy->height)
    {
      y = 0;
      while (y < zappy->width)
	{
	  memset(msg, 0, 1024);
	  sprintf(msg, "bct %u %u %d %d %d %d %d %d %d", x, y,
		  zappy->map[y][x].resources[0],
		  zappy->map[y][x].resources[1],
		  zappy->map[y][x].resources[2],
		  zappy->map[y][x].resources[3],
		  zappy->map[y][x].resources[4],
		  zappy->map[y][x].resources[5],
		  zappy->map[y][x].resources[6]);
	  add_msg(&zappy->graphic->out, msg);
	  y++;
	}
      x++;
    }
}

void	send_teams(t_zappy *zappy)
{
  char	msg[1024];
  int	i;

  i = 0;
  while (i < zappy->nb_teams)
    {
      memset(msg, 0, 1024);
      sprintf(msg, "tna %s", zappy->teams[i]->name);
      add_msg(&zappy->graphic->out, msg);
      i++;
    }
}

void		send_players(t_zappy *zappy)
{
  char		msg[1024];
  t_team	*tmp;
  int		i;

  i = 0;
  while (i < zappy->nb_teams)
    {
      tmp = zappy->teams[i]->players;
      while (tmp != NULL)
	{
	  memset(msg, 0, 1024);
	  sprintf(msg, "pnw %d %d %d %d %d %s", tmp->player->id, tmp->player->x,
		  tmp->player->y, tmp->player->_dir + 1, tmp->player->level,
		  zappy->teams[i]->name);
	  add_msg(&zappy->graphic->out, msg);
	  tmp = tmp->next;
	}
      i++;
    }
}

void	send_eggs(t_zappy *zappy)
{
  char	msg[1024];
  t_egg	*tmp;

  tmp = zappy->eggs;
  while (tmp != NULL)
    {
      memset(msg, 0, 1024);
      sprintf(msg, "enw %d %d %d %d", tmp->id, 0, tmp->x, tmp->y);
      add_msg(&zappy->graphic->out, msg);
      tmp = tmp->next;
    }
}
