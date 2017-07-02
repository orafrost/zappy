/*
** fd_set.c for zappy in /home/kerma/Projets/Epitech/PSU/zappy/src/server/sock
**
** Made by kerma
** Login   <kerma@epitech.net>
**
** Started on  Wed Jun 28 15:52:30 2017 kerma
** Last update Sun Jul  2 06:06:50 2017 kerma
*/

#include "zappy.h"

static int	set_fd_waiting(t_zappy *zappy)
{
  int		max;
  int		i;

  i = 0;
  max = 0;
  while (i < MAX)
    {
      if (zappy->waiting[i] != NULL)
	{
	  FD_SET(zappy->waiting[i]->fd, &zappy->fd_read);
	  FD_SET(zappy->waiting[i]->fd, &zappy->fd_write);
	  if (zappy->waiting[i]->fd > max)
	    max = zappy->waiting[i]->fd;
	}
      i++;
    }
  return (max);
}

static int	set_fd_graphic(t_zappy *zappy)
{
  int		max;

  max = 0;
  if (zappy->graphic != NULL)
    {
      FD_SET(zappy->graphic->fd, &zappy->fd_read);
      FD_SET(zappy->graphic->fd, &zappy->fd_write);
      if (zappy->graphic->fd > max)
	max = zappy->graphic->fd;
    }
  return (max);
}

static int	set_fd_players(t_zappy *zappy)
{
  t_team	*tmp;
  int		max;
  int		i;

  i = 0;
  max = 0;
  while (i < zappy->nb_teams)
    {
      tmp = zappy->teams[i]->players;
      while (tmp != NULL)
	{
	  if (tmp->player->client->fd > max)
	    max = tmp->player->client->fd;
	  FD_SET(tmp->player->client->fd, &zappy->fd_read);
	  FD_SET(tmp->player->client->fd, &zappy->fd_write);
	  tmp = tmp->next;
	}
      i++;
    }
  return (max);
}

int	set_fd(t_zappy *zappy)
{
  int	ret;
  int	max;

  max = zappy->server->fd;
  FD_SET(zappy->server->fd, &zappy->fd_read);
  if ((ret = set_fd_waiting(zappy)) > max)
    max = ret;
  if ((ret = set_fd_players(zappy)) > max)
    max = ret;
  if ((ret = set_fd_graphic(zappy)) > max)
    max = ret;
  return (max);
}
