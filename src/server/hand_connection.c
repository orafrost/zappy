/*
** hand_connection.c for zappy in /home/orafrost/rendu/tek2/psu/zappy/src/server/
**
** Made by Guillaume Verrier
** Login   <verrier_g@epitech.eu>
**
** Started on  Tue Jun 20 14:30:24 2017 Guillaume Verrier
** Last update Sat Jun 24 17:21:40 2017 kerma
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
  while (a < game->nb_teams)
  {
    if (strcmp(game->teams[a]->name, buff) == 0)
    {
      if (game->teams[a]->nb > game->teams[a]->max)
        return (NULL);
      game->teams[a]->nb += 1;
      return (game->teams[a]);
    }
    a += 1;
  }
  return (NULL);
}

int start_echange(t_zappy *game, t_player *new)
{
  char buff[1024];
  t_teamRoot *team;

  if (send(new->client->socket, "WELCOME\n", 8, 0) < 0)
    return (-1);
  if (recv(new->client->socket, buff, 1024, 0) < 0)
    return (-1);
  place_end(buff);
  if ((team = place_team(buff, game)) == NULL)
  {
    if (send(new->client->socket, "KO\n", 4, 0) < 0)
      return (-1);
  }
  team->players = add_elem(team->players, create_team_node(new));
  sprintf(buff, "%d\n", new->id);
  if (send(new->client->socket, buff, strlen(buff), 0) < 0)
    return (-1);
  sprintf(buff, "%d %d\n", game->width, game->height);
  if (send(new->client->socket, buff, strlen(buff), 0) < 0)
    return (-1);
  return (0);
}
