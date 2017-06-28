/*
** struct.h for zappy in /home/kerma/Projets/Epitech/PSU/zappy/include
**
** Made by kerma
** Login   <kerma@epitech.net>
**
** Started on  Mon Jun 26 20:39:26 2017 kerma
** Last update Wed Jun 28 15:19:26 2017 kerma
*/

#ifndef STRUCT_H_
# define STRUCT_H_

# define MAX    (1024)
# define NB_CMD	(1)

typedef struct	s_player	t_player;
typedef struct	s_zappy		t_zappy;

typedef int	(*cmds)(t_zappy *, t_player *);
typedef int	(*func_ptr)(t_zappy *, char **, int *, int *);

typedef enum	e_dir
  {
    UP		= 0,
    RIGHT	= 1,
    DOWN	= 2,
    LEFT	= 3
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

typedef struct		s_buffer
{
  char			*msg;
  struct s_buffer	*next;
}			t_buffer;

typedef struct	s_tcp
{
  int		fd;
  int		init;
  t_buffer	*out;
}		t_tcp;

typedef struct	s_action
{
  e_action	action;
  char          *arg;
  time_t	start;
  float		dure;
}		t_action;

typedef struct	s_player
{
  int		resources[7];
  int		level;
  int		x;
  int		y;
  t_tcp		*client;
  t_action	action;
  e_dir		_dir;
}		t_player;

typedef struct	s_team
{
  t_player	*player;
  struct s_team	*next;
}		t_team;

typedef struct	s_teamRoot
{
  int		nb;
  int		max;
  char		*name;
  t_team	*players;
}		t_teamRoot;

typedef struct	s_tile
{
  int		resources[7];
  t_team	*player;
}		t_tile;

typedef struct	s_zappy
{
  unsigned int	width;
  unsigned int	height;
  int		port;
  int		nb_teams;
  int		frequency;
  t_teamRoot	**teams;
  t_tile	**map;
  t_tcp		*server;
  t_tcp		*graphic;
  t_tcp		*waiting[MAX];
  fd_set	fd_read;
  fd_set	fd_write;
  cmds		cmd[NB_CMD];
  char		*cmd_name[NB_CMD];
}		t_zappy;

typedef struct	s_args
{
  int		nb;
  char		*arg[6];
  func_ptr	func[6];
}		t_args;

#endif
