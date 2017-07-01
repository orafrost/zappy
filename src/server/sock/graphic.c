/*
** graphic.c for zappy in /home/kerma/Projets/Epitech/PSU/zappy/src/server/sock
**
** Made by kerma
** Login   <kerma@epitech.net>
**
** Started on  Tue Jun 27 20:46:14 2017 kerma
** Last update Sat Jul  1 14:51:27 2017 kerma
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
	  sprintf(msg, "bct %u %u %d %d %d %d %d %d", x, y,
		  zappy->map[y][x].resources[0],
		  zappy->map[y][x].resources[1],
		  zappy->map[y][x].resources[2],
		  zappy->map[y][x].resources[3],
		  zappy->map[y][x].resources[4],
		  zappy->map[y][x].resources[5]);
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
  // send connected players
  // send eggs
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
  char          buff[1024];

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
  else
    {
      // TODO cmd parser
      printf("GRAPHIC: %s\n", buff);
    }
  return (0);
}
