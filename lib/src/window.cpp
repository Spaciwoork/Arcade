//
// Created by spaciwork on 08/04/18.
//

#include "../include/libsfml.hpp"

void lib_SFML::CreateWindow()
{

	return (window.create(sf::VideoMode(width, height), "Arcade"));
}

int lib_SFML::Refresh(int value)
{
	window.pollEvent(event);
	if (event.type == sf::Event::Closed) {
		window.close();
		return (-1);
	}
	else {
		window.clear();
		if (value == 5)
			aff_menu();
		else
			aff_map();
		window.display();
		return(value);
	}
}