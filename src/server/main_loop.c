/*
** main_loop.c for zappy in /home/orafrost/rendu/tek2/psu/zappy/src/server/
**
** Made by Guillaume Verrier
** Login   <verrier_g@epitech.eu>
**
** Started on  Tue Jun 20 15:22:04 2017 Guillaume Verrier
** Last update Sat Jun 24 17:38:33 2017 kerma
*/

#include "zappy.h"

int	g_state = RUN;

void	handler(int sig)
{
  if (sig == SIGINT)
    g_state = STOP;
}

int		main_loop(t_zappy *game)
{
  t_player	*temp;
  /* int		id; */

  /* id = 0; */
  signal(SIGINT, &handler);
  /* temp = create_player(id, UP); */
  if (init_serveur_tcp(game->server, game->nb_teams * game->teams[0]->max,
		       game->port) == 1)
    return (ERROR);
  while (g_state == RUN)
    {
      (void)temp;
      /* if (hand_connection(game->server, temp) == 0) */
      /* 	if (start_echange(game, temp) != -1) */
      /* 	  create_player(++id, UP); */
    }
  close_socket(game->server);
  return (0);
}
