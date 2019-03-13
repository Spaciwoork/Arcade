/*
** EPITECH PROJECT, 2018
** cpp_arcade
** File description:
** ILoadGames
*/


#ifndef CPP_ARCADE_GO_ILOADGAMES_HPP
#define CPP_ARCADE_GO_ILOADGAMES_HPP

//#include "../include/Core.hpp"

#include "global.hpp"
using namespace std;

class ILoadGame {
	protected:
		player *p;
		vector<player *> *secondary;
		vector<player *> *tertiary;
		vector<pair<int, int>> *quaternary;
		vector<player *> *fifth;
		map<string, int> Map;
		bool gameOver;
		float width;
		float height;
	public:
		
		virtual ~ILoadGame() = default;
		virtual map<string, int> mapCreator(float, float) = 0;
		virtual t_draw_data *generateContent(void) = 0;
		virtual void move_player(player *, int) = 0;
		virtual void action(player *, int) = 0;
		virtual int check_pos(void) = 0;
		virtual player *getPlayer(void) const = 0;
		virtual vector<player *> *getSecondary(void) const = 0;
		virtual vector<player *> *getTertiary(void) const = 0;
		virtual vector<pair<int, int>> *getQuaternary(void) const = 0;
		virtual vector<player *> *getFifth(void) const = 0;
		virtual bool getGameOver() const = 0;
		virtual void game() = 0;
};

typedef ILoadGame *create_us();
typedef void destroy_us(ILoadGame *);

#endif //CPP_ARCADE_GO_ILOADGAMES_HPP
