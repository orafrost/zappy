/*
** client.c for zappy in /home/kerma/Projets/Epitech/PSU/zappy/src/server/sock
**
** Made by kerma
** Login   <kerma@epitech.net>
**
** Started on  Mon Jun 26 23:47:11 2017 kerma
** Last update Tue Jun 27 19:12:00 2017 kerma
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

int	client_read(t_zappy *zappy, t_team **c, int team_id)
{
  char	buff[1024];

  (void)zappy;
  if (*c == NULL)
    return (0);
  memset(buff, 0, 1024);
  if (recv((*c)->player->client->fd, buff, 1024, 0) <= 0)
    {
      close((*c)->player->client->fd);
      zappy->teams[team_id]->players = del_elem(zappy->teams[team_id]->players, c);
      return (0);
    }
  place_end(buff);
  if (cmd_parser(zappy, (*c)->player, buff) == ERROR)
    return (ERROR);
  return (0);
}

int	client_write(t_zappy *zappy, t_team **c, int team_id)
{
  (void)zappy;
  (void)team_id;
  // TODO identify cmd with more than one line and send all necessary lines
  if (*c != NULL && (*c)->player->client->out != NULL)
    {
      dprintf((*c)->player->client->fd, "%s\n", (*c)->player->client->out->msg);
      del_msg(&(*c)->player->client->out);
    }
  return (0);
}
