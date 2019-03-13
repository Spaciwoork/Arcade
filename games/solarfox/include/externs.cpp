/*
** EPITECH PROJECT, 2018
** cpp_arcade
** File description:
** externs
*/

#include "solarfox.hpp"

ILoadGame *creater() {
	return (new solarfox);
}

void destroyr(ILoadGame *solarfox) {
	delete solarfox;
}