##
## EPITECH PROJECT, 2018
## Philosophers
## File description:
## Makefile
##

SRC_SOLARFOX		=	solarfox/include/externs.cpp	\
				solarfox/src/constructor.cpp	\
				solarfox/src/getter.cpp		\
				solarfox/src/getter2.cpp	\
				solarfox/src/solarfox.cpp	\
				solarfox/src/move.cpp		\
				solarfox/src/missile.cpp	\
				solarfox/src/powerup.cpp

SRC_NIBBLER		=	snake/include/externs.cpp	\
				snake/src/constructor.cpp	\
				snake/src/getter.cpp		\
				snake/src/fruit.cpp		\
				snake/src/move.cpp		\
				snake/src/check.cpp		\
				snake/src/action.cpp		\
				snake/src/game.cpp		\
				snake/src/generate.cpp

SRC_COMMON		=	../src/player/constructor.cpp	\
				../src/player/checkpos.cpp	\
				../src/player/getter.cpp	\
				../src/player/setter.cpp	\
				../src/player/move.cpp		\
				duplicate.cpp

OBJ		=	$(SRC_SOLAR:.cpp=.o) $(SRC_NIBBLER:.cpp=.o) $(SRC_COMMON:.cpp=.o)

NAME_SOLARFOX		=   	lib_arcade_solarfox

NAME_NIBBLER		=   	lib_arcade_nibbler

FLAGS		=	-W -Wextra

all:	$(OBJ)
	g++ -shared -fPIC $(SRC_SOLARFOX) $(SRC_COMMON) -o lib_arcade_solarfox.so
	g++ -shared -fPIC $(SRC_NIBBLER) $(SRC_COMMON) -o lib_arcade_nibbler.so

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME_NIBBLER).so
	rm -f $(NAME_SOLARFOX).so

re:	fclean all

author:
	echo $(USER) > author
