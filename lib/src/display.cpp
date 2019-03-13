//
// Created by spaciwork on 08/04/18.
//

#include "../include/libsfml.hpp"

void	lib_SFML::aff_map()
{
	int number = 0;
	window.draw(line_gauche);
	window.draw(line_droite);
	window.draw(line_bas);
	window.draw(line_haut);
	window.draw(maine.at(way).sprite_game);
	for (auto it = ennemy.begin(); it != ennemy.end(); it++)
	{
		window.draw(ennemy.at(number));
		number++;
	}
	number = 0;
	for (auto it = laser.begin(); it != laser.end(); it++)
	{
		window.draw(laser.at(number));
		number++;
	}
	number = 0;
	for (auto it = power.begin(); it != power.end(); it++)
	{
		window.draw(power.at(number));
		number++;
	}
}



void	lib_SFML::aff_menu()
{
	window.draw(sprite_back);
	window.draw(text_solar);
	window.draw(text_snake);
	window.draw(text_menu);
}