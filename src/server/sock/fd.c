/*
** fd.c for zappy in /home/kerma/Projets/Epitech/PSU/zappy/src/server/sock
**
** Made by kerma
** Login   <kerma@epitech.net>
**
** Started on  Mon Jun 26 21:10:38 2017 kerma
** Last update Tue Jun 27 19:29:07 2017 kerma
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

static int		isset_fd_waiting(t_zappy *zappy)
{
  int	i;

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
  t_team	*team;
  int		i;

  i = 0;
  if (FD_ISSET(zappy->server->fd, &zappy->fd_read) &&
      add_client(zappy) == ERROR)
    return (ERROR);
  while (i < zappy->nb_teams)
    {
      team = zappy->teams[i]->players;
      while (team != NULL)
	{
	  if (FD_ISSET(team->player->client->fd, &zappy->fd_write) &&
	      team->player->client->fct_write(zappy, &team, i) == ERROR)
	    return (ERROR);
	  if (FD_ISSET(team->player->client->fd, &zappy->fd_read) &&
	      team->player->client->fct_read(zappy, &team, i) == ERROR)
	    return (ERROR);
	  if (team != NULL)
	    team = team->next;
	}
      i++;
    }
  if (isset_fd_waiting(zappy) == ERROR)
    return (ERROR);
  return (0);
}

int		set_fd(t_zappy *zappy)
{
  t_team	*team;
  int		tmp;
  int		max;
  int		i;

  i = 0;
  max = zappy->server->fd;
  FD_SET(zappy->server->fd, &zappy->fd_read);
  while (i < zappy->nb_teams)
    {
      team = zappy->teams[i]->players;
      while (team != NULL)
	{
	  if (team->player->client->fd > max)
	    max = team->player->client->fd;
	  FD_SET(team->player->client->fd, &zappy->fd_read);
	  FD_SET(team->player->client->fd, &zappy->fd_write);
	  team = team->next;
	}
      i++;
    }
  if ((tmp = set_fd_waiting(zappy)) > max)
    max = tmp;
  return (max);
}
