/*
** EPITECH PROJECT, 2018
** cpp_arcade
** File description:
** externs
*/

#include "snake.hpp"

ILoadGame *creater() {
	return (new Snake);
}

void destroyr(ILoadGame *snake) {
	delete snake;
}