/*
** main_loop.c for zappy in /home/orafrost/rendu/tek2/psu/zappy/src/server/
**
** Made by Guillaume Verrier
** Login   <verrier_g@epitech.eu>
**
** Started on  Tue Jun 20 15:22:04 2017 Guillaume Verrier
** Last update Fri Jun 30 18:06:34 2017 kerma
*/

#include "zappy.h"

int	g_state;

void		close_all(t_zappy *zappy)
{
  t_team	*team;
  int		i;

  i = 0;
  while (i < zappy->nb_teams)
    {
      team = zappy->teams[i]->players;
      while (team != NULL)
	{
	  close(team->player->client->fd);
	  team = team->next;
	}
      i++;
    }
  i = 0;
  while (i < MAX)
    {
      if (zappy->waiting[i] != NULL)
	close(zappy->waiting[i]->fd);
      i++;
    }
  close(zappy->server->fd);
}

int	main_loop(t_zappy *zappy)
{
  int	max;
  int	ret;

  ret = 0;
  while (g_state == RUN)
    {
      // TODO delete
      /* t_team *tmp; */
      /* int i = 0; */
      /* while (i < zappy->nb_teams) */
      /* 	{ */
      /* 	  tmp = zappy->teams[i]->players; */
      /* 	  printf("%s\n", zappy->teams[i]->name); */
      /* 	  while (tmp != NULL) */
      /* 	    { */
      /* 	      printf("  %d\n", tmp->player->client->fd); */
      /* 	      tmp = tmp->next; */
      /* 	    } */
      /* 	  i++; */
      /* 	} */
      /* printf("------------------------\n\n"); */

      FD_ZERO(&zappy->fd_read);
      FD_ZERO(&zappy->fd_write);
      max = set_fd(zappy);
      if (select(max + 1, &zappy->fd_read, &zappy->fd_write, NULL, NULL) == -1)
	{
	  ret = ERROR;
	  g_state = STOP;
	}
      else if (isset_fd(zappy) == ERROR)
	{
	  ret = ERROR;
	  g_state = STOP;
	}
      
    }
  close_all(zappy);
  return (ret);
}
