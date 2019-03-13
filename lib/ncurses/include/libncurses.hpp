//
// Created by spaciwork on 08/04/18.
//

#ifndef ARCADE_LIBNCURSES_HPP
#define ARCADE_LIBNCURSES_HPP

#include "../../../include/global.hpp"
#include "../../../include/player.hpp"
#include "../../../include/IDisplayModule.hpp"
#include "../../../include/ILoadGames.hpp"
#include <ncurses.h>

class lib_NCURSES : public IDisplayModule {
	protected:
	int width;
	int height;
	WINDOW *boite, *title, *solarfox, *snake, *map_game, *player;
	int key;
	int player_posX;
	int player_posY;
	int toto;

	public:
	lib_NCURSES();
	~lib_NCURSES(void);
	void CreateWindow();
	int Refresh(int value);
	int draw_map(map<string, int> mapper);
	void draw_content(t_draw_data *);
	int moove();
	void setnewpos(t_draw_data *);
	float getWidth(void);
	float getHeight(void);
	void create_menu();
	int  select_game(int);
	void generate_ennemy(t_draw_data *);
	void generate_laser(t_draw_data *);
	void generate_pow(t_draw_data *content);
};

extern "C" IDisplayModule* create();

extern "C" void destroy(IDisplayModule* lib_NCURSES);

#endif //ARCADE_LIBNCURSES_HPP
