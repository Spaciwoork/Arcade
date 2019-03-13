//
// Created by spaciwork on 08/04/18.
//

#include "../include/libsfml.hpp"

int	lib_SFML::select_game(int value)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::F1))
		value = 1;
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::F2))
		value = 2;
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::F3))
		value = 3;
	return (value);
}

sf::Text	lib_SFML::setText(float pos_x, float pos_y, float size, string Text)
{
	sf::Text textu;
	textu.setFont(font_menu);
	textu.setFillColor(sf::Color::Black);
	textu.setPosition(pos_x, pos_y);
	textu.setCharacterSize(size);
	textu.setString(Text);
	return (textu);
}

void	lib_SFML::create_menu()
{
	textu_back.loadFromFile("background.png");
	sprite_back.setTexture(textu_back);
	sprite_back.setPosition(0, 0);
	sprite_back.setScale(0.49, 0.48);
	font_menu.loadFromFile("ARCADE_I.TTF");
	text_menu = setText(width / 2 - 400, height / 2 - 200, 120, "ARCADE");
	text_snake = setText(width / 2 - 550, height /2, 60, "SNAKE");
	text_solar = setText(width / 2 + 50, height / 2, 60, "SOLAR_FOX");
}