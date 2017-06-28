/*
** zappy.h for zappy in /home/orafrost/rendu/tek2/psu/zappy/include
**
** Made by guillame verrier
** Login   <orafrost@epitech.net>
**
** Started on  Mon Jun  5 15:09:26 2017 guillame verrier
** Last update Wed Jun 28 16:14:34 2017 kerma
*/

#ifndef ZAPPY_H_
# define ZAPPY_H_

# include <math.h>
# include <sys/socket.h>
# include <netinet/in.h>
# include <sys/types.h>
# include <arpa/inet.h>
# include <signal.h>
# include <string.h>
# include <unistd.h>
# include <stdlib.h>
# include <netdb.h>
# include <stdio.h>
# include <time.h>

# include "struct.h"

# define ERROR  (84)
# define STOP   (1)
# define RUN    (0)

extern int      g_state;

void		clean(t_zappy *zappy);
void		free_map(t_zappy *zappy);
void		free_teams(t_zappy *zappy);

void		free_buffer(t_buffer *buffer);
void		del_msg(t_buffer **buffer);
int		add_msg(t_buffer **buffer, char *msg);

int		graphic_read(t_zappy *zappy);
void		graphic_write(t_zappy *zappy);  
int		add_graphic_client(t_zappy *zappy, int fd);

void		place_end(char buff[]);
int		client_read(t_zappy *zappy, t_team **player, int team_id);
void		client_write(t_team *player);

void		clean_waiting(t_zappy *zappy, int fd);
int		read_waitings(t_zappy *zappy, int fd);
void		write_waitings(t_zappy *zappy, int fd);


int		set_fd(t_zappy *zappy);
int		isset_fd(t_zappy *zappy);

int		add_client(t_zappy *zappy);
int		init_server(t_tcp *tcp, int port);

int		main_loop(t_zappy *game);

t_tcp		*init_tcp(t_tcp *tcp, int fd);
t_team		*add_player(t_team **team, int fd);
t_team		*del_elem(t_team *start, t_team **elem);

void		get_vector(t_player *cur, int *vx, int *vy);
void		move_up(t_zappy *game, t_player *cur);
void		turn_right(t_zappy *game, t_player *cur);
void		turn_left(t_zappy *game, t_player *cur);
t_tile		*get_tile(t_zappy *game, int pos[2]);

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

int		intlen(int nb);
int		nb_teams(t_zappy *zappy, t_player *player);
t_teamRoot	*find_team(t_zappy *zappy, t_player *player);

#endif
