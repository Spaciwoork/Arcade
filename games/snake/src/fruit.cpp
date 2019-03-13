/*
** EPITECH PROJECT, 2018
** cpp_arcade
** File description:
** fruit
*/

#include "../include/snake.hpp"
#include <time.h>
#include <math.h>

player *Snake::genTail(void)
{
	float x;
	float y;
	int way;
	auto it = tertiary->begin();

	while (it != tertiary->end())
		it++;
	if (it == tertiary->end())
		it--;
	x = (*it)->getPosX();
	y = (*it)->getPosY();
	way = (*it)->getWay();
	switch (way) {
		case TOP:
			y += 0.65 / 2;
			break;
		case RIGHT:
			x -= 0.65 / 2;
			break;
		case BOTTOM:
			y -= 0.65 / 2;
			break;
		case LEFT:
			x += 0.65 / 2;
			break;
	}
	return (new player(x, y, way));
}

void Snake::addToTail(void)
{
	float x;
	float y;
	int i = tertiary->size();

	x = tertiary->at(i - 1)->getPosX() + 0.65 / 2;
	y = tertiary->at(i - 1)->getPosY();
	tertiary->push_back(genTail());
}

void Snake::pickFruit(void)
{
	for (auto it = quaternary->begin(); it != quaternary->end(); it++) {
		if (fabs(get<0>(*it) * 100 - p->getPosX()) <= 24 &&
			fabs(get<1>(*it) * 100 - p->getPosY()) <= 24) {
				quaternary->erase(it);
				addToTail();
				return;
		}
	}
}

void Snake::addFruit(void)
{
	int x;
	int y;

	srand((clock() * 1000 + time(NULL)) + getpid() * clock() * 3);
	x = rand() % (WIDTH - 5) + 3;
	y = rand() % (HEIGHT - 5) + 3;
	while (isDup(*quaternary, make_pair(x, y))) {
		srand((clock() * 1000 + time(NULL)) + getpid() * clock() * 3);
		x = rand() % (WIDTH - 1);
		y = rand() % (HEIGHT - 1);
	}
	quaternary->push_back(make_pair(x, y));
}