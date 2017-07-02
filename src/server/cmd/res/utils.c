/*
** utils.c for zappy in /home/kerma/Projets/Epitech/PSU/zappy/src/server/cmd/res
**
** Made by kerma
** Login   <kerma@epitech.net>
**
** Started on  Sat Jul  1 01:51:46 2017 kerma
** Last update Sun Jul  2 19:41:11 2017 kerma
*/

#include "zappy.h"

void	get_vector(t_player *cur, int *vx, int *vy)
{
  if (cur->_dir == UP)
    {
      *vx = 0;
      *vy = -1;
    }
  else if (cur->_dir == RIGHT)
    {
      *vx = 1;
      *vy = 0;
    }
  else if (cur->_dir == DOWN)
    {
      *vx = 0;
      *vy = 1;
    }
  else
    {
      *vx = -1;
      *vy = 0;
    }
}

t_tile	*get_tile(t_zappy *game, int pos[2])
{
  if (pos[0] < 0)
    pos[0] = game->width - pos[0];
  if ((unsigned int)pos[0] >= game->width)
    pos[0] = pos[0] - game->width;
  if (pos[1] < 0)
    pos[1] = game->height - pos[1];
  if ((unsigned int)pos[1] >= game->height)
    pos[1] = pos[1] - game->height;
  return (game->map[pos[1]] + pos[0]);
}

int	find_resource(char *resource)
{
  char	*list[7];
  int	i;

  i = 0;
  list[0] = "food";
  list[1] = "linemate";
  list[2] = "deraumere";
  list[3] = "sibur";
  list[4] = "mendiane";
  list[5] = "phiras";
  list[6] = "thystame";
  while (i < 7)
    {
      if (strcmp(resource, list[i]) == 0)
	return (i);
      i++;
    }
  return (WRONG_RESOURCE);
}

t_teamRoot	*find_team(t_zappy *zappy, t_player *player)
{
  t_team	*tmp;
  int		i;

  i = 0;
  while (zappy->teams[i] != NULL)
    {
      tmp = zappy->teams[i]->players;
      while (tmp != NULL)
	{
	  if (tmp->player == player)
	    return (zappy->teams[i]);
	  tmp = tmp->next;
	}
      i++;
    }
  return (NULL);
}
