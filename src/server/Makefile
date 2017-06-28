##
## Makefile for zappy in /home/kerma/Projets/Epitech/PSU/zappy/src/server
##
## Made by kerma
## Login   <kerma@epitech.net>
##
## Started on  Tue Jun 20 14:17:36 2017 kerma
## Last update Wed Jun 28 16:05:24 2017 kerma
##

NAME	= zappy_server

SRCS	= main.c		\
	list.c			\
	free.c			\
	main_loop.c		\
	init/misc.c		\
	init/init.c		\
	init/args.c		\
	init/arg1.c		\
	init/arg2.c		\
	sock/sock.c		\
	sock/wait.c		\
	sock/fd_set.c		\
	sock/fd_isset.c		\
	sock/buffer.c		\
	sock/client.c		\
	sock/graphic.c		\
	cmd/utils.c		\
	cmd/nb_teams.c

OBJS	= $(SRCS:.c=.o)

CFLAGS	+= -W			\
	-Wall			\
	-Werror			\
	-Wextra			\
	-I../../include		\
	-g3

all: $(NAME)

$(NAME): $(OBJS)
	gcc -o $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
