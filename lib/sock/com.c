/*
** main.c for ftp in /home/orafrost/rendus/Tek2/ftp
**
** Made by guillaume verrier
** Login   <verrie_g@epitech.net>
**
** Started on  Tue Jun 14 15:43:52 2016 guillaume verrier
** Last update Mon May  8 13:16:51 2017 guillame verrier
*/

#include "sock.h"

void my_send(t_tcp *socket, char *msg)
{
  write(socket->socket, msg, strlen(msg));
}

static int my_strlen(char *str)
{
  int i;

  if (str == NULL)
    return (0);
  i = 0;
  while (str[i] != 0)
    i += 1;
  return (i);
}

char *my_read_cmd(t_tcp *socket)
{
  static char temp[1024];
  char *buff;
  char *ret;
  int   len;

  ret = NULL;
  buff = strdup(temp);
  while (ret == NULL)
  {
    if ((len = read(socket->socket, temp, 1023)) == -1)
      return (NULL);
    temp[len] = '\0';
    buff = realloc(buff, my_strlen(buff) + strlen(temp) + 1);
    strcat(buff, temp);
    ret = strtok(buff, "\r\n");
  }
  ret = strdup(ret);
  if (strlen(ret) + 2 == strlen(buff))
    strcpy(temp, strtok(NULL, ""));
  else
    temp[0] = 0;
  free(buff);
  return (ret);
}
