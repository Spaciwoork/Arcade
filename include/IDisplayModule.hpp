/*
** EPITECH PROJECT, 2018
** cpp_arcade
** File description:
** IDisplayModule
*/

#ifndef CPP_ARCADE_IDISPLAYEMODULE_HPP
#define CPP_ARCADE_IDISPLAYEMODULE_HPP

#include "global.hpp"
using namespace std;

class IDisplayModule {
	protected:
		player *p;
		vector<player *> *secondary;
		vector<player *> *tertiary;
		vector<pair<int, int>> *quaternary;
	public:
		virtual ~IDisplayModule() = default;
		virtual void CreateWindow() = 0;
		virtual int Refresh(int value) = 0;
		virtual int draw_map(map<string, int> mapper) = 0;
		virtual void draw_content(t_draw_data *) = 0;
		virtual int moove() = 0;
		virtual void setnewpos(t_draw_data *) = 0;
		virtual float getWidth(void) = 0;
		virtual float getHeight(void) = 0;
		virtual void create_menu() = 0;
		virtual int  select_game(int) = 0;
		virtual	void generate_ennemy(t_draw_data *) = 0;
		virtual void generate_laser(t_draw_data *) = 0;
		virtual void generate_pow(t_draw_data *content) = 0;
};

typedef IDisplayModule *create_t();
typedef void destroy_t(IDisplayModule *);

#endif //CPP_ARCADE_IDISPLAYEMODULE_HPP
