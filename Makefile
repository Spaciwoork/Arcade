##
## EPITECH PROJECT, 2018
## Philosophers
## File description:
## Makefile
##

SRC		=	src/main.cpp	\
			src/parser.cpp	\
			src/core.cpp	\
			src/player/checkpos.cpp	\
			src/player/constructor.cpp	\
			src/player/getter.cpp		\
			src/player/move.cpp		\
			src/player/setter.cpp   \

OBJ		=	$(SRC:.cpp=.o)

NAME		=	arcade

FLAGS		=	-W -Wextra

all:
	$(MAKE) graphicals
	$(MAKE) games
	$(MAKE) core

games:
	make -C games

core:	$(OBJ)
	g++ -o $(NAME) $(OBJ) $(FLAGS) -g -ldl

graphicals:
	make -C lib

clean:
	rm -f $(OBJ)

fclean:	clean
	make fclean -C lib/
	make fclean -C games/
	rm -f $(NAME)

re:	fclean all

author:
	echo $(USER) > author

.PHONY: games core graphicals