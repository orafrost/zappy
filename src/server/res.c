/*
** res.c for zappy in /home/kerma/Projets/Epitech/PSU/zappy/src/server
**
** Made by kerma
** Login   <kerma@epitech.net>
**
** Started on  Fri Jun 30 18:24:20 2017 kerma
** Last update Fri Jun 30 19:16:21 2017 kerma
*/

#include "zappy.h"

int		check_players_action(t_zappy *zappy)
{
  t_team        *tmp;
  int           i;

  i = 0;
  while (i < zappy->nb_teams)
    {
      tmp = zappy->teams[i]->players;
      while (tmp != NULL)
	{
	  if (tmp->action.response != NULL &&
	      time(NULL) - tmp->action.start >= tmp->action.dure)
	    {
	      if((tmp->action.response)(zappy, tmp) == ERROR)
		return (ERROR);
	      tmp->action.response = NULL;
	    }
	  tmp = tmp->next;
	}
      i++;
    }
  return (0);
}
