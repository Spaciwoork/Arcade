/*
** EPITECH PROJECT, 2018
** RESTART
** File description:
** getter
*/

#include "../include/snake.hpp"

player *Snake::getPlayer(void) const
{
	return (p);
}

vector<player *> *Snake::getSecondary(void) const
{
	return (secondary);
}

vector<player *> *Snake::getTertiary(void) const
{
	return (tertiary);
}

vector<pair<int, int>> *Snake::getQuaternary(void) const
{
	return (quaternary);
}

vector<player *> *Snake::getFifth(void) const
{
	return (fifth);
}

bool Snake::getGameOver(void) const
{
	return (gameOver);
}