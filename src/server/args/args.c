/*
** args.c for zappy in /home/kerma/Projets/Epitech/PSU/zappy/src/server/args
**
** Made by kerma
** Login   <kerma@epitech.net>
**
** Started on  Tue Jun 20 14:30:23 2017 kerma
** Last update Wed Jun 21 00:37:44 2017 kerma
*/

#include "zappy.h"

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
  memset(args->done, 0, 6);
  args->func[0] = &arg_port;
  args->func[1] = &arg_width;
  args->func[2] = &arg_height;
  args->func[3] = &arg_names;
  args->func[4] = &arg_clients;
  args->func[5] = &arg_freq;
}

void	arg_pars(t_zappy *zappy, char **av, t_args *args, int *i)
{
  int	k;

  k = 0;
  while (k < 6)
    {
      if (strcmp(av[*i], args->arg[k]) == 0)
	{
	  args->func[k](zappy, av, i, &args->nb);
	  args->done[k] = 1;
	  return ;
	}
      k++;
    }
  puterr("Unknown argument.");
}

void		args(t_zappy *zappy, int ac, char **av)
{
  t_args	args;
  int		i;

  i = 1;
  arg_init(&args);
  zappy->map = NULL;
  zappy->teams = NULL;
  if (ac < 2)
    usage(stderr, ERROR);
  while (i < ac)
    {
      if (strcmp(av[i], "-help") == 0)
	usage(stdin, 0);
      else
	arg_pars(zappy, av, &args, &i);
      i++;
    }
  // TODO test if all arg was set
  // TODO test args->nb
  // TODO test malloc zappy->map
}
