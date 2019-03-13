/*
** EPITECH PROJECT, 2018
** cpp_arcade
** File description:
** move
*/

#include "../include/solarfox.hpp"

map<string, int> solarfox::mapCreator(float x, float y)
{
	Map["larg"] = (P_HEIGHT - 0.3) * 100;
	Map["long"] = (P_WIDTH - 0.4) * 100;
	Map["pos_x"] = (3 + 0.3) * 100 - x * 2 / 100;
	Map["pos_y"] = 3 * 100 - y * 2 / 100;
	return (Map);
}

t_draw_data *solarfox::generateContent()
{
	t_draw_data *content = new t_draw_data;

	content->p = p;
	content->p->turnDrawable();
	content->secondary = secondary;
	content->tertiary = tertiary;
	content->quaternary = quaternary;
	content->fifth = fifth;
	content->sprite = "solarfox.png";
	return (content);
}

void solarfox::move_player(player *play, int value)
{
	if (value == BOTTOM && p->getWay() != TOP)
		p->setWay(BOTTOM);
	else if (value == TOP && p->getWay() != BOTTOM)
		p->setWay(TOP);
	else if (value == LEFT && p->getWay() != RIGHT)
		p->setWay(LEFT);
	else if (value == RIGHT && p->getWay() != LEFT)
		p->setWay(RIGHT);
	p->forward();
}

void solarfox::action(player *play, int value)
{
	if (value == FIRE)
		launchMissile();
}

int solarfox::check_pos()
{
	auto it_long = Map.find("long");
	auto it_larg = Map.find("larg");
	auto it_x = Map.find("pos_x");
	auto it_y = Map.find("pos_y");
	vector<float> pos_solarfox;

	pos_solarfox.push_back(p->getPosX());
	pos_solarfox.push_back(p->getPosY());
	if ((pos_solarfox.at(0) < it_x->second ) ||
		(pos_solarfox.at(0) > (it_x->second + it_long->second - 10)))
		return (-1);
	else if ((pos_solarfox.at(1) < it_y->second ) ||
		(pos_solarfox.at(1) > (it_y->second + it_larg->second - 10)))
		return (-1);
	return (0);
}