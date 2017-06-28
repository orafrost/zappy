/*
** fd.c for zappy in /home/kerma/Projets/Epitech/PSU/zappy/src/server/sock
**
** Made by kerma
** Login   <kerma@epitech.net>
**
** Started on  Mon Jun 26 21:10:38 2017 kerma
** Last update Wed Jun 28 16:04:53 2017 kerma
*/

#include "zappy.h"

static int	isset_fd_waiting(t_zappy *zappy)
{
  int		i;

  i = 0;
  while (i < MAX)
    {
      if (zappy->waiting[i] != NULL)
	{
	  if (FD_ISSET(zappy->waiting[i]->fd, &zappy->fd_write))
	    write_waitings(zappy, i);
	  if (FD_ISSET(zappy->waiting[i]->fd, &zappy->fd_read) &&
	      read_waitings(zappy, i) == ERROR)
	    return (ERROR);
	}
      i++;
    }
  return (0);
}

static int	isset_fd_graphic(t_zappy *zappy)
{
  if (zappy->graphic != NULL)
    {
      if (FD_ISSET(zappy->graphic->fd, &zappy->fd_write))
	graphic_write(zappy);
      if (FD_ISSET(zappy->graphic->fd, &zappy->fd_read) &&
	  graphic_read(zappy) == ERROR)
	return (ERROR);
    }
  return (0);
}

static int	isset_fd_players(t_zappy *zappy)
{  
  t_team	*tmp;
  int		i;

  i = 0;
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
  return (0);
}

int	isset_fd(t_zappy *zappy)
{
  if (FD_ISSET(zappy->server->fd, &zappy->fd_read) &&
      add_client(zappy) == ERROR)
    return (ERROR);
  if (isset_fd_waiting(zappy) == ERROR)
    return (ERROR);
  if (isset_fd_players(zappy) == ERROR)
    return (ERROR);
  if (isset_fd_graphic(zappy) == ERROR)
    return (ERROR);
  return (0);
}
