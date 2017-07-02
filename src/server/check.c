/*
** res.c for zappy in /home/kerma/Projets/Epitech/PSU/zappy/src/server
**
** Made by kerma
** Login   <kerma@epitech.net>
**
** Started on  Fri Jun 30 18:24:20 2017 kerma
** Last update Sun Jul  2 12:00:53 2017 kerma
*/

#include "zappy.h"

void		food_consumption(t_zappy *zappy, t_team **ref)
{
  time_t	delay;
  int		bol;

  bol = 0;
  delay = time(NULL) - (*ref)->player->time;
  while (delay >= zappy->food_conso)
    {
      bol = 1;
      delay -= zappy->food_conso;
      if ((*ref)->player->resources[FOOD] > 0)
	(*ref)->player->resources[FOOD]--;
    }
  if (bol == 1)
    (*ref)->player->time = time(NULL);
}

static int	check_life(t_zappy *zappy, t_team **ref, int team_id)
{
  char		buff[1024];

  food_consumption(zappy, ref);
  if ((*ref)->player->resources[FOOD] == 0)
    {
      memset(buff, 0, 1024);
      sprintf(buff, "pdi %d", (*ref)->player->id);
      if (zappy->graphic != NULL)
	add_msg(&zappy->graphic->out, buff);
      dprintf((*ref)->player->client->fd, "dead\n");
      quit(zappy, ref, team_id);
      return (1);
    }
  return (0);
}

static int	check_action(t_zappy *zappy, t_team *ref)
{
  t_player	*player;
  time_t	delay;

  player = ref->player;
  if (player->action.response != NULL)
    {
      delay = time(NULL) - player->action.start;
      if (delay >= player->action.dure)
	{
	  if ((player->action.response)(zappy, player) == ERROR)
	    return (ERROR);
	  player->action.dure = 0;
	  player->action.start = 0;
	  player->action.response = NULL;
	}
    }
  return (0);
}

static t_egg	*check_eggs(t_zappy *zappy)
{
  t_egg		*tmp;
  time_t	delay;
  char		buff[1024];

  tmp = zappy->eggs;
  while (tmp != NULL)
    {
      delay = time(NULL) - tmp->start;
      if (tmp->start != 0 && delay >= (600 / zappy->frequency))
	{
	  memset(buff, 0, 1024);
	  sprintf(buff, "eht %d", tmp->id);
	  if (zappy->graphic != NULL)
	    add_msg(&zappy->graphic->out, buff);
	  add_conn(zappy, tmp->team);
	  tmp->start = 0;
	}
      tmp = tmp->next;
    }
  return (zappy->eggs);
}

int		check_players(t_zappy *zappy)
{
  t_team	*tmp;
  int		ret;
  int		i;

  i = 0;
  while (i < zappy->nb_teams)
    {
      tmp = zappy->teams[i]->players;
      while (tmp != NULL)
	{
	  if ((ret = check_life(zappy, &tmp, i)) == ERROR)
	    return (ERROR);
	  if (ret == 0 && check_action(zappy, tmp) == ERROR)
	    return (ERROR);
	  if (tmp != NULL)
	    tmp = tmp->next;
	}
      i++;
    }
  zappy->eggs = check_eggs(zappy);
  return (0);
}
