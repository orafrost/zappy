/*
** free.c for zappy in /home/kerma/Projets/Epitech/PSU/zappy/src/server
**
** Made by kerma
** Login   <kerma@epitech.net>
**
** Started on  Wed Jun 21 13:40:12 2017 kerma
** Last update Sun Jul  2 05:45:17 2017 kerma
*/

#include "zappy.h"

void		free_map(t_zappy *zappy)
{
  size_t	i;
  size_t	j;

  i = 0;
  while (i < zappy->height)
    {
      if (zappy->map[i] != NULL)
	{
	  j = 0;
	  while (j < zappy->width)
	    {
	      while (zappy->map[i][j].player != NULL)
		zappy->map[i][j].player =
		  del_player(zappy->map[i][j].player,
			     &zappy->map[i][j].player->player);
	      j++;
	    }
	  free(zappy->map[i]);
	}
      i++;
    }
  if (zappy->map != NULL)
    free(zappy->map);
}

void	free_teams(t_zappy *zappy)
{
  int	i;

  i = 0;
  while (i < zappy->nb_teams)
    {
      if (zappy->teams[i]->players != NULL)
      	{
	  while (zappy->teams[i]->players != NULL)
	    zappy->teams[i]->players = del_team(zappy->teams[i]->players,
						&zappy->teams[i]->players);
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

void	free_eggs(t_zappy *zappy)
{
  while (zappy->eggs != NULL)
    zappy->eggs = del_egg(zappy->eggs, &zappy->eggs);
}

void	clean(t_zappy *zappy)
{
  int	i;

  i = 0;
  if (zappy->server != NULL)
    free(zappy->server);
  if (zappy->teams != NULL)
    free_teams(zappy);
  if (zappy->map != NULL)
    free_map(zappy);
  if (zappy->eggs != NULL)
    free_eggs(zappy);
  if (zappy->graphic != NULL)
    {
      free_buffer(zappy->graphic->out);
      free(zappy->graphic);
    }
  while (i < MAX)
    {
      if (zappy->waiting[i] != NULL)
	{
	  free_buffer(zappy->waiting[i]->out);
	  free(zappy->waiting[i]);
	}
      i++;
    }
}
