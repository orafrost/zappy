/*
** main.c for ftp in /home/orafrost/rendus/Tek2/ftp
** 
** Made by guillaume verrier
** Login   <verrie_g@epitech.net>
** 
** Started on  Tue Jun 14 15:43:52 2016 guillaume verrier
** Last update Sat Jun 18 12:16:40 2016 guillaume verrier
*/

#include "sock.h"

int	connection_serveur_tcp(t_tcp *client, char *ip, int port)
{
  client->socket = socket(AF_INET, SOCK_STREAM, 0);
  client->port = port;
  if (client->socket == -1)
    {
      write(2, "error creation socket\n", 22);
      return (1);
    }
  client->sin.sin_addr.s_addr = inet_addr(ip);
  client->sin.sin_family = AF_INET;
  client->sin.sin_port = htons(client->port);
  if (connect(client->socket,
	   (const struct sockaddr *)&client->sin, sizeof(client->sin)) == -1)
    {
      write(2, "error conection to serveur\n", 27);
      close(client->socket);
      return (1);
    }
  return (0);
}
