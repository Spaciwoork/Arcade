/*
** EPITECH PROJECT, 2018
** cpp_arcade
** File description:
** constructor
*/

#include "../include/snake.hpp"

Snake::Snake(void)
{
	secondary = new vector<player *>;
	tertiary = new vector<player *>;
	quaternary = new vector<pair<int, int>>;
	fifth = new vector<player *>;
}