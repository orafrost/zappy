/*
** zappy.h for zappy in /home/orafrost/rendu/tek2/psu/zappy/include
**
** Made by guillame verrier
** Login   <orafrost@epitech.net>
**
** Started on  Mon Jun  5 15:09:26 2017 guillame verrier
** Last update Sat Jun 24 17:07:08 2017 kerma
*/

# ifndef ZAPPY_H_
# define ZAPPY_H_

# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <signal.h>
# include <stdio.h>
# include <time.h>

# include "sock.h"

# define ERROR	(84)
# define STOP   (1)
# define RUN    (0)

extern int      g_state;

typedef enum	e_dir
  {
    UP		= 1,
    RIGHT	= 2,
    DOWN	= 3,
    LEFT	= 4
  }		e_dir;

typedef enum	e_resources
  {
    FOOD	= 0,
    LINEMATE	= 1,
    DERAUMERE	= 2,
    SIBUR	= 3,
    MENDIANE	= 4,
    PHIRAS	= 5,
    THYSTAME	= 6
  }		e_resources;

typedef enum	e_action
  {
    MOVE	= 0,
    TURN_RIGHT	= 1,
    TURN_LEFT	= 2,
    LOOK	= 3,
    INVENTORY	= 4,
    BROADCAST	= 5,
    NB_TEAMS	= 6,
    FORK	= 7,
    EJECT	= 8,
    DEATH	= 9,
    TAKE	= 10,
    SET		= 11,
    START	= 12    
  }		e_action;

typedef struct	s_action
{
  e_action	action;
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
  int		port;
  int		nb_teams;
  int		frequency;
  t_teamRoot	**teams;
  t_tile	**map;
}		t_zappy;

typedef struct	s_args
{
  int		nb;
  char		*arg[6];
  int		(*func[6])(t_zappy *, char **, int *, int *);
}		t_args;

void		clean(t_zappy *zappy);
void		free_map(t_zappy *zappy);
void		free_teams(t_zappy *zappy);

int		main_loop(t_zappy *game);
int		hand_connection(t_tcp *server, t_player *player);
int		start_echange(t_zappy *game, t_player *);

t_player	*create_player(int id, enum e_dir dir);
t_team		*create_team_node(t_player *player);
t_team		*add_elem(t_team *start, t_team *node);
void		free_team(t_team *node);
t_team		*del_elem(t_team *start, t_team *elem);

void		usage();
int		is_num(char *str);
int		puterr(char *err);
void		*pputerr(char *err);
int		args(t_zappy *zappy, int ac, char **av);
int		arg_port(t_zappy *zappy, char **av, int *i, int *nb);
int		arg_width(t_zappy *zappy, char **av, int *i, int *nb);
int		arg_height(t_zappy *zappy, char **av, int *i, int *nb);
int		arg_names(t_zappy *zappy, char **av, int *i, int *nb);
int		arg_clients(t_zappy *zappy, char **av, int *i, int *nb);
int		arg_freq(t_zappy *zappy, char **av, int *i, int *nb);
void		arg_init(t_args *args);
int		map_init(t_zappy *zappy);
int		default_init(t_zappy *zappy);
t_teamRoot	*team_init(char *name);

#endif
