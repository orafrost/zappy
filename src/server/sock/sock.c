/*
** sock.c for zappy in /home/kerma/Projets/Epitech/PSU/zappy/lib/sock
**
** Made by kerma
** Login   <kerma@epitech.net>
**
** Started on  Mon Jun 26 18:57:37 2017 kerma
** Last update Tue Jun 27 15:15:06 2017 kerma
*/

#include "zappy.h"

static int	close_leave(int fd)
{
  close(fd);
  return (ERROR);
}

static int		init_socket(t_tcp *tcp, struct sockaddr_in *s_in,
				    int port, char *ip)
{
  struct protoent	*pe;

  s_in->sin_family = AF_INET;
  s_in->sin_port = htons(port);
  s_in->sin_addr.s_addr = (ip == NULL) ? INADDR_ANY : inet_addr(ip);
  if ((pe = getprotobyname("TCP")) == NULL)
    return (ERROR);
  if ((tcp->fd = socket(PF_INET, SOCK_STREAM, pe->p_proto)) == -1)
    return (ERROR);
  if (setsockopt(tcp->fd, SOL_SOCKET, SO_REUSEADDR, &(int){1}, sizeof(int)) == -1)
    return (close_leave(tcp->fd));
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
  if ((zappy->waiting[fd] = init_tcp(zappy->waiting[fd], fd, WAITING)) == NULL)
    return (ERROR);
  dprintf(fd, "WELCOME\n");
  return (0);
}

int			init_server(t_tcp *tcp, int port)
{
  struct sockaddr_in	s_in;
  
  if (init_socket(tcp, &s_in, port, NULL) == ERROR)
    return (ERROR);
  if (bind(tcp->fd, (const struct sockaddr *)&s_in, sizeof(s_in)) == -1)
    return (close_leave(tcp->fd));
  if (listen(tcp->fd, MAX) == -1)
    return (close_leave(tcp->fd));
  tcp->out = NULL;
  tcp->fct_read = NULL;
  tcp->fct_write = NULL;
  return (0);
}
