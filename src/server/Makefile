##
## Makefile for zappy in /home/kerma/Projets/Epitech/PSU/zappy/src/server
##
## Made by kerma
## Login   <kerma@epitech.net>
##
## Started on  Tue Jun 20 14:17:36 2017 kerma
## Last update Tue Jun 20 14:22:06 2017 kerma
##

NAME	= zappy_server

SRCS	= main.c

OBJS	= $(SRCS:.c=.o)

CFLAGS	+= -W -Wall -Werror -Wextra -I../../include

all: $(NAME)

$(NAME): $(OBJS)
	gcc -o $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
