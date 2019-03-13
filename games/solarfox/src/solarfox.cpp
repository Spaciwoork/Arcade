/*
** EPITECH PROJECT, 2018
** cpp_arcade
** File description:
** solarfox
*/

#include "../include/solarfox.hpp"
#include <time.h>
#include <math.h>

void solarfox::spawner(void)
{
	int spawn;
	float x = 0;
	float y = 0;
	int side;
	player *p;

	srand((clock() * 1000 + time(NULL)) + getpid());
	side = rand() % 2;
	srand((clock() * 1000 + time(NULL)) * getpid());
	spawn = rand() % 700;
	if (spawn > 1)
		return;
	if (spawn == 0) {
		x = rand() % (WIDTH - 5) + 3;
		y = HEIGHT * side;
	}
	else if (spawn == 1) {
		x = WIDTH * side;
		y = rand() % (HEIGHT - 5) + 3;
	}
	p = new player(x, y, 0);
	if (isDup(*secondary, p) == false)
		secondary->push_back(p);
}

void solarfox::shoot(void)
{
	int x;
	int y;
	int way;

	for (vector<player *>::iterator it = secondary->begin(); it != secondary->end(); it++) {
		if ((*it)->getWay() % SHOOTCYCLE == 0) {
			x = (*it)->getPosX();
			y = (*it)->getPosY();
			if (x == 0 || x == (WIDTH)) {
				way = (x == 0) ? RIGHT : LEFT;
				x = (x == 0) ? x + 1 : x - 1;
				//x = abs(x - 1);
			} else if (y == 0 || y == (HEIGHT)) {
				way = (y == 0) ? BOTTOM : TOP;
				y = (y == 0) ? y + 1 : y - 1;
				//y = abs(y - 1);
			}
			else
				way = -1;
			tertiary->push_back(new player(x, y, way));
			//Lasers->push_back(make_tuple(x, y, way));
		}
		(*it)->setWay((*it)->getWay() + 1);
		//get<2>(*it) += 1;
	}
}

bool solarfox::checkDeath(void)
{
	for (vector<player *>::iterator it = tertiary->begin(); it != tertiary->end(); it++) {
		if (fabs((*it)->getPosX() * 100 - p->getPosX()) <= 24 && fabs((*it)->getPosY() * 100 - p->getPosY()) <= 24)
			return (true);
	}
	return (false);
}

void solarfox::game(void)
{
	spawner(); // Create Enemy
	
	lasersForward(); // Move Lasers

	// Move Missiles

	shoot(); // Create Enemy Lasers

	clearOutside();

	//Check Missile-Laser Collision
	checkCollision();

	//Check Player's Death
	if (checkDeath() == true) {
		gameOver = true;
		return;
	}

	pickPowerup();
	if (quaternary->empty() == true) {
		cout << "You won !" << endl;
		exit(0);
	}
}