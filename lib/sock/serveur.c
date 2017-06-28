/*
** main.c for ftp in /home/orafrost/rendus/Tek2/ftp
**
** Made by guillaume verrier
** Login   <verrie_g@epitech.net>
**
** Started on  Tue Jun 14 15:43:52 2016 guillaume verrier
** Last update Mon Jun 26 17:07:58 2017 Guillaume Verrier
*/

#include "sock.h"

int	init_serveur_tcp(t_tcp *serveur, int nb_co, int port)
{
  serveur->socket = socket(AF_INET, SOCK_STREAM, 0);
  serveur->port = port;
  if (serveur->socket == -1)
    {
      write(2, "error creation socket\n", 22);
      return (1);
    }
  serveur->sin.sin_addr.s_addr = htonl(INADDR_ANY);
  serveur->sin.sin_family = AF_INET;
  serveur->sin.sin_port = htons(serveur->port);
  if (bind(serveur->socket,
	   (const struct sockaddr *)&serveur->sin, sizeof(serveur->sin)) == -1)
    {
      write(2, "error bind socket\n", 18);
      close(serveur->socket);
      return (1);
    }
  if (listen(serveur->socket, nb_co) == -1)
    {
      write(2, "error listen\n", 13);
      close(serveur->socket);
      return (1);
    }
  return (0);
}

int	connect_client(t_tcp *client, t_tcp *serveur, int flags)
{
  int	size;

  size = sizeof(client->sin);
  client->socket = accept4(serveur->socket,
			  (struct sockaddr *)&client->sin, (socklen_t *)&size, flags);
  if (client->socket == -1)
    {
      write(2, "error connection to client\n", 27);
      close(serveur->socket);
      return (1);
    }
  return (0);
}

void close_socket(t_tcp *socket)
{
  close(socket->socket);
}
