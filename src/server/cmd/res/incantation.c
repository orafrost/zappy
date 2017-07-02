/*
** incantation.c for zappy in /home/kerma/Projets/Epitech/PSU/zappy/src/server/cmd
**
** Made by kerma
** Login   <kerma@epitech.net>
**
** Started on  Fri Jun 30 21:56:06 2017 kerma
** Last update Sun Jul  2 05:52:46 2017 kerma
*/

#include "zappy.h"

static int	test_players(t_zappy *game, t_player *cur, int nb_players[])
{
  t_team	*tmp;
  int		nb;

  nb = 0;
  tmp = game->map[cur->y][cur->x].player;
  while (tmp != NULL)
    {
      tmp = tmp->next;
      nb++;
    }
  if (nb != nb_players[cur->level - 1])
    return (1);
  return (0);
}

static int	test_resources(t_zappy *game, t_player *cur, int resources[7][6])
{
  int		i;

  i = 0;
  while (i < 7)
    {
      if (game->map[cur->y][cur->x].resources[i] !=
	  resources[cur->level - 1][i])
	return (1);
      i++;
    }
  return (0);
}

int	res_incantation(t_zappy *game, t_player *cur)
{
  int	nb_players[7];
  int	resources[7][6];
  char	buff[1024];
  char	buff2[1024];

  memset(buff, 0, 1024);
  memset(buff2, 0, 1024);
  init_nbplayers(nb_players);
  init_resources(resources);
  if (test_players(game, cur, nb_players) == 1 ||
      test_resources(game, cur, resources) == 1)
    {
      add_msg(&cur->client->out, "ko");
      return (0);
    }
  cur->level++;
  sprintf(buff, "Current level: %d", cur->level);
  sprintf(buff2, "plv %d %d", cur->id, cur->level);
  add_msg(&cur->client->out, buff);
  if (game->graphic != NULL)
    add_msg(&game->graphic->out, buff);
  return (0);
}
