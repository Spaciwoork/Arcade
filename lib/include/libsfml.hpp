/*
** EPITECH PROJECT, 2018
** cpp_arcade
** File description:
** libsfml
*/

#ifndef CPP_ARCADE_GO_LIBSFML_HPP
#define CPP_ARCADE_GO_LIBSFML_HPP

#include "../../include/global.hpp"
#include "../../include/player.hpp"
#include "../../include/IDisplayModule.hpp"
#include "../../include/ILoadGames.hpp"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

using namespace std;

typedef struct s_stock				// STOCK SPRITE AND TEXTURE IN VECTOR
{
	sf::Sprite sprite_game;			// DON'T UNLINK SPRITE AND TEXTU IN VECTOR
	sf::Texture textu_game;			// IF UNLINK SFML DON'T FIND TEXTU
}		stocking;

class lib_SFML : public IDisplayModule {
protected:
	sf::RectangleShape rectangle;
	sf::RectangleShape line_haut;
	sf::RectangleShape line_droite;
	sf::RectangleShape line_gauche;
	sf::RectangleShape line_bas;
	sf::Texture texture_player;
	sf::Sprite sprite_player;
	sf::RenderWindow window;
	vector<float> save_player;
	sf::Texture textu_back;
	sf::Sprite sprite_back;
	sf::Font font_menu;
	sf::Text text_menu;
	sf::Text text_snake;
	sf::Text text_solar;
	vector<stocking> maine;			//VECTOR OF SPRITES + TEXTU
	vector<stocking> corp;
	vector<stocking> last;
	vector<stocking> data;
	vector<stocking> pow;
	stocking tmp[20];
	vector<sf::Sprite> ennemy;
	vector<sf::Sprite> laser;
	vector<sf::Sprite> power;
	sf::Event event;
	int way;

	int width;
	int height;
	vector<sf::Sprite> sprite_game;
	vector<sf::Texture> textu_game;
	typedef struct s_textu
	{
		int pos_img_x = 0;
		int pos_img_y = 0;
		int longu = 65;
		int larg = 65;
	}		t_textu;

public:
	lib_SFML();
	~lib_SFML(void);
	int moove();
	void CreateWindow();
	int Refresh(int value);
	int draw_map(map<string, int>);
	void draw_content(t_draw_data *);
	void aff_map();
	void setnewpos(t_draw_data *);
	void change_player(int, int, int, int);
	float getWidth(void);
	float getHeight(void);
	vector<stocking> spritor(string img, int *value);
	void create_menu();
	sf::Text setText(float pos_x, float pos_y, float size, string Text);
	int select_game(int value);
	void aff_menu();
	void generate_ennemy(t_draw_data *);
	void generate_laser(t_draw_data *);
	void controle_pow(t_draw_data *content, int number);
	void controle(t_draw_data *content, int number);
	int indicate_direction(int direction_receive);
	void generate_pow(t_draw_data *content);
};


extern "C" IDisplayModule *create();

extern "C" void destroy(IDisplayModule* lib_SFML);

#endif //CPP_ARCADE_GO_LIBSFML_HPP
