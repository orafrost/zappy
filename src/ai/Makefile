##
## Makefile for zappy in /home/kerma/Projets/Epitech/PSU/zappy/src/ai
##
## Made by kerma
## Login   <kerma@epitech.net>
##
## Started on  Wed Jun 28 16:48:49 2017 kerma
## Last update Sun Jul  2 12:50:32 2017 kerma
##

NAME		= zappy_ai

OBJS		= $(SRCS:.cpp=.o)

SRCS		= main.cpp	\
		AI.cpp		\
		Utils.cpp	\
		Socket.cpp	\
		Commands.cpp	\

CPPFLAGS	+= -W		\
		-Wall		\
		-Werror		\
		-Wextra		\
		-std=c++11	\
		-I./include

all: $(NAME)

$(NAME): $(OBJS)
	g++ -o $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
