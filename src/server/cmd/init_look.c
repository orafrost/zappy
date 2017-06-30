/*
** init_look.c for zappy in /home/orafrost/rendu/tek2/psu/zappy/src/server/cmd/
**
** Made by Guillaume Verrier
** Login   <verrier_g@epitech.eu>
**
** Started on  Thu Jun 29 14:19:24 2017 Guillaume Verrier
** Last update Thu Jun 29 14:21:44 2017 Guillaume Verrier
*/

#include "zappy.h"

int init_look(t_zapy *game, t_player *cur)
{
  cut->action.reponse = look;
  cur->acton.dure  = 7 / game->frequency;
  return (0);
}

int init_inventory(t_zapy *game, t_player *cur)
{
  cut->action.reponse = inventory;
  cur->acton.dure  = 1 / game->frequency;
  return (0);
}

int init_broadcast(t_zapy *game, t_player *cur)
{
  cut->action.reponse = broadcast;
  cur->acton.dure  = 7 / game->frequency;
  return (0);
}
