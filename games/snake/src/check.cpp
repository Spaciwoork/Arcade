/*
** EPITECH PROJECT, 2018
** cpp_arcade
** File description:
** check
*/

#include "../include/snake.hpp"
#include <math.h>

int	Snake::check_pos()
{
	auto it_long = Map.find("long");
	auto it_larg = Map.find("larg");
	auto it_x = Map.find("pos_x");
	auto it_y = Map.find("pos_y");

	if ((p->getPosX() < it_x->second ) || (p->getPosX() > (it_x->second + it_long->second)))
		return (-1);
	else if ((p->getPosY() < it_y->second ) || (p->getPosY() > (it_y->second + it_larg->second)))
		return (-1);
}

bool Snake::checkDeath(void)
{
	for (vector<player *>::iterator it = tertiary->begin(); it != tertiary->end(); it++) {
		if (fabs((*it)->getPosX() * 100 - p->getPosX()) <= 24 && fabs((*it)->getPosY() * 100 - p->getPosY()) <= 24)
			return (true);
	}
	return (false);
}