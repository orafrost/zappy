##
## Makefile for ../libsock.a in/home/orafrost/rendus/Tek2/ftp/client/lib/sock
##
## Made by guillaume verrier
## Login   <verrie_g@epitech.net>
##
## Started on	Sat Jun 18 11:55:44 2016 guillaume verrier
## Last update	Sat Jun 18 11:55:44 2016 guillaume verrier
##

NAME =	../libsock.a

SRC =	./client.c \
			./serveur.c \
			./com.c

OBJ =	$(SRC:.c=.o)


all:	$(NAME)

$(NAME):$(OBJ)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean all
