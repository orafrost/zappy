/*
** inventory.c for zappy in /home/kerma/Projets/Epitech/PSU/zappy/src/server/cmd
**
** Made by kerma
** Login   <kerma@epitech.net>
**
** Started on  Fri Jun 30 21:56:06 2017 kerma
** Last update Fri Jun 30 22:59:42 2017 kerma
*/

#include "zappy.h"

int	res_inventory(t_zappy *game, t_player *cur)
{
  char	buff1[2048];
  char	buff2[2048];

  (void)game;
  memset(buff1, 0, 2048);
  memset(buff2, 0, 2048);
  sprintf(buff1, "[food %d, linemate %d, deraumere %d, sibur %d,",
	  cur->resources[0],
	  cur->resources[1],
	  cur->resources[2],
	  cur->resources[3]);
  sprintf(buff2, "%s mendiane %d, phiras %d, thystame %d]",
	  buff1,
	  cur->resources[4],
	  cur->resources[5],
	  cur->resources[6]);
  add_msg(&cur->client->out, buff2);
  return (0);
}
