/*
** EPITECH PROJECT, 2018
** cpp_arcade
** File description:
** powerup
*/

#include "../include/solarfox.hpp"
#include <math.h>

void solarfox::pickPowerup()
{
	for (auto it = quaternary->begin(); it != quaternary->end(); it++) {
		if (fabs(get<0>(*it) * 100 - p->getPosX()) <= 24 &&
			fabs(get<1>(*it) * 100 - p->getPosY()) <= 24) {
			quaternary->erase(it);
			return;
			}
	}
}