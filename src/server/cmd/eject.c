/*
** eject.c for zappy in /home/kerma/Projets/Epitech/PSU/zappy/src/server/cmd
**
** Made by kerma
** Login   <kerma@epitech.net>
**
** Started on  Sun Jun 25 17:42:52 2017 kerma
** Last update Sun Jun 25 18:05:32 2017 kerma
*/

#include "zappy.h"

int	eject(t_zappy *zappy, t_player *player)
{
  player->action->action = EJECT;
  player->action->start = time(NULL);
  player->action->dure = 7 / zappy->frequency;
  // send 'eject: K\n' to all client in the same tile
  // find out about ko/ok context

  /* send(player->client->socket, "ok\n", 3, 0); */
  return (0);
}
