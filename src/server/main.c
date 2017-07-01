/*
** main.c for zappy in /home/kerma/Projets/Epitech/PSU/zappy/src/server
**
** Made by kerma
** Login   <kerma@epitech.net>
**
** Started on  Tue Jun 20 14:10:18 2017 kerma
** Last update Sat Jul  1 02:22:52 2017 kerma
*/

#include "zappy.h"

int     g_state = RUN;

void    handler(int sig)
{
  if (sig == SIGINT)
    g_state = STOP;
}

int	init(t_zappy *zappy)
{
  if (init_server(zappy->server, zappy->port) == ERROR)
    return (puterr("An error occurred while initialising the socket."));
  return (0);
}
void	init_cmd_name(char *cmd[])
{
  cmd[0] = "Connect_nbr";
  cmd[1] = "Inventory";
  cmd[2] = "Forward";
  cmd[3] = "Left";
  cmd[4] = "Right";
  cmd[5] = "Look";
}

void	init_cmds(cmds cmd[])
{
  cmd[0] = &cmd_connect_nbr;
  cmd[1] = &cmd_inventory;
  cmd[2] = &cmd_forward;
  cmd[3] = &cmd_left;
  cmd[4] = &cmd_right;
  cmd[5] = &cmd_look;
}

int		main(int ac, char **av)
{
  t_zappy	zappy;
  int		ret;

  srand(time(NULL));
  signal(SIGINT, &handler);  
  if ((ret = args(&zappy, ac, av)) == 0 &&
      (ret = init(&zappy) == 0))
    {
      init_cmds(zappy.cmd);
      init_cmd_name(zappy.cmd_name);
      ret = main_loop(&zappy);
    }
  clean(&zappy);
  return (ret);
}
