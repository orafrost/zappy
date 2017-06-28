##
## Makefile for zappy in /home/kerma/Projets/Epitech/PSU/zappy
##
## Made by kerma
## Login   <kerma@epitech.net>
##
## Started on  Tue Jun 27 21:20:58 2017 kerma
## Last update Wed Jun 28 17:30:21 2017 kerma
##

NAME1		= zappy_server
NAME2		= zappy_ai
NAME3		= zappy_graphic

all: $(NAME1) $(NAME2) $(NAME3)

$(NAME1):
	make -C src/server/
	cp src/server/$(NAME1) ./

$(NAME2):
	make -C src/ai/
	cp src/ai/$(NAME2) ./

$(NAME3):
	make -C src/graphic/
	cp src/graphic/$(NAME3) ./

clean:
	make clean -C src/server/
	make clean -C src/ai
	make clean -C src/graphic

fclean: clean
	rm -f $(NAME1)
	rm -f $(NAME2)
	rm -f $(NAME3)
	make fclean -C src/server/
	make fclean -C src/ai
	make fclean -C src/graphic

re: fclean all
