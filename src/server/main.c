/*
** main.c for zappy in /home/kerma/Projets/Epitech/PSU/zappy/src/server
**
** Made by kerma
** Login   <kerma@epitech.net>
**
** Started on  Tue Jun 20 14:10:18 2017 kerma
** Last update Sat Jul  1 17:04:35 2017 kerma
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

void	init_cmds(cmds cmds[], char *cmd[])
{
  cmd[0] = "Connect_nbr";
  cmd[1] = "Inventory";
  cmd[2] = "Forward";
  cmd[3] = "Left";
  cmd[4] = "Right";
  cmd[5] = "Look";
  cmd[6] = "Take";
  cmd[7] = "Set";
  cmd[8] = "Broadcast";
  cmds[0] = &cmd_connect_nbr;
  cmds[1] = &cmd_inventory;
  cmds[2] = &cmd_forward;
  cmds[3] = &cmd_left;
  cmds[4] = &cmd_right;
  cmds[5] = &cmd_look;
  cmds[6] = &cmd_take;
  cmds[7] = &cmd_set;
  cmds[8] = &cmd_broadcast;
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
      init_cmds(zappy.cmd, zappy.cmd_name);
      ret = main_loop(&zappy);
    }
  clean(&zappy);
  return (ret);
}
