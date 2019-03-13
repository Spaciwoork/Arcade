/*
** EPITECH PROJECT, 2018
** cpp_arcade
** File description:
** move
*/

#include "../include/snake.hpp"

void Snake::genNewPos(vector<player *>::iterator it, player *prev)
{
	float x;
	float y;
	int way;

	switch (prev->getWay()) {
		case (TOP):
			(*it)->setPosX(prev->getPosX());
			(*it)->setPosY(prev->getPosY() + 0.65 / 2);
			break;
		case (BOTTOM):
			(*it)->setPosX(prev->getPosX());
			(*it)->setPosY(prev->getPosY() - 0.65 / 2);
			break;
		case (LEFT):
			(*it)->setPosX(prev->getPosX() + 0.65 / 2);
			(*it)->setPosY(prev->getPosY());
			break;
		case (RIGHT):
			(*it)->setPosX(prev->getPosX() - 0.65 / 2);
			(*it)->setPosY(prev->getPosY());
			break;
	}
}

void Snake::move_player(player *p, int value)
{
	int nb = tertiary->size();
	player *tmp;
	player *tmp2;

	
tmp = new player(p->getPosX() / 100, p->getPosY() / 100, p->getWay());
	if (value == BOTTOM && p->getWay() != TOP)
		p->setWay(BOTTOM);
	else if (value == TOP && p->getWay() != BOTTOM)
		p->setWay(TOP);
	else if (value == LEFT && p->getWay() != RIGHT)
		p->setWay(LEFT);
	else if (value == RIGHT && p->getWay() != LEFT)
		p->setWay(RIGHT);
	switch (p->getWay()) {
		case (TOP):
			p->setPosY(p->getPosY() - 0.65 / 2);
			break;
		case (BOTTOM):
			p->setPosY(p->getPosY() + 0.65 / 2);
			break;
		case (LEFT):
			p->setPosX(p->getPosX() - 0.65 / 2);
			break;
		case (RIGHT):
			p->setPosX(p->getPosX() + 0.65 / 2);
			break;
	}
	for (auto it = tertiary->begin(); it != tertiary->end(); it++) {
		if (it == tertiary->begin()) {
			tmp2 = new player(tmp->getPosX(), tmp->getPosY(), tmp->getWay());
			tmp = new player((*it)->getPosX(), (*it)->getPosY(), (*it)->getWay());
			genNewPos(it, tmp2);
		} else {
			tmp2 = new player(tmp->getPosX(), tmp->getPosY(), tmp->getWay());
			tmp = new player((*it)->getPosX(), (*it)->getPosY(), (*it)->getWay());
			genNewPos(it, tmp2);
		}
		nb++;
	}
}