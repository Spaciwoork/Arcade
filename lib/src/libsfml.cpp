/*
** EPITECH PROJECT, 2018
** cpp_arcade
** File description:
** libsfml
*/

#include "../include/libsfml.hpp"
#include <math.h>

lib_SFML::lib_SFML(void)
{
	width = sf::VideoMode::getDesktopMode().width;
	height = sf::VideoMode::getDesktopMode().height;
}

void	lib_SFML::setnewpos(t_draw_data *content)
{
	int number = 0;
	if (maine.size() > 0) {
		maine.at(way).sprite_game.setPosition(content->p->getPosX(),
			content->p->getPosY());
		for (auto it = content->secondary->begin();
			it != content->secondary->end(); it++) {
			ennemy.at(number).setPosition(
				content->secondary->at(number)->getPosX() * 100,
				content->secondary->at(number)->getPosY() *
					100);
			number++;
		}
		number = 0;
		if (laser.size() > 0) {
			for (auto it = content->tertiary->begin();
				it != content->tertiary->end(); it++) {
				laser.at(number).setPosition(
					content->tertiary->at(
						number)->getPosX() * 100,
					content->tertiary->at(
						number)->getPosY() * 100);
				number++;
			}
		}
	}
	else {
		exit(84);
	}

}

void	lib_SFML::controle_pow(t_draw_data *content, int number)
{
	float cmp_x;
	float cmp_y;
	float other_cmp_x;
	float other_cmp_y;

	auto it = content->quaternary->begin() + number;
	cmp_x = content->p->getPosX();
	cmp_y = content->p->getPosY();
	other_cmp_x = (float)get<0>(*it) * 100;
	other_cmp_y = (float)get<1>(*it) * 100;
	if (fabs(cmp_x - other_cmp_x) <= 24 && fabs(cmp_y - other_cmp_y) <= 24)
		power.erase(power.begin() + number);
}

void	lib_SFML::controle(t_draw_data *content, int number)
{
	float cmp_x;
	float cmp_y;
	float other_cmp_x;
	float other_cmp_y;

	cmp_x = laser.at(number).getPosition().x;
	cmp_y = laser.at(number).getPosition().y;
	other_cmp_x = content->tertiary->at(number)->getPosX() * 100;
	other_cmp_y = content->tertiary->at(number)->getPosY() * 100;
	if ((other_cmp_x - cmp_x) > 100)
		laser.erase(laser.begin() + number);
	else if ((other_cmp_y - cmp_y) > 100)
		laser.erase(laser.begin() + number);
}

int	lib_SFML::indicate_direction(int direction_receive)
{
	switch (direction_receive){
	case TOP:
		return (0);
	case RIGHT:
		return (1);
	case LEFT:
		return (2);
	case BOTTOM:
		return (3);

	}
}

int	lib_SFML::moove()
{
	sf::Event event;
	static int value = -2;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		value = LEFT;
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		value = RIGHT;
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		value = BOTTOM;
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		value = TOP;
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		value = CHANGE_LIB;
	return (value);

}


lib_SFML::~lib_SFML()
{
}