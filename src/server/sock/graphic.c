/*
** graphic.c for zappy in /home/kerma/Projets/Epitech/PSU/zappy/src/server/sock
**
** Made by kerma
** Login   <kerma@epitech.net>
**
** Started on  Tue Jun 27 20:46:14 2017 kerma
** Last update Sun Jul  2 07:22:36 2017 kerma
*/

#include "zappy.h"

void	send_sizes(t_zappy *zappy)
{
  char	msg[1024];

  memset(msg, 0, 1024);
  sprintf(msg, "msz %d %d", zappy->width, zappy->height);
  add_msg(&zappy->graphic->out, msg);
}

void	send_frequency(t_zappy *zappy)
{
  char	msg[1024];

  memset(msg, 0, 1024);
  sprintf(msg, "sgt %d", zappy->frequency);
  add_msg(&zappy->graphic->out, msg);
}

int	add_graphic_client(t_zappy *zappy, int fd)
{
  if (zappy->graphic != NULL)
    {
      dprintf(fd, "ko\n");
      return (0);
    }
  if ((zappy->graphic = init_tcp(zappy->graphic, fd)) == NULL)
    return (ERROR);
  clean_waiting(zappy, fd);
  send_sizes(zappy);
  send_frequency(zappy);
  send_map(zappy);
  send_teams(zappy);
  send_players(zappy);
  send_eggs(zappy);
  return (0);
}

void	graphic_write(t_zappy *zappy)
{
  if (zappy->graphic->out != NULL)
    {
      dprintf(zappy->graphic->fd, "%s\n", zappy->graphic->out->msg);
      del_msg(&zappy->graphic->out);
    }
}

int	graphic_read(t_zappy *zappy)
{
  char	buff[1024];

  memset(buff, 0, 1024);
  if (zappy->graphic->init == 0)
    {
      zappy->graphic->init = 1;
      return (0);
    }
  if (recv(zappy->graphic->fd, buff, 1024, 0) <= 0)
    {
      close(zappy->graphic->fd);
      free_buffer(zappy->graphic->out);
      free(zappy->graphic);
      zappy->graphic = NULL;
      return (0);
    }
  if (place_end(buff) == 1)
    add_msg(&zappy->graphic->out, "ko");
  return (0);
}
