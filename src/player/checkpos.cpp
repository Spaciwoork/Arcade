/*
** EPITECH PROJECT, 2018
** local
** File description:
** checkpos
*/

#include "../../include/player.hpp"
#include "../../include/global.hpp"

int player::isOnEdge(float width, float height) // handle corners (x == 0 && y == 0 [...])
{
	if (x == 0 || x == width) {
		if (x == 0)
			return (LEFT);
		return (RIGHT);
	}
	else if (y == 0 || y == height) {
		if (y == 0)
			return (TOP);
		return (BOTTOM);
	}
	return (-1);
}