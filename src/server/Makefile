##
## Makefile for zappy in /home/kerma/Projets/Epitech/PSU/zappy/src/server
##
## Made by kerma
## Login   <kerma@epitech.net>
##
## Started on  Tue Jun 20 14:17:36 2017 kerma
## Last update Sat Jul  1 18:16:49 2017 kerma
##

NAME	= zappy_server

SRCS	= main.c		\
	team.c			\
	free.c			\
	player.c		\
	check.c			\
	main_loop.c		\
	init/misc.c		\
	init/init.c		\
	init/args.c		\
	init/arg1.c		\
	init/arg2.c		\
	sock/sock.c		\
	sock/wait.c		\
	sock/utils.c		\
	sock/fd_set.c		\
	sock/fd_isset.c		\
	sock/buffer.c		\
	sock/client.c		\
	sock/graphic.c		\
	cmd/init/connect_nbr.c	\
	cmd/init/inventory.c	\
	cmd/init/broadcast.c	\
	cmd/init/forward.c	\
	cmd/init/right.c	\
	cmd/init/left.c		\
	cmd/init/look.c		\
	cmd/init/take.c		\
	cmd/init/set.c		\
	cmd/res/inventory.c	\
	cmd/res/broadcast.c	\
	cmd/res/look_misc.c	\
	cmd/res/forward.c	\
	cmd/res/utils.c		\
	cmd/res/right.c		\
	cmd/res/left.c		\
	cmd/res/take.c		\
	cmd/res/look.c		\
	cmd/res/set.c

OBJS	= $(SRCS:.c=.o)

CFLAGS	+= -W			\
	-Wall			\
	-Werror			\
	-Wextra			\
	-I../../include		\
	-g3

all: $(NAME)

$(NAME): $(OBJS)
	gcc -o $(NAME) $(OBJS) -lm

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
