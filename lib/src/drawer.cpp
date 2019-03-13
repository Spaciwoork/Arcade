/*
** EPITECH PROJECT, 2018
** cpp_arcade
** File description:
** drawer
*/


#include "../include/libsfml.hpp"

void	lib_SFML::draw_content(t_draw_data *info)
{
	int value[4];
	value[0] = 0;
	value[1] = 0;
	value[2] = 2;
	value[3] = 2;
	string img = info->sprite;
	maine = spritor(img, value);
	data.clear();

	value[0] = 0;
	value[1] = 4;
	value[2] = 2;
	value[3] = 6;
	last = spritor(img, value);
	data.clear();

	value[0] = 0;
	value[1] = 2;
	value[2] = 2;
	value[3] = 4;
	corp = spritor(img, value);
	data.clear();

	value[0] = 2;
	value[1] = 0;
	value[2] = 3;
	value[3] = 1;
	pow = spritor(img, value);
	data.clear();
}


vector<stocking> lib_SFML::spritor(string img, int *value)
{
	static int i;
	int x_size = 5;
	int coor_start = 0;
	int coor_sprite = 65;
	int y_size = 4;
	int x_coor = 0;
	sf::Sprite spriting;
	sf::Texture prep;

	for (int compt_y = value[0]; compt_y < value[2]; compt_y++) {
		for (int compt_x = value[1]; compt_x < value[3]; compt_x++) {
			sf::IntRect rect(compt_x * coor_sprite,
				compt_y * coor_sprite, coor_sprite,
				coor_sprite);
			prep.loadFromFile(img, rect);
			tmp[i].textu_game = prep;
			spriting.setTexture(tmp[i].textu_game);
			spriting.setScale(0.5, 0.5);
			tmp[i].sprite_game = spriting;
			data.push_back(tmp[i]);
			i++;
		}
	}
	return (data);
}


int	lib_SFML::draw_map(map<string, int> mapper)
{
	auto it_long = mapper.find("long");
	auto it_larg = mapper.find("larg");
	auto it_x = mapper.find("pos_x");
	auto it_y = mapper.find("pos_y");

	line_haut.setPosition(it_x->second, it_y->second);
	line_haut.setSize(sf::Vector2f(it_long->second, 5));
	line_bas.setSize(sf::Vector2f(it_long->second + 5, 5));
	line_bas.setPosition(it_x->second - 5, it_y->second + it_larg->second);
	line_gauche.setSize(sf::Vector2f(it_larg->second, 5));
	line_gauche.setPosition(it_x->second, it_y->second);
	line_droite.setSize(sf::Vector2f(it_larg->second, 5));
	line_droite.setPosition(it_long->second + it_x->second, it_y->second);
	line_droite.rotate(90);
	line_gauche.rotate(90);
}