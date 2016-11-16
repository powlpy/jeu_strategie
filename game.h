#ifndef	GAME_H
#define GAME_H

#include "player.h"
#include "graphicsManager.h"
#include "objectsManager.h"

//#include <gf/Model.h>
#include <vector>

class Game{
	std::vector<Player> players; // Peut etre modifié par un Array
	ObjectsManager objectsManager;
	GraphicsManager graphicsManager;

public:
	Game();
	void run();
};

#endif