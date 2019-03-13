/*
** EPITECH PROJECT, 2018
** cpp_arcade
** File description:
** player
*/

#ifndef PLAYER_H_
#define PLAYER_H_

#include <iostream>
#include <vector>
#include <map>

using namespace std;

class player
{
protected:
	float x;
	float y;
	int way;
public:
	player(float, float, int);
	~player();
	float turnDrawable(void);
	float getPosX(void) const;
	float getPosY(void) const;
	float *getPos(void) const;
	int getWay(void) const;
	void setPosX(float);
	void setPosY(float);
	void setWay(float);
	void forward();
	int isOnEdge(float, float);
};

typedef struct s_draw_data
{
	player *p;
	vector<player *> *secondary;
	vector<player *> *tertiary;
	vector<pair<int, int>> *quaternary;
	map<string, int> Map;
	vector<player *> *fifth;
	string sprite;
} t_draw_data;

#endif /* !PLAYER_H_ */