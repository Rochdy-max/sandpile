SRC	=	src/main.c	\
		src/sandpile.c

INCLUDE	= include/

NAME	=	sandpile

REMOVE	=	rm -rf

COMPILE_OPTIONS	=	-g

all:	$(NAME)

$(NAME):
	gcc -o $(NAME) -I $(INCLUDE) $(COMPILE_OPTIONS) $(SRC)

clean:

fclean:	clean
	$(REMOVE) $(NAME)

re: fclean all
