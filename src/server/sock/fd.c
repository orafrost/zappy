/*
** fd.c for zappy in /home/kerma/Projets/Epitech/PSU/zappy/src/server/sock
**
** Made by kerma
** Login   <kerma@epitech.net>
**
** Started on  Mon Jun 26 21:10:38 2017 kerma
** Last update Tue Jun 27 21:07:33 2017 kerma
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

static int	isset_fd_waiting(t_zappy *zappy)
{
  int		i;

  i = 0;
  while (i < MAX)
    {
      if (zappy->waiting[i] != NULL)
	{
	  if (FD_ISSET(zappy->waiting[i]->fd, &zappy->fd_write) &&
	      write_waitings(zappy, i) == ERROR)
	    return (ERROR);
	  if (FD_ISSET(zappy->waiting[i]->fd, &zappy->fd_read) &&
	      read_waitings(zappy, i) == ERROR)
	    return (ERROR);
	}
      i++;
    }
  return (0);
}

int		isset_fd(t_zappy *zappy)
{
  t_team	*tmp;
  int		i;

  i = 0;
  if (FD_ISSET(zappy->server->fd, &zappy->fd_read) &&
      add_client(zappy) == ERROR)
    return (ERROR);
  while (i < zappy->nb_teams)
    {
      tmp = zappy->teams[i]->players;
      while (tmp != NULL)
	{
	  if (FD_ISSET(tmp->player->client->fd, &zappy->fd_write))
	    client_write(tmp);
	  if (FD_ISSET(tmp->player->client->fd, &zappy->fd_read) &&
	      client_read(zappy, &tmp, i) == ERROR)
	    return (ERROR);
	  if (tmp != NULL)
	    tmp = tmp->next;
	}
      i++;
    }
  if (isset_fd_waiting(zappy) == ERROR)
    return (ERROR);
  return (0);
}

int		set_fd(t_zappy *zappy)
{
  t_team	*tmp;
  int		ret;
  int		max;
  int		i;

  i = 0;
  max = zappy->server->fd;
  FD_SET(zappy->server->fd, &zappy->fd_read);
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
  if ((ret = set_fd_waiting(zappy)) > max)
    max = ret;
  return (max);
}
