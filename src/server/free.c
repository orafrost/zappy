/*
** free.c for zappy in /home/kerma/Projets/Epitech/PSU/zappy/src/server
**
** Made by kerma
** Login   <kerma@epitech.net>
**
** Started on  Wed Jun 21 13:40:12 2017 kerma
** Last update Wed Jun 21 13:41:34 2017 kerma
*/

#include "zappy.h"

void		free_map(t_zappy *zappy)
{
  size_t	i;

  i = 0;
  while (i < zappy->height)
    {
      if (zappy->map[i] != NULL)
	free(zappy->map[i]);
      i++;
    }
  if (zappy->map != NULL)
    free(zappy->map);
}

void	free_teams(t_zappy * zappy)
{
  int	i;

  i = 0;
  while (i < zappy->nb_teams)
    {
      if (zappy->teams[i]->name != NULL)
	free(zappy->teams[i]->name);
      // TODO free_team(zappy->teams[i]->players)
      if (zappy->teams[i] != NULL)
	free(zappy->teams[i]);
      i++;
    }
  if (zappy->teams != NULL)
    free(zappy->teams);
}

void	clean(t_zappy *zappy)
{
  if (zappy->server != NULL)
    free(zappy->server);
  if (zappy->teams != NULL)
    free_teams(zappy);
  if (zappy->map != NULL)
    free_map(zappy);
}
