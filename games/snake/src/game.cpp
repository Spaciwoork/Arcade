/*
** EPITECH PROJECT, 2018
** cpp_arcade
** File description:
** game
*/

#include "../include/snake.hpp"

void Snake::game(void)
{
	if (quaternary->empty() == true || quaternary->size() < 2)
		addFruit();
	/*if (checkDeath() == true) {
		gameOver = true;
		return;
	}*/
	pickFruit();
}