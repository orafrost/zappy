/*
** hand_connection.c for zappy in /home/orafrost/rendu/tek2/psu/zappy/src/server/
**
** Made by Guillaume Verrier
** Login   <verrier_g@epitech.eu>
**
** Started on  Tue Jun 20 14:30:24 2017 Guillaume Verrier
** Last update Tue Jun 20 17:05:53 2017 Guillaume Verrier
*/

#include "zappy.h"

int hand_connection(t_tcp *server, t_player *player)
{
  if (connect_client(player->client, server) == 1)
    return (-1);
  return (0);
}

void place_end(char buff[])
{
  int  a;

  a = 0;
  while (buff[a] != '\n' && a < 1024)
  {
    a += 1;
  }
  buff[a] = '\0';
}

t_teamRoot *place_team(char buff[], t_zappy *game)
{
  int  a;

  a = 0;
  while (a < nb_teams)
  {
    if (strcmp(games->teams[a]->name, buff) == 0)
    {
      if (games->teams[a]->nb > games->teams[a]->max)
        return (NULL);
      games->teams[a]->nb += 1;
      return (games->teams[a]);
    }
    a += 1;
  }
  return (NULL);
}

int start_echange(t_zappy *game, t_player *new)
{
  char buff[1024];
  t_teamRoot *team;
  int  a;

  if (send(new->cient, "WELCOME\n", 8, 0) < 0)
    return (-1);
  if (recv(new->client, buff, 1024, 0) < 0)
    return (NULL);
  place_end(buff);
  if ((team = find_team(buff, game)) == NULL)
  {
    if (send(new->cient, "KO\n", 4, 0) < 0)
      return (-1);
  }
  team->player = add_elem(team->player, create_team_node(team->player, new));
  sprintf(buff, "%d\n", new->id);
  if (send(new->cient, buff, strlen(buff), 0) < 0)
    return (-1);
  sprintf(buff, "%d %d\n", games->width, games->height);
  if (send(new->cient, buff, strlen(buff), 0) < 0)
    return (-1);
}
