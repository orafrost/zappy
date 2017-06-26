/*
** fork.c for zappy in /home/kerma/Projets/Epitech/PSU/zappy/src/server/cmd
**
** Made by kerma
** Login   <kerma@epitech.net>
**
** Started on  Sun Jun 25 17:42:52 2017 kerma
** Last update Sun Jun 25 17:56:41 2017 kerma
*/

#include "zappy.h"

int	fork(t_zappy *zappy, t_player *player)
{
  player->action->action = FORK;
  player->action->start = time(NULL);
  player->action->dure = 42 / zappy->frequency;
  /* send(player->client->socket, "ok\n", 3, 0); */
  return (0);
}
