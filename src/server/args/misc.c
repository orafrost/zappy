/*
** misc.c for zappy in /home/kerma/Projets/Epitech/PSU/zappy/src/server/args
**
** Made by kerma
** Login   <kerma@epitech.net>
**
** Started on  Tue Jun 20 16:38:28 2017 kerma
** Last update Fri Jun 23 15:57:00 2017 kerma
*/

#include "zappy.h"

void	puterr(char *err)
{
  fprintf(stderr, "%s\n", err);
  exit(ERROR);
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

void	usage()
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
  exit(0);
}

void	arg_init(t_args *args)
{
  args->nb = -1;
  args->arg[0] = "-p";
  args->arg[1] = "-x";
  args->arg[2] = "-y";
  args->arg[3] = "-n";
  args->arg[4] = "-c";
  args->arg[5] = "-f";
  args->func[0] = &arg_port;
  args->func[1] = &arg_width;
  args->func[2] = &arg_height;
  args->func[3] = &arg_names;
  args->func[4] = &arg_clients;
  args->func[5] = &arg_freq;
}
