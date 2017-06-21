/*
** misc.c for zappy in /home/kerma/Projets/Epitech/PSU/zappy/src/server/args
**
** Made by kerma
** Login   <kerma@epitech.net>
**
** Started on  Tue Jun 20 16:38:28 2017 kerma
** Last update Wed Jun 21 15:02:25 2017 Guillaume Verrier
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

int	is_set(t_args args)
{
  int	i;

  i = 0;
  while (i < 6)
    {
      if (args.done[i++] == 0)
	return (1);
    }
  return (0);
}

void	usage(FILE *stream, int ret)
{
  fprintf(stream, "USAGE: ./zappy_server -p port -x width -y height -n name1");
  fprintf(stream, " name2 ...  -c clientsNb -f freq\n");
  fprintf(stream, "\tport\t\tis the port number\n");
  fprintf(stream, "\twidth\t\tis the width of the world\n");
  fprintf(stream, "\theight\t\tis the height of the world\n");
  fprintf(stream, "\tnameX\t\tis the name of the team X\n");
  fprintf(stream, "\tclientsNb\tis the number of authorized clients per");
  fprintf(stream, " team\n");
  fprintf(stream, "\tfreq\t\tis the reciprocal of time unit for execution of");
  fprintf(stream, " actions\n");
  exit(ret);
}

void	arg_init(t_args *args)
{
  args->nb = 0;
  args->arg[0] = "-p";
  args->arg[1] = "-x";
  args->arg[2] = "-y";
  args->arg[3] = "-n";
  args->arg[4] = "-c";
  args->arg[5] = "-f";
  memset(args->done, 0, 6 * sizeof(int));
  args->func[0] = &arg_port;
  args->func[1] = &arg_width;
  args->func[2] = &arg_height;
  args->func[3] = &arg_names;
  args->func[4] = &arg_clients;
  args->func[5] = &arg_freq;
}
