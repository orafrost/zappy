##
## Makefile for zappy in /home/kerma/Projets/Epitech/PSU/zappy/src/server
##
## Made by kerma
## Login   <kerma@epitech.net>
##
## Started on  Tue Jun 20 14:17:36 2017 kerma
## Last update Tue Jun 27 16:26:45 2017 kerma
##

NAME	= zappy_server

SRCS	= main.c		\
	list.c			\
	free.c			\
	main_loop.c		\
	args/misc.c		\
	args/init.c		\
	args/args.c		\
	args/arg1.c		\
	args/arg2.c		\
	sock/fd.c		\
	sock/sock.c		\
	sock/wait.c		\
	sock/buffer.c		\
	sock/client.c		\
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
