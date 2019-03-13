/*
** EPITECH PROJECT, 2018
** cpp_arcade
** File description:
** getter
*/

#include "../include/solarfox.hpp"
#include <time.h>

vector<pair<int, int>> *solarfox::genMap(void)
{
	int nbPwUp = P_WIDTH * P_HEIGHT / 2;
	int x;
	int y;
	vector<pair<int, int>> *map = new vector<pair<int, int>>();

	for (int i = 0; i < nbPwUp; i++) {
		srand((clock() * 1000 + time(NULL)) + getpid() * clock() * 3);
		x = rand() % (WIDTH - 5) + 3;
		y = rand() % (HEIGHT - 5) + 3;
		while (isDup(*map, make_pair(x, y)))
		{
			srand((clock() * 1000 + time(NULL)) + getpid() * clock() * 3);
			x = rand() % (WIDTH - 5) + 3;
			y = rand() % (HEIGHT - 5) + 3;
		}
		map->push_back(make_pair(x, y));
	}
	return (map);
}

solarfox::solarfox()
{
	p = new player(WIDTH / 2, HEIGHT / 2, TOP);
	secondary = new vector<player *>;
	tertiary = new vector<player *>;
	quaternary = genMap();
	fifth = new vector<player *>;
	gameOver = false;
}

solarfox::~solarfox()
{
}