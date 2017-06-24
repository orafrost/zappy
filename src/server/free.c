/*
** free.c for zappy in /home/kerma/Projets/Epitech/PSU/zappy/src/server
**
** Made by kerma
** Login   <kerma@epitech.net>
**
** Started on  Wed Jun 21 13:40:12 2017 kerma
** Last update Sat Jun 24 17:38:45 2017 kerma
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
  t_team	*elem;
  int		i;

  i = 0;
  while (i < zappy->nb_teams)
    {
      // TODO
      /* if (zappy->teams[i]->players) */
      /* 	{ */
      /* 	  while (zappy->teams[i]->players != NULL) */
      /* 	    { */
      /* 	      elem = zappy->teams[i]->players; */
      /* 	      zappy->teams[i]->players = zappy->teams[i]->players->next; */
      /* 	      free_team(elem); */
      /* 	    } */
      /* 	} */
      if (zappy->teams[i]->name != NULL)
	free(zappy->teams[i]->name);
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
