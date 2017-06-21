/*
** main_loop.c for zappy in /home/orafrost/rendu/tek2/psu/zappy/src/server/
**
** Made by Guillaume Verrier
** Login   <verrier_g@epitech.eu>
**
** Started on  Tue Jun 20 15:22:04 2017 Guillaume Verrier
** Last update Wed Jun 21 09:57:38 2017 Guillaume Verrier
*/

#include "zappy.h"

void main_loop(t_zappy *game)
{
  t_player *temp;
  int       id;

  id = 0;
  temp = create_player(id, UP);
  while (1)
  {
    if (hand_connection(game->server, temp) == 0)
      if (start_echange(game, temp) != -1)
        create_player(++id, UP);
  }
}
