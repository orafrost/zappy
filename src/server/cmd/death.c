/*
** death.c for zappy in /home/kerma/Projets/Epitech/PSU/zappy/src/server/cmd
**
** Made by kerma
** Login   <kerma@epitech.net>
**
** Started on  Sun Jun 25 17:42:52 2017 kerma
** Last update Sun Jun 25 18:06:41 2017 kerma
*/

#include "zappy.h"

int	death(t_zappy *zappy, t_player *player)
{
  // clean player and player on map tile
  send(player->client->socket, "dead\n", 5, 0);
  return (0);
}
