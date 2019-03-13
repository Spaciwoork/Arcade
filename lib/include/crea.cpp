//
// Created by spaciwork on 06/04/18.
//

#include "libsfml.hpp"

IDisplayModule *create() {
	return new lib_SFML;
}

void destroy(IDisplayModule *lib_SFML) {
	delete lib_SFML;
}