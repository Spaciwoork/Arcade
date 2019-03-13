//
// Created by spaciwork on 12/03/18.
//

#ifndef CPP_ARCADE_GO_SNAKE_HPP
#define CPP_ARCADE_GO_SNAKE_HPP

#include "../../../include/global.hpp"
#include "../../../include/player.hpp"
#include "../../../include/IDisplayModule.hpp"
#include "../../../include/ILoadGames.hpp"

class Snake : public ILoadGame
{
public:
	Snake(void);
	virtual map<string, int> mapCreator(float, float);
	t_draw_data *generateContent(void);
	void move_player(player *p, int value);
	player *getPlayer(void) const;
	vector<player *> *getSecondary(void) const;
	vector<player *> *getTertiary(void) const;
	vector<pair<int, int>> *getQuaternary(void) const;
	vector<player *> *getFifth(void) const;
	bool getGameOver(void) const;
	int check_pos(void);
	void action(player *, int);
	void game(void);
	void addFruit(void);
	bool checkDeath(void);
	void pickFruit(void);
	void addToTail(void);
	player *genTail(void);
	void genNewPos(vector<player *>::iterator, player *);
};

extern "C" ILoadGame *creater(); /*{
	return new Snake;
}*/

extern "C" void destroyr(ILoadGame *Snake);/* {
	delete Snake;
}*/

#endif //CPP_ARCADE_GO_SNAKE_HPP
