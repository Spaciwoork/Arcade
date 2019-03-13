//
// Created by spaciwork on 08/04/18.
//

#include "../include/libncurses.hpp"

lib_NCURSES::lib_NCURSES(void)
{
	width = 1000;
	height = 1000;
}

void lib_NCURSES::CreateWindow()
{
	initscr();
	boite = newwin(LINES, COLS, 0, 0);
	wborder(boite, '|', '|', '*', '*', '+', '+', '+', '+');
	keypad(boite, TRUE);
	//wrefresh(boite);
	noecho();
	keypad(stdscr, TRUE);
}

int lib_NCURSES::Refresh(int value)
{
	if (value != 5)
	{
		wrefresh(map_game);
		wrefresh(player);
	}
	return (value);
}

lib_NCURSES::~lib_NCURSES()
{
	delwin(boite);
	getch();
	endwin();
	free(boite);
}

int	lib_NCURSES::draw_map(map<string, int> mapper)
{
	delwin(boite);
	endwin();
	map_game = newwin(LINES, COLS, 0, 0);
	wborder(map_game, '|', '|', '*', '*', '+', '+', '+', '+');
	return 0;
}

void lib_NCURSES::draw_content(t_draw_data *content)
{
	player_posX = (int)content->p->getPosX();
	player_posY = (int)content->p->getPosY();
	player = newwin(1, 1, (int)content->p->getPosY()/ 100, (int)content->p->getPosX() / 100);
	wprintw(player, "P");
}

int lib_NCURSES::moove()
{
	return 0;
}

void lib_NCURSES::setnewpos(t_draw_data *content)
{
	wmove(player, (int)content->p->getPosY() / 100, (int)content->p->getPosX() / 100);
	wrefresh(player);
}

float lib_NCURSES::getWidth(void)
{
	return 0;
}

float lib_NCURSES::getHeight(void)
{
	return 0;
}

void lib_NCURSES::create_menu()
{
	title = newwin(10, 20, LINES /2 - LINES /8, COLS/2 - COLS/14);
	wprintw(title, "ARCADE");
	solarfox = newwin(10, 20, LINES - LINES /2, COLS/2 - COLS/4);
	wprintw(solarfox, "SOLAR_FOX");
	snake = newwin(10, 20, LINES - LINES /2, COLS /2 + COLS / 8);
	wprintw(snake, "SNAKE");
}

int  lib_NCURSES::select_game(int value)
{
	wrefresh(boite);
	wrefresh(title);
	wrefresh(solarfox);
	wrefresh(snake);
	key = wgetch(boite);
	if (key == KEY_F(2))
		value = 1;
	else if (key == KEY_F(3))
		value = 2;
	else if (key == KEY_F(4))
		value = 3;
	return (value);
}

void lib_NCURSES::generate_ennemy(t_draw_data *content)
{

}

void lib_NCURSES::generate_laser(t_draw_data *content)
{

}

void lib_NCURSES::generate_pow(t_draw_data *content)
{

}