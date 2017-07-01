/*
** wait.c for zappy in /home/kerma/Projets/Epitech/PSU/zappy/src/server/sock
**
** Made by kerma
** Login   <kerma@epitech.net>
**
** Started on  Tue Jun 27 14:53:38 2017 kerma
** Last update Sat Jul  1 18:03:56 2017 kerma
*/

#include "zappy.h"

void	clean_waiting(t_zappy *zappy, int fd)
{
  free_buffer(zappy->waiting[fd]->out);
  free(zappy->waiting[fd]);
  zappy->waiting[fd] = NULL;
}

static int	add_to_team(t_zappy *zappy, int fd, int i)
{
  t_team	*new;
  char		msg1[4];
  char		msg2[5];

  if ((new = add_team(zappy, &zappy->teams[i]->players, fd)) == NULL)
    return (ERROR);
  zappy->teams[i]->nb++;
  clean_waiting(zappy, fd);
  add_player(&zappy->map[new->player->y][new->player->x].player, new->player);
  memset(msg1, 0, 4);
  memset(msg2, 0, 5);
  sprintf(msg1, "%d", zappy->teams[i]->max - zappy->teams[i]->nb);
  sprintf(msg2, "%d %d", zappy->width, zappy->height);
  add_msg(&new->player->client->out, msg1);
  add_msg(&new->player->client->out, msg2);
  return (0);
}

static int	new_player(t_zappy *zappy, char buff[], int fd)
{
  int		i;

  i = 0;
  while (i < zappy->nb_teams)
    {
      if (strcmp(zappy->teams[i]->name, buff) == 0)
	{
	  if (zappy->teams[i]->nb >= zappy->teams[i]->max)
	    add_msg(&zappy->waiting[fd]->out, "ko");
	  else if (add_to_team(zappy, fd, i) == ERROR)
	    return (ERROR);
	  return (0);
	}
      i++;
    }
  if (strcmp("GRAPHIC", buff) == 0)
    {
      if (add_graphic_client(zappy, fd) == ERROR)
	return (ERROR);
    }
  else
    add_msg(&zappy->waiting[fd]->out, "ko");
  return (0);
}

int	read_waitings(t_zappy *zappy, int fd)
{
  char  buff[1024];
  
  memset(buff, 0, 1024);
  if (recv(zappy->waiting[fd]->fd, buff, 1024, 0) <= 0)
    {
      clean_waiting(zappy, fd);
      close(fd);
      return (0);
    }
  if (place_end(buff) == 1)
    add_msg(&zappy->waiting[fd]->out, "ko");
  else if (new_player(zappy, buff, fd) == ERROR)
    return (ERROR);
  return (0);
}

void		write_waitings(t_zappy *zappy, int fd)
{
  t_tcp		*conn;

  conn = zappy->waiting[fd];
  if (conn->out != NULL)
    {
      dprintf(conn->fd, "%s\n", conn->out->msg);
      del_msg(&conn->out);
    }
}
