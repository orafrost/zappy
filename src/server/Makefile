##
## Makefile for zappy in /home/kerma/Projets/Epitech/PSU/zappy/src/server
##
## Made by kerma
## Login   <kerma@epitech.net>
##
## Started on  Tue Jun 20 14:17:36 2017 kerma
## Last update Fri Jun 23 16:06:43 2017 kerma
##

NAME	= zappy_server

SRCS	= main.c	\
	free.c		\
	args/misc.c	\
	args/args.c	\
	args/arg1.c	\
	args/arg2.c

OBJS	= $(SRCS:.c=.o)

CFLAGS	+= -W			\
	-Wall			\
	-Werror			\
	-Wextra			\
	-I../../include		\
	-I../../lib/sock/	\
	-g3

all: $(NAME)

$(NAME): $(OBJS)
	gcc -o $(NAME) $(OBJS) -L../../lib -lsock

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
