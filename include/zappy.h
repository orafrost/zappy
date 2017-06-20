/*
** zappy.h for zappy in /home/orafrost/rendu/tek2/psu/zappy/include
**
** Made by guillame verrier
** Login   <orafrost@epitech.net>
**
** Started on  Mon Jun  5 15:09:26 2017 guillame verrier
** Last update Mon Jun  5 15:42:20 2017 guillame verrier
*/

# ifndef ZAPPY_H_
# define ZAPPY_H_

enum e_dir
  {
    UP = 1, RIGHT = 2, DOWN = 3, LEFT = 4
  };

enum e_resources
  {
    Food = 0, Linemate = 1, Deraumere = 2,
    Sibur = 3, Mendiane = 4, Phiras = 5, Thystame = 6
  };

typedef struct s_player
{
  int resources[7];
  int id;
  enum e_dir _dir;
}		t_player;

typedef struct  s_team
{
  t_player	    *player;
  struct s_team *next;
}		t_team;

typedef struct s_tile
{
  int    resources[7];
  t_team *player;
}	             t_tile;

typedef struct s_teamRoot
{
  char		*name;
  t_team	*players;
}		t_teamRoot;

typedef struct s_zappy
{
  unsigned int width;
  unsigned int height;
  int          nb_teams;
  float        frequency;
  t_teamRoot   **teams;
  t_tile       **map;
}		t_zappy;

#endif