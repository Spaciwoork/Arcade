/*
** EPITECH PROJECT, 2018
** local
** File description:
** move
*/

#include "../../include/player.hpp"
#include "../../include/global.hpp"

void player::forward()
{
	switch (way) {
		case (TOP):
			y -= 0.5;
			break;
		case (BOTTOM):
			y += 0.5;
			break;
		case (LEFT):
			x -= 0.5;
			break;
		case (RIGHT):
			x += 0.5;
			break;
	}
}