##
## EPITECH PROJECT, 2018
## arcade
## File description:
## Makefile
##

SRC_SFML		=	src/drawer.cpp			\
				src/display.cpp			\
				src/generateur.cpp		\
				src/getter.cpp			\
				src/libsfml.cpp			\
				src/menu.cpp			\
				src/window.cpp			\
				include/crea.cpp

SRC_NCURSES		=	ncurses/src/libncurses.cpp	\
				ncurses/include/creator.cpp

SRC_COMMON		=	../src/player/checkpos.cpp	\
				../src/player/constructor.cpp	\
				../src/player/getter.cpp	\
				../src/player/move.cpp		\
				../src/player/setter.cpp

OBJ			=	$(SRC_SFML:.cpp=.o) $(SRC_NCURSES:.cpp=.o) $(SRC_COMMON:.cpp=.o)

NAME_SFML		=	lib_arcade_SFML.so

NAME_NCURSES		=	lib_arcade_nCurses.so

CXXFLAGS			=	-W -Wextra -fPIC

all:	$(OBJ)
	g++ -shared -fPIC $(SRC_SFML) $(SRC_COMMON) -o lib_arcade_SFML.so -Llib -lsfml-graphics -lsfml-window -lsfml-system
	g++ -shared -fPIC $(SRC_NCURSES) $(SRC_COMMON) -o lib_arcade_nCurses.so -Llib -lncurses

clean:
	rm -f $(OBJ)
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME_SFML)
	rm -f $(NAME_NCURSES)

re:	fclean all

author:
	echo $(USER) > author

