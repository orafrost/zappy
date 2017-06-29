/*
** misc.c for zappy in /home/kerma/Projets/Epitech/PSU/zappy/src/server/args
**
** Made by kerma
** Login   <kerma@epitech.net>
**
** Started on  Tue Jun 20 16:38:28 2017 kerma
** Last update Thu Jun 29 14:00:50 2017 kerma
*/

#include "zappy.h"

int	puterr(char *err)
{
  fprintf(stderr, "%s\n", err);
  return (ERROR);
}

void	*pputerr(char *err)
{
  fprintf(stderr, "%s\n", err);
  return (NULL);
}

int	is_num(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    {
      if (str[i] < '0' || str[i] > '9')
	return (1);
      i++;
    }
  return (0);
}

void	usage(t_zappy *zappy)
{
  printf("USAGE: ./zappy_server -p port -x width -y height -n name1");
  printf(" name2 ...  -c clientsNb -f freq\n");
  printf("\tport\t\tis the port number\n");
  printf("\twidth\t\tis the width of the world\n");
  printf("\theight\t\tis the height of the world\n");
  printf("\tnameX\t\tis the name of the team X\n");
  printf("\tclientsNb\tis the number of authorized clients per");
  printf(" team\n");
  printf("\tfreq\t\tis the reciprocal of time unit for execution of");
  printf(" actions\n");
  clean(zappy);
  exit(0);
}
