##
## Makefile for zappy in /home/kerma/Projets/Epitech/PSU/zappy
##
## Made by kerma
## Login   <kerma@epitech.net>
##
## Started on  Tue Jun 27 21:20:58 2017 kerma
## Last update Tue Jun 27 21:25:54 2017 kerma
##

NAME1	= zappy_server
NAME2	= zappy_ai
NAME3	= zappy_graphic

all: $(NAME1) $(NAME2) $(NAME3)

$(NAME1):
	make -C src/server/
	cp src/server/$(NAME1) ./

$(NAME2):
	# make -C path_ai/
	# cp path_ai/$(NAME2) ./

$(NAME3):
	# make -C path_graphic/
	# cp path_graphic/$(NAME3) ./

clean:
	make clean -C src/server/
	# make clean -C path_ai
	# make clean -C path_graphic

fclean: clean
	rm -f $(NAME1)
	# rm -f $(NAME2)
	# rm -f $(NAME3)
	make fclean -C src/server/
	# make fclean -C path_ai
	# make fclean -C path_graphic

re: fclean all
