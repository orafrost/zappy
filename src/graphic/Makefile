##
## Makefile for zappy in /home/eric/tek2/zappy/graphic
## 
## Made by Eric Amilhat
## Login   <eric.amilhat@epitech.eu>
## 
## Started on  Tue Jun 20 14:22:10 2017 Eric Amilhat
## Last update Wed Jun 21 11:53:55 2017 Eric Amilhat
##

NAME	= zappy_graphic

SRC	= zappy_graphic.cpp

OBJ	= $(SRC:.cpp=.o)

CXX	= g++

CXXFLAGS	=  -Wextra -std=c++11

all:	$(OBJ)
	g++ $(OBJ) -o$(NAME) -std=c++11 -lsfml-audio -lsfml-graphics -lsfml-window -lsfml-system 

sfml:
	g++ -std=c++11 -fPIC -c  -I/usr/include lib/sfml_entry.cpp -o lib/lib_arcade_sfml.o
	g++ lib/lib_arcade_sfml.o -I/usr/include -lsfml-audio -lsfml-graphics -lsfml-window -lsfml-system -shared -ldl -ltinfo -Wl,--no-undefined  -o lib/lib_arcade_sfml.so

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

