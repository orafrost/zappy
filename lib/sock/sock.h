/*
** my.h for my in /home/orafrost/rendus/Tek2/ftp
**
** Made by guillaume verrier
** Login   <verrie_g@epitech.net>
**
** Started on  Wed Jun 15 15:54:01 2016 guillaume verrier
** Last update Mon May  8 13:17:06 2017 guillame verrier
*/

#ifndef _SOCK_H_
# define _SOCK_H_

# include <string.h>
# include <sys/types.h>
# include <sys/socket.h>
# include <netinet/in.h>
# include <arpa/inet.h>
# include <unistd.h>
# include <netdb.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct		s_tcp
{
  int                   socket;
  struct sockaddr_in    sin;
  int			port;
}			t_tcp;

char *my_read_cmd(t_tcp *socket);
void my_send(t_tcp *socket, char *msg);
void close_socket(t_tcp *socket);
int	connection_serveur_tcp(t_tcp *client, char *ip, int port);
int	init_serveur_tcp(t_tcp *serveur, int nb_co, int port);
int	connect_client(t_tcp *client, t_tcp *serveur);

#endif /* _SOCK_H_ */
