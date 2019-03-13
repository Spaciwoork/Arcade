/*
** EPITECH PROJECT, 2018
** cpp_arcade
** File description:
** core
*/

#include "../include/Core.hpp"

void printerror(string error)
{
	cout << error << endl;
	exit(84);
}

void	launch_game(IDisplayModule *displayer, ILoadGame *gaming)
{
	int value = TOP;
	int tmp;
	map<string, int> mapper;
	t_draw_data *content = NULL;

	mapper = gaming->mapCreator(displayer->getWidth(), displayer->getHeight());
	displayer->draw_map(mapper);
	content = gaming->generateContent();
	displayer->draw_content(content);
	while (value != -1) {
		if (gaming->getGameOver() == true) {
			cout << "YOU LOST !";
			exit(0);
		}
		tmp = displayer->moove();
		if (tmp != -2)
			value = tmp;
		if (value == EXIT)
			exit(0);
		
	 	gaming->game();
		gaming->move_player(content->p, value);
	 	displayer->generate_ennemy(content);
		displayer->generate_laser(content);
		displayer->generate_pow(content);
		displayer->setnewpos(content);
		value = gaming->check_pos();
		value = displayer->Refresh(value);
	}
}

int	arcade(char *filename, char *arg2)
{
	t_core graph;
	t_core games;
	IDisplayModule *displayer;
	ILoadGame *gaming;
	int to_load;

	graph = load_graph(filename, graph);
	displayer = graph.create();
	to_load = menu(displayer);
	games = load_games(arg2, games, to_load);
	gaming = games.create_games();
	launch_game(displayer, gaming);
}

t_core	load_graph(char *filename, t_core graph)
{
	graph.handler = dlopen(filename, RTLD_LAZY);
	if (!graph.handler)
		printerror("GRAPH: Error opening lib.so " + (string)(filename));
	graph.create = (create_t *) dlsym(graph.handler, "create");
	graph.dlsym_error = dlerror();
	if (graph.dlsym_error)
		printerror("GRAPH: Error searching for symbol create");
	graph.destroy = (destroy_t *) dlsym(graph.handler, "destroy");
	graph.dlsym_error = dlerror();
	if (graph.dlsym_error)
		printerror("GRAPH: Error searching for symbol destroy");
	return (graph);
}

int	menu(IDisplayModule *displayer)
{
	int value = 5;
	displayer->CreateWindow();
	displayer->create_menu();
	while (value != -1) {
		value = displayer->select_game(value);
		if (value == 1)
			return (1);
		if (value == 2)
			return (2);
		value = displayer->Refresh(value);
	}
	exit(0);
}

t_core	load_games(char *filename, t_core games, int to_load)
{
	if (to_load == 1)
		games.handler = dlopen("games/lib_arcade_nibbler.so", RTLD_LAZY);
	else
		games.handler = dlopen("games/lib_arcade_solarfox.so", RTLD_LAZY);
	if (!games.handler)
		printerror("GAME: Error opening lib.so ");
	games.create_games = (create_us *) dlsym(games.handler, "creater");
	games.dlsym_error = dlerror();
	if (games.dlsym_error)
		printerror("GAME: Error searching for symbol creater");
	games.destroy_games = (destroy_us *) dlsym(games.handler, "destroyr");
	games.dlsym_error = dlerror();
	if (games.dlsym_error)
		printerror("GAME: Error searching for symbol destroy");
	return (games);
}