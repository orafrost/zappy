/*
** response.c for zappy in /home/orafrost/rendu/tek2/psu/zappy/src/server/
**
** Made by Guillaume Verrier
** Login   <verrier_g@epitech.eu>
**
** Started on  Tue Jun 27 13:57:33 2017 Guillaume Verrier
** Last update Thu Jun 29 14:08:17 2017 Guillaume Verrier
*/

#include "zappy.h"

int resp_ok(t_zappy *game, t_player *cur)
{
  add_msg(cur->client->out, "OK\n");
  return (0);
}
