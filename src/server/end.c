/*
** end.c for zappy in /home/kerma/Projets/Epitech/PSU/zappy/src/server
**
** Made by kerma
** Login   <kerma@epitech.net>
**
** Started on  Sun Jul  2 05:56:38 2017 kerma
** Last update Sun Jul  2 06:03:00 2017 kerma
*/

#include "zappy.h"

int     g_state;

void		end_game(t_zappy *zappy)
{
  t_team	*tmp;
  int		i;

  i = 0;
  while (i < zappy->nb_teams)
    {
      tmp = zappy->teams[i]->players;
      while (tmp != NULL)
	{
	  if (tmp->player->level == 8)
	    {
	      printf("The winner is team: %s\n", zappy->teams[i]->name);
	      if (zappy->graphic != NULL)
		dprintf(zappy->graphic->fd, "seg %s\n",
			zappy->teams[i]->name);
	      g_state = STOP;
	      return ;
	    }
	  tmp = tmp->next;
	}
      i++;
    }
}
