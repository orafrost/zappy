/*
** zappy.h for zappy in /home/orafrost/rendu/tek2/psu/zappy/include
**
** Made by guillame verrier
** Login   <orafrost@epitech.net>
**
** Started on  Mon Jun  5 15:09:26 2017 guillame verrier
** Last update Wed Jun 21 15:18:38 2017 Guillaume Verrier
*/

# ifndef ZAPPY_H_
# define ZAPPY_H_

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <time.h>

# define ERROR	(84)

# include "sock.h"

typedef enum	e_dir
  {
    UP = 1,
    RIGHT = 2,
    DOWN = 3,
    LEFT = 4
  }		e_dir;

typedef enum	e_resources
  {
    Food = 0,
    Linemate = 1,
    Deraumere = 2,
    Sibur = 3,
    Mendiane = 4,
    Phiras = 5,
    Thystame = 6
  }		e_resources;

typedef struct	s_action
{
  time_t	start;
  float		dure;
}		t_action;

typedef struct	s_player
{
  int		resources[7];
  int		id;
  int		x;
  int		y;
  t_tcp		*client;
  t_action	action;
  enum e_dir	_dir;
}		t_player;

typedef struct	s_team
{
  t_player	*player;
  struct s_team	*next;
}		t_team;

typedef struct	s_tile
{
  int		resources[7];
  t_team	*player;
}		t_tile;

typedef struct	s_teamRoot
{
  int		nb;
  int		max;
  char		*name;
  t_team	*players;
}		t_teamRoot;

typedef struct	s_zappy
{
  unsigned int	width;
  unsigned int	height;
  t_tcp		*server;
  int    port;
  int		nb_teams;
  int		frequency;
  t_teamRoot	**teams;
  t_tile	**map;
}		t_zappy;

typedef struct	s_args
{
  int		nb;
  int		done[6];
  char		*arg[6];
  void		(*func[6])(t_zappy *, char **, int *, int *);
}		t_args;

void	clean(t_zappy *zappy);

int main_loop(t_zappy *game);
int hand_connection(t_tcp *server, t_player *player);
int start_echange(t_zappy *game, t_player *);

t_player *create_player(int id, enum e_dir dir);
t_team *create_team_node(t_player *player);
t_team *add_elem(t_team *start, t_team *node);
void free_team(t_team *node);
t_team *del_elem(t_team *start, t_team *elem);

int	is_num(char *str);
int	is_set(t_args args);
void	puterr(char *err);
void    usage(FILE *stream, int ret);
void	args(t_zappy *zappy, int ac, char **av);
void    arg_init(t_args *args);
void	arg_port(t_zappy *zappy, char **av, int *i, int *nb);
void	arg_width(t_zappy *zappy, char **av, int *i, int *nb);
void	arg_height(t_zappy *zappy, char **av, int *i, int *nb);
void    arg_names(t_zappy *zappy, char **av, int *i, int *nb);
void	arg_clients(t_zappy *zappy, char **av, int *i, int *nb);
void	arg_freq(t_zappy *zappy, char **av, int *i, int *nb);

#endif
