/*
** incantation_misc.c for zappy in /home/kerma/Projets/Epitech/PSU/zappy/src/server/cmd/res
**
** Made by kerma
** Login   <kerma@epitech.net>
**
** Started on  Sun Jul  2 03:33:41 2017 kerma
** Last update Sun Jul  2 03:38:43 2017 kerma
*/

#include "zappy.h"

void	init_nbplayers(int nb_players[])
{
  nb_players[0] = 1;
  nb_players[1] = 2;
  nb_players[2] = 2;
  nb_players[3] = 4;
  nb_players[4] = 4;
  nb_players[5] = 6;
  nb_players[6] = 6;
}

void	init_resources_rest(int resources[7][6])
{
  resources[5][0] = 1;
  resources[5][1] = 2;
  resources[5][2] = 4;
  resources[5][4] = 1;
  resources[6][0] = 2;
  resources[6][1] = 2;
  resources[6][2] = 2;
  resources[6][3] = 2;
  resources[6][4] = 2;
  resources[6][5] = 1;
}

void	init_resources(int resources[7][6])
{
  memset(resources[0], 0, 6 * sizeof(int));
  memset(resources[1], 0, 6 * sizeof(int));
  memset(resources[2], 0, 6 * sizeof(int));
  memset(resources[3], 0, 6 * sizeof(int));
  memset(resources[4], 0, 6 * sizeof(int));
  memset(resources[5], 0, 6 * sizeof(int));
  resources[0][0] = 1;
  resources[1][0] = 1;
  resources[1][1] = 1;
  resources[1][2] = 1;
  resources[2][0] = 2;
  resources[2][2] = 1;
  resources[2][4] = 2;
  resources[3][0] = 1;
  resources[3][1] = 1;
  resources[3][2] = 2;
  resources[3][4] = 4;
  resources[4][0] = 1;
  resources[4][1] = 2;
  resources[4][2] = 1;
  resources[4][3] = 3;
  init_resources_rest(resources);
}
