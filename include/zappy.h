/*
** zappy.h for zappy in /home/orafrost/rendu/tek2/psu/zappy/include
**
** Made by guillame verrier
** Login   <orafrost@epitech.net>
**
** Started on  Mon Jun  5 15:09:26 2017 guillame verrier
** Last update Sun Jul  2 20:03:29 2017 kerma
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
# include <math.h>

# include "struct.h"

# define ERROR  (84)
# define STOP   (1)
# define RUN    (0)

extern int      g_state;

void		clean(t_zappy *zappy);
void		free_map(t_zappy *zappy);
void		free_teams(t_zappy *zappy);
void		free_buffer(t_buffer *buffer);

void		add_conn(t_zappy *zappy, char *name);
void		quit(t_zappy *zappy, t_team **ref, int team_id);
int		graphic_read(t_zappy *zappy);
void		graphic_write(t_zappy *zappy);
int		add_graphic_client(t_zappy *zappy, int fd);
int		place_end(char buff[]);
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
int		check_players(t_zappy *zappy);
void		end_game(t_zappy *zappy);

void		del_msg(t_buffer **buffer);
int		add_msg(t_buffer **buffer, char *msg);
t_tcp		*init_tcp(t_tcp *tcp, int fd);
t_team		*add_team(t_zappy *zappy, t_team **team, int fd);
t_team		*del_team(t_team *start, t_team **elem);
int		add_player(t_team **team, t_player *player);
t_team		*del_player(t_team *start, t_player **elem);
t_egg		*add_egg(t_egg **eggs, char *team, int y, int x);
t_egg		*del_egg(t_egg *start, t_egg **elem);
void		use_egg(t_zappy *zappy, t_team **new, int team_id);

int		cmd_set(t_zappy *game, t_player *cur);
int		cmd_take(t_zappy *game, t_player *cur);
int		cmd_fork(t_zappy *game, t_player *cur);
int		cmd_look(t_zappy *game, t_player *cur);
int		cmd_left(t_zappy *game, t_player *cur);
int		cmd_right(t_zappy *game, t_player *cur);
int		cmd_eject(t_zappy *game, t_player *cur);
int		cmd_forward(t_zappy *game, t_player *cur);
int		cmd_inventory(t_zappy *game, t_player *cur);
int		cmd_broadcast(t_zappy *zappy, t_player *player);
int		cmd_incantation(t_zappy *game, t_player *cur);
int		cmd_connect_nbr(t_zappy *zappy, t_player *player);

int		res_set(t_zappy *game, t_player *cur);
int		res_take(t_zappy *game, t_player *cur);
int		res_look(t_zappy *game, t_player *cur);
int		res_left(t_zappy *game, t_player *cur);
int		res_fork(t_zappy *game, t_player *cur);
int		res_right(t_zappy *game, t_player *cur);
int		res_eject(t_zappy *game, t_player *cur);
int		res_forward(t_zappy *game, t_player *cur);
int		res_inventory(t_zappy *game, t_player *cur);
int		res_broadcast(t_zappy *game, t_player *cur);
int		res_incantation(t_zappy *game, t_player *cur);

int		get_k_eject(t_player *cur, t_player *tmp);

void		send_map(t_zappy *zappy);
void		send_teams(t_zappy *zappy);
void		send_players(t_zappy *zappy);
void		send_eggs(t_zappy *zappy);

void		init_nbplayers(int nb_players[]);
void		init_resources(int resources[7][6]);
t_teamRoot	*find_team(t_zappy *zappy, t_player *player);
int		send_look(t_tile **vis, t_player *cur, int len);
int		find_resource(char *resource);
void		get_vector(t_player *cur, int *vx, int *vy);
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

#endif
