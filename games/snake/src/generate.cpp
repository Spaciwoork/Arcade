/*
** EPITECH PROJECT, 2018
** cpp_arcade
** File description:
** generate
*/

#include "../include/snake.hpp"
#include <math.h>

map<string, int> Snake::mapCreator(float x, float y)
{
	Map["larg"] = (HEIGHT) * 100 - y * 2 / 100;
	Map["long"] = (WIDTH) * 100 - x * 2 / 100;
	Map["pos_x"] = x * 2 / 100;
	Map["pos_y"] = y * 2 / 100;
	p = new player(WIDTH * 100 / 2, HEIGHT * 100 / 2, TOP);
	for (int i = 0; i < 3; i++)
		tertiary->push_back(new player(WIDTH / 2, HEIGHT / 2 + ((i * 0.65 / 2 + 0.65 / 2)), TOP));
	for (int i = 0; i < 2; i++)
		addFruit();
	return (Map);
}

t_draw_data *Snake::generateContent(void)
{
	t_draw_data *content = new t_draw_data;

	content->p = p;
	content->secondary = secondary;
	content->tertiary = tertiary;
	content->quaternary = quaternary;
	content->fifth = fifth;
	content->sprite = "snake.png";
	return (content);
}