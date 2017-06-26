/*
** free.c for zappy in /home/kerma/Projets/Epitech/PSU/zappy/src/server
**
** Made by kerma
** Login   <kerma@epitech.net>
**
** Started on  Wed Jun 21 13:40:12 2017 kerma
** Last update Mon Jun 26 15:47:22 2017 kerma
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

void		free_teams(t_zappy *zappy)
{
  /* t_team	*elem; */
  int		i;

  i = 0;
  while (i < zappy->nb_teams)
    {
      if (zappy->teams[i]->players != NULL)
      	{
	  while (zappy->teams[i]->players != NULL)
	    zappy->teams[i]->players = del_elem(zappy->teams[i]->players,
						zappy->teams[i]->players);
      	}
      if (zappy->teams[i]->name != NULL)
	free(zappy->teams[i]->name);
      if (zappy->teams[i] != NULL)
	free(zappy->teams[i]);
      i++;
    }
  if (zappy->teams != NULL)
    free(zappy->teams);
  zappy->teams = NULL;
  zappy->nb_teams = 0;
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
