/*
** EPITECH PROJECT, 2018
** cpp_arcade
** File description:
** missile
*/

#include "../include/solarfox.hpp"

void solarfox::clearOutside(void)
{
	if (tertiary->empty() == false) {
		for (vector<player *>::iterator it = tertiary->begin();
			it != tertiary->end(); it++) {
			if ((*it)->getPosX() <= 0 || (*it)->getPosX() >= WIDTH)
				tertiary->erase(it);
			if ((*it)->getPosY() <= 0 || (*it)->getPosY() >= HEIGHT)
				tertiary->erase(it);
		}
	}
	if (fifth->empty() == false) {
		for (vector<player *>::iterator it = fifth->begin();
			it != fifth->end(); it++) {
			if ((*it)->getPosX() <= 3 || (*it)->getPosY() >= WIDTH - 3)
				fifth->erase(it);
			if ((*it)->getPosY() <= 3 || (*it)->getPosY() >= HEIGHT + 3)
				fifth->erase(it);
		}
	}
}

void solarfox::checkCollision(void)
{
	for (vector<player *>::iterator it = tertiary->begin();
		it != tertiary->end(); it++) {
		for (vector<player *>::iterator iter = fifth->begin();
			iter != fifth->end(); iter++) {
			if ((*it)->getPosX() == (*iter)->getPosX() &&
				(*it)->getPosY() == (*iter)->getPosY()) {
				tertiary->erase(it);
				fifth->erase(iter);
			}
		}
	}
}

void solarfox::lasersForward(void)
{
	for (vector<player *>::iterator it = tertiary->begin();
		it != tertiary->end(); it++) {
		switch ((*it)->getWay()) {
		case (TOP):
			(*it)->setPosY((*it)->getPosY() - 0.003);
			break;
		case (BOTTOM):
			(*it)->setPosY((*it)->getPosY() + 0.003);
			break;
		case (LEFT):
			(*it)->setPosX((*it)->getPosX() - 0.003);
			break;
		case (RIGHT):
			(*it)->setPosX((*it)->getPosX() + 0.003);
			break;
		}
	}
}

void solarfox::launchMissile(void)
{
	float x = p->getPosX();
	float y = p->getPosY();
	int way = p->getWay();
	player *missile;

	switch (way) {
	case (TOP):
		y -= 0.003;
		break;
	case (BOTTOM):
		y += 0.003;
		break;
	case (LEFT):
		x -= 0.003;
		break;
	case (RIGHT):
		x += 0.003;
		break;
	}
	fifth->push_back(new player(x, y, way));
}