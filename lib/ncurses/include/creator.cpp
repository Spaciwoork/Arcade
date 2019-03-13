//
// Created by spaciwork on 09/04/18.
//

#include "libncurses.hpp"

IDisplayModule *create() {
	return new lib_NCURSES;
}

void destroy(IDisplayModule *lib_NCURSES) {
	delete lib_NCURSES;
}