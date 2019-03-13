/*
** EPITECH PROJECT, 2018
** cpp_arcade
** File description:
** getter
*/

#include "../include/solarfox.hpp"

player *solarfox::getPlayer(void) const
{
	return (p);
}

vector<player *> *solarfox::getSecondary(void) const
{
	return (secondary);
}

vector<player *> *solarfox::getTertiary(void) const
{
	return (tertiary);
}

vector<pair<int, int>> *solarfox::getQuaternary(void) const
{
	return (quaternary);
}

vector<player *> *solarfox::getFifth(void) const
{
	return (fifth);
}