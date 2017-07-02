/*
** look_misc.c for zappy in /home/kerma/Projets/Epitech/PSU/zappy/src/server/cmd/res
**
** Made by kerma
** Login   <kerma@epitech.net>
**
** Started on  Sat Jul  1 15:58:48 2017 kerma
** Last update Sat Jul  1 16:20:27 2017 kerma
*/

#include "zappy.h"

void	init_tab(char *name[])
{
  name[0] = "food";
  name[1] = "linemate";
  name[2] = "deraumere";
  name[3] = "sibur";
  name[4] = "mendiane";
  name[5] = "phiras";
  name[6] = "thystame";
}

static int	concat_resources(t_tile *tile, char buff[], int *init)
{
  char		*name[7];
  int		var[2];

  var[0] = 0;
  init_tab(name);
  while (var[0] < 7)
    {
      var[1] = 0;
      while (var[1] < tile->resources[var[0]])
	{
	  if (*init != 0 && strcat(buff, " ") == NULL)
	    return (puterr("Function \'strcat\' failed."));
	  *init = 1;
	  if (strcat(buff, name[var[0]]) == NULL)
	    return (puterr("Function \'strcat\' failed."));
	  var[1] += 1;
	}
      var[0] += 1;
    }
  return (0);
}

static int	set_player(t_tile *tile, char buff[], int *init)
{
  t_team	*tmp;

  tmp = tile->player;
  while (tmp != NULL)
    {
      if (*init != 0 && strcat(buff, " ") == NULL)
	return (puterr("Function \'strcat\' failed."));
      *init = 1;
      if (strcat(buff, "player") == NULL)
	return (puterr("Function \'strcat\' failed."));
      tmp = tmp->next;
    }
  return (0);
}

int	send_look(t_tile **vis, t_player *cur, int len)
{
  char	buff[4096 * len];
  int	init;
  int	a;

  a = 0;
  init = 0;
  memset(buff, 0, 4096 * len);
  buff[0] = '[';
  while (a < len)
    {
      if (set_player(vis[a], buff, &init) == ERROR)
	return (ERROR);
      if (concat_resources(vis[a], buff, &init) == ERROR)
	return (ERROR);
      a += 1;
      if (a != len && strcat(buff, ",") == NULL)
	return (puterr("Function \'strcat\' failed."));
    }
  if (strcat(buff, "]") == NULL)
    return (puterr("Function \'strcat\' failed."));
  add_msg(&cur->client->out, buff);
  return (0);
}
