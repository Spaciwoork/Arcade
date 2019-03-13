//
// Created by spaciwork on 08/04/18.
//

#include "../include/libsfml.hpp"

void	lib_SFML::generate_ennemy(t_draw_data *content)
{
	unsigned int number = 0;
	sf::Sprite sto;
	if (ennemy.size() < content->secondary->size())
		for (auto it = content->secondary->begin();
			it != content->secondary->end(); it++) {
			if (number >= ennemy.size()) {
				sto = corp.at(0).sprite_game;
				sto.setPosition(content->secondary->at(
					number)->getPosX() * 100,
					content->secondary->at(
						number)->getPosY() * 100);
				ennemy.push_back(sto);
			}
			number++;
		}
}

void	lib_SFML::generate_laser(t_draw_data *content)
{
	unsigned int number = 0;
	sf::Sprite sto;
	if (laser.size() < content->tertiary->size())
		for (auto it = content->tertiary->begin();
			it != content->tertiary->end(); it++) {
			if ((laser.size() > 0) && (number < laser.size()))
				controle(content, number);
			if (number >= laser.size()) {
				sto = last.at(0).sprite_game;
				sto.setPosition(content->tertiary->at(
					number)->getPosX() * 100,
					content->tertiary->at(
						number)->getPosY() * 100);
				laser.push_back(sto);
			}
			number++;
		}
}


void	lib_SFML::generate_pow(t_draw_data *content)
{
	unsigned int number = 0;
	sf::Sprite sto;

		for (auto it = content->quaternary->begin();
			it != content->quaternary->end(); it++) {
			controle_pow(content, number);
			if (number >= power.size()) {
				sto = pow.at(0).sprite_game;
				sto.setPosition(get<0>(*it) * 100,
					get<1>(*it) * 100);
				power.push_back(sto);
			}
			number++;
		}
}