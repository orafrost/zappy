/*
** wait.c for zappy in /home/kerma/Projets/Epitech/PSU/zappy/src/server/sock
**
** Made by kerma
** Login   <kerma@epitech.net>
**
** Started on  Tue Jun 27 14:53:38 2017 kerma
** Last update Tue Jun 27 19:40:12 2017 kerma
*/

#include "zappy.h"

static int	add_to_team(t_zappy *zappy, char buff[], int fd)
{
  t_team	*new;
  int		a;

  a = 0;
  while (a < zappy->nb_teams)
    {
      if (strcmp(zappy->teams[a]->name, buff) == 0)
	{
	  if (zappy->teams[a]->nb >= zappy->teams[a]->max)
	    {
	      add_msg(&zappy->waiting[fd]->out, "ko");
	      return (0);
	    }
	  if ((new = add_player(&zappy->teams[a]->players, fd)) == NULL)
	    return (ERROR);
	  zappy->teams[a]->nb += 1;
	  free_buffer(zappy->waiting[fd]->out);
	  free(zappy->waiting[fd]);
	  zappy->waiting[fd] = NULL;
	  add_msg(&new->player->client->out, "ok");
	  return (0);
	}
      a += 1;
    }
  if (strcmp("GRAPHIC", buff) == 0)
    {
      // TODO handle GAPHIC client and add response to player->client->out buffer
      printf("TODO\n");
      return (0);
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
      close(fd);
      free_buffer(zappy->waiting[fd]->out);
      free(zappy->waiting[fd]);
      zappy->waiting[fd] = NULL;
      return (0);
    }
  place_end(buff);
  if (add_to_team(zappy, buff, fd) == ERROR)
    return (ERROR);
  return (0);
}

int	write_waitings(t_zappy *zappy, int fd)
{
  if (zappy->waiting[fd]->out != NULL)
    {
      dprintf(zappy->waiting[fd]->fd, "%s\n", zappy->waiting[fd]->out->msg);
      del_msg(&zappy->waiting[fd]->out);
    }
  return (0);
}
