##
## Makefile for zappy in /home/kerma/Projets/Epitech/PSU/zappy/src/server
##
## Made by kerma
## Login   <kerma@epitech.net>
##
## Started on  Tue Jun 20 14:17:36 2017 kerma
## Last update Sun Jul  2 07:27:43 2017 kerma
##

NAME	= zappy_server

SRCS	= main.c			\
	end.c				\
	egg.c				\
	team.c				\
	free.c				\
	player.c			\
	check.c				\
	main_loop.c			\
	init/misc.c			\
	init/init.c			\
	init/args.c			\
	init/arg1.c			\
	init/arg2.c			\
	sock/sock.c			\
	sock/wait.c			\
	sock/utils.c			\
	sock/fd_set.c			\
	sock/fd_isset.c			\
	sock/buffer.c			\
	sock/client.c			\
	sock/graphic.c			\
	sock/graphic_misc.c		\
	cmd/init/connect_nbr.c		\
	cmd/init/incantation.c		\
	cmd/init/inventory.c		\
	cmd/init/broadcast.c		\
	cmd/init/forward.c		\
	cmd/init/eject.c		\
	cmd/init/right.c		\
	cmd/init/left.c			\
	cmd/init/look.c			\
	cmd/init/take.c			\
	cmd/init/fork.c			\
	cmd/init/set.c			\
	cmd/res/incantation_misc.c	\
	cmd/res/incantation.c		\
	cmd/res/inventory.c		\
	cmd/res/broadcast.c		\
	cmd/res/look_misc.c		\
	cmd/res/forward.c		\
	cmd/res/eject.c			\
	cmd/res/utils.c			\
	cmd/res/right.c			\
	cmd/res/left.c			\
	cmd/res/take.c			\
	cmd/res/look.c			\
	cmd/res/fork.c			\
	cmd/res/set.c

OBJS	= $(SRCS:.c=.o)

CFLAGS	+= -W			\
	-Wall			\
	-Werror			\
	-Wextra			\
	-I../../include

all: $(NAME)

$(NAME): $(OBJS)
	gcc -o $(NAME) $(OBJS) -lm

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
