##
## Makefile for zappy in /home/kerma/Projets/Epitech/PSU/zappy
##
## Made by kerma
## Login   <kerma@epitech.net>
##
## Started on  Tue Jun 27 21:20:58 2017 kerma
## Last update Sun Jul  2 20:25:13 2017 kerma
##

NAME		= zappy_graphic

SRCS		= main.cpp		\
		Utils.cpp		\
		Socket.cpp		\
		Graphic.cpp		\
		Commands.cpp

OBJS		= $(SRCS:.cpp=.o)

CPPFLAGS	+= -W		\
		-Wall		\
		-Werror		\
		-Wextra		\
		-std=c++11	\
		-I./include

all: $(NAME)

$(NAME): $(OBJS)
	g++ -o $(NAME) $(OBJS) -lsfml-audio -lsfml-graphics -lsfml-window -lsfml-system

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
