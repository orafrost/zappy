/*
** sock.c for zappy in /home/kerma/Projets/Epitech/PSU/zappy/lib/sock
**
** Made by kerma
** Login   <kerma@epitech.net>
**
** Started on  Mon Jun 26 18:57:37 2017 kerma
** Last update Tue Jun 27 20:53:58 2017 kerma
*/

#include "zappy.h"

static int	close_leave(int fd, char *err)
{
  close(fd);
  return (puterr(err));
}

static int		init_socket(t_tcp *tcp, struct sockaddr_in *s_in,
				    int port)
{
  struct protoent	*pe;

  s_in->sin_family = AF_INET;
  s_in->sin_port = htons(port);
  s_in->sin_addr.s_addr = INADDR_ANY;
  if ((pe = getprotobyname("TCP")) == NULL)
    return (ERROR);
  if ((tcp->fd = socket(PF_INET, SOCK_STREAM, pe->p_proto)) == -1)
    return (ERROR);
  if (setsockopt(tcp->fd, SOL_SOCKET, SO_REUSEADDR,
		 &(int){1}, sizeof(int)) == -1)
    return (close_leave(tcp->fd, "Function \'setsockopt\' failed."));
  return (0);
}

int			add_client(t_zappy *zappy)
{
  struct sockaddr_in    s_in;
  socklen_t             s_in_size;
  int			fd;

  s_in_size = sizeof(s_in);
  if ((fd = accept(zappy->server->fd, (struct sockaddr *)&s_in,
		   &s_in_size)) == -1)
    return (puterr("Function \'accept\' failed."));
  if (fd >= MAX)
    {
      dprintf(fd, "Too much connections\n");
      close(fd);
      return (0);
    }
  if ((zappy->waiting[fd] = init_tcp(zappy->waiting[fd], fd)) == NULL)
    return (ERROR);
  add_msg(&zappy->waiting[fd]->out, "WELCOME");
  return (0);
}

int			init_server(t_tcp *tcp, int port)
{
  struct sockaddr_in	s_in;
  
  if (init_socket(tcp, &s_in, port) == ERROR)
    return (ERROR);
  if (bind(tcp->fd, (const struct sockaddr *)&s_in, sizeof(s_in)) == -1)
    return (close_leave(tcp->fd, "Function \'bind\' failed."));
  if (listen(tcp->fd, MAX) == -1)
    return (close_leave(tcp->fd, "Function \'list\' failed."));
  return (0);
}
