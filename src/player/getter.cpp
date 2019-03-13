/*
** EPITECH PROJECT, 2018
** cpp_arcade
** File description:
** getter
*/

#include "../../include/player.hpp"

float player::turnDrawable(void)
{
	x *= 100;
	y *= 100;
}

float player::getPosX(void) const
{
	return(x);
}

float player::getPosY(void) const
{
	return(y);
}

float *player::getPos(void) const
{
	float *pos = new float[2];

	pos[0] = x;
	pos[1] = y;
	return (pos);
}

int player::getWay(void) const
{
	return(way);
}