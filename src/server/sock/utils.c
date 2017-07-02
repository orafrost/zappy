/*
** utils.c for zappy in /home/kerma/Projets/Epitech/PSU/zappy/src/server/sock
**
** Made by kerma
** Login   <kerma@epitech.net>
**
** Started on  Sat Jul  1 18:15:55 2017 kerma
** Last update Sun Jul  2 05:43:32 2017 kerma
*/

#include "zappy.h"

int	place_end(char buff[])
{
  int	a;

  a = 0;
  while (buff[a] != '\n' && buff[a] != '\0' && a < 1024)
    a += 1;
  if (buff[a] != '\n')
    return (1);
  buff[a] = '\0';
  return (0);
}

void	quit(t_zappy *zappy, t_team **ref, int team_id)
{
  zappy->teams[team_id]->nb--;
  close((*ref)->player->client->fd);
  zappy->map[(*ref)->player->y][(*ref)->player->x].player =
    del_player(zappy->map[(*ref)->player->y][(*ref)->player->x].player,
	       &(*ref)->player);
    zappy->teams[team_id]->players =
      del_team(zappy->teams[team_id]->players, ref);
}

void	add_conn(t_zappy *zappy, char *name)
{
  int	i;

  i = 0;
  while (i < zappy->nb_teams)
    {
      if (strcmp(zappy->teams[i]->name, name) == 0)
	{
	  zappy->teams[i]->max++;
	  return ;
	}
      i++;
    }
}
