/*
** client.c for zappy in /home/kerma/Projets/Epitech/PSU/zappy/src/server/sock
**
** Made by kerma
** Login   <kerma@epitech.net>
**
** Started on  Mon Jun 26 23:47:11 2017 kerma
** Last update Tue Jun 27 21:19:28 2017 kerma
*/

#include "zappy.h"

void	place_end(char buff[])
{
  int  a;

  a = 0;
  while (buff[a] != '\n' && a < 1024)
    a += 1;
  buff[a] = '\0';
}

int	cmd_parser(t_zappy *zappy, t_player *player, char buff[])
{
  int	i;
  char  *temp[2];
  
  i = 0;
  if ((temp[0] = strtok(buff, " ")) == NULL)
    temp[0] = strtok(NULL, "\0");
  temp[1] = strtok(NULL, "\0");
  while (i < NB_CMD)
    {
      if (strcmp(zappy->cmd_name[i], temp[0]) == 0)
	{
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

int		client_read(t_zappy *zappy, t_team **player, int team_id)
{
  char		buff[1024];

  if (*player == NULL)
    return (0);
  memset(buff, 0, 1024);
  if (recv((*player)->player->client->fd, buff, 1024, 0) <= 0)
    {
      zappy->teams[team_id]->nb--;
      close((*player)->player->client->fd);
      zappy->teams[team_id]->players =
	del_elem(zappy->teams[team_id]->players, player);
      return (0);
    }
  place_end(buff);
  if (cmd_parser(zappy, (*player)->player, buff) == ERROR)
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
