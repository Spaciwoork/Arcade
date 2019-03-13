//
// Created by spaciwork on 10/03/18.
//

#ifndef CPP_ARCADE_CORE_HPP
#define CPP_ARCADE_CORE_HPP

#include <iostream>
#include <map>
#include <vector>
#include <dlfcn.h>
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include "../include/IDisplayModule.hpp"
#include "../include/ILoadGames.hpp"
#include "global.hpp"

using namespace std;

typedef struct s_core
{
	void *handler;
	create_t *create;
	destroy_t *destroy;
	create_us *create_games;
	destroy_us *destroy_games;
	const char *dlsym_error;
	IDisplayModule *display;
	ILoadGame *gaming;
} t_core;

t_core load_graph(char *filename, t_core graph);
int	arcade(char *filename, char *arg2);
t_core	load_games(char *filename, t_core games, int);
int	menu(IDisplayModule *displayer);

#endif //CPP_ARCADE_CORE_HPP