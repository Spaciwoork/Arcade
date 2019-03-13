/*
** EPITECH PROJECT, 2018
** cpp_arcade
** File description:
** global
*/

#ifndef GLOBAL_HPP_
#define GLOBAL_HPP_

#include <sys/types.h>
#include <sys/unistd.h>
#include <iostream>
#include <vector>
#include <map>
#include "player.hpp"

using namespace std;

#define WIDTH 8
#define HEIGHT 10
#define P_WIDTH (WIDTH - 5)
#define P_HEIGHT (HEIGHT - 5)
/*#define TOP 0
#define RIGHT 1
#define BOTTOM 2
#define LEFT 3*/

enum keyboard
{
	EXIT = -1,
	TOP = 0,
	RIGHT = 1,
	BOTTOM = 2,
	LEFT = 3,
	FIRE = 4,
	CHANGE_LIB = 6
};

void print_tuple(tuple<int, int, int>);
void print_vector(vector<int>);
void print_vector(vector<char>);
void print_vector(vector<pair<int, int>>);
void print_vector(vector<tuple<int, int, int>>);
bool isDup(vector<pair<int, int>>, pair<int, int>);
bool isDup(vector<player *>, player *);
	
#endif /* !GLOBAL_HPP_ */