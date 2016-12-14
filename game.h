#ifndef	GAME_H
#define GAME_H

#include "player.h"
#include "graphicsManager.h"
#include "objectsManager.h"

//#include <gf/Model.h>
#include <vector>

class Game{
	std::array<Player, 2> players;
	ObjectsManager objectsManager;
	GraphicsManager graphicsManager;

public:
	Game();
	void run();
};

#endif