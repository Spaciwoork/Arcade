/*
** EPITECH PROJECT, 2018
** cpp_arcade
** File description:
** solarfox
*/

#ifndef SOLARFOX_HPP_
#define SOLARFOX_HPP_

#include "../../../include/global.hpp"
#include "../../../include/player.hpp"
#include "../../../include/IDisplayModule.hpp"
#include "../../../include/ILoadGames.hpp"

#define SHOOTCYCLE 2000

class solarfox : public ILoadGame
{
public:
	// Ctor & dtor
	solarfox(void);
	~solarfox(void);

	// Getters
	player *getPlayer(void) const;
	vector<player *> *getSecondary(void) const;
	vector<player *> *getTertiary(void) const;
	vector<pair<int, int>> *getQuaternary(void) const;
	vector<player *> *getFifth(void) const;
	bool getGameOver() const;

	// Game Functions
	void game(void); // Handles enemies, lasers and missiles
	void spawner(void); // Spawns enemies
	void shoot(void); // Spawns enemies' lasers
	void launchMissile(void); // Spawns player's missiles
	vector<pair<int, int>> *genMap(void); // Spawns powerups
	void move_player(player *p, int value); // Moves the player
	int check_pos(); // Checks if the player is inside the map
	bool checkDeath(void); // Checks if the player should die
	void lasersForward(void); // Handles lasers movement
	void checkCollision(void); // Handles missile/lasers collision
	void pickPowerup(void); // Handles pickup collection
	void clearOutside(void); // Clears out of bounds lasers and missiles
	virtual map<string, int> mapCreator(float, float); // Creates data needed to print the map
	t_draw_data *generateContent(); // Returns data needed by the graphical libraries
	void action(player *, int); // Handles other inputs
};

extern "C" ILoadGame *creater();
extern "C" void destroyr(ILoadGame *solarfox);

#endif /* SOLARFOX_HPP_ */