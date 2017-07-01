/*
** client.c for zappy in /home/kerma/Projets/Epitech/PSU/zappy/src/server/sock
**
** Made by kerma
** Login   <kerma@epitech.net>
**
** Started on  Mon Jun 26 23:47:11 2017 kerma
** Last update Sat Jul  1 18:19:10 2017 kerma
*/

#include "zappy.h"

static int	cmd_parser(t_zappy *zappy, t_player *player, char buff[])
{
  int		i;
  char		*temp[2];
  
  i = 0;
  if ((temp[0] = strtok(buff, " ")) == NULL)
    if ((temp[0] = strtok(NULL, "\0")) == NULL)
      {
	add_msg(&player->client->out, "ko");
	return (0);
      }
  temp[1] = strtok(NULL, "\0");
  while (player->action.response == NULL && i < NB_CMD)
    {
      if (strcmp(zappy->cmd_name[i], temp[0]) == 0)
	{
	  player->action.start = time(NULL);
	  player->action.arg = temp[1];
	  if (zappy->cmd[i](zappy, player) == ERROR)
	    return (ERROR);
	  return (0);
	}
      i++;
    }
  add_msg(&player->client->out, "ko");
  return (0);
}

static int	cmd_split(t_zappy *zappy, t_team **ref, char buff[])
{
  char		*temp;

  if ((temp = strtok(buff, "\n")) == NULL)
    add_msg(&(*ref)->player->client->out, "ko");
  else
    {
      if (place_end(temp) == 1)
	add_msg(&(*ref)->player->client->out, "ko");
      else if (cmd_parser(zappy, (*ref)->player, temp) == ERROR)
	return (ERROR);
      while ((temp = strtok(NULL, "\n")) != NULL)
	{
	  if (place_end(temp) == 1)
	    add_msg(&(*ref)->player->client->out, "ko");
	  else if (cmd_parser(zappy, (*ref)->player, temp) == ERROR)
	    return (ERROR);
	}
    }
  return (0);
}

int		client_read(t_zappy *zappy, t_team **ref, int team_id)
{
  char		buff[1024];

  if (*ref == NULL)
    return (0);
  memset(buff, 0, 1024);
  if ((*ref)->player->client->init == 0)
    {
      (*ref)->player->client->init = 1;
      return (0);
    }
  if (recv((*ref)->player->client->fd, buff, 1024, 0) <= 0)
    {
      quit(zappy, ref, team_id);
      return (0);
    }  
  if (cmd_split(zappy, ref, buff) == ERROR)
    return (ERROR);
  return (0);
}

void		client_write(t_team *player)
{
  t_tcp		*conn;

  conn = player->player->client;
  if (player != NULL && conn->out != NULL)
    {
      dprintf(conn->fd, "%s\n", conn->out->msg);
      del_msg(&conn->out);
    }
}
