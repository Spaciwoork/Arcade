/*
** EPITECH PROJECT, 2018
** cpp_arcade
** File description:
** duplicate
*/

#include "../include/global.hpp"

bool isDup(vector<pair<int, int>> v, pair<int, int> p)
{
	for (vector<pair<int, int>>::iterator it = v.begin(); it != v.end(); it++) {
		if (p == *it)
			return (true);
	}
	return (false);
}

bool isDup(vector<player *> v, player *p)
{
	for (vector<player *>::iterator it = v.begin(); it != v.end(); it++) {
		if (p->getPosX() == (*it)->getPosX() && p->getPosY() == (*it)->getPosY())
			return (true);
	}
	return (false);
}