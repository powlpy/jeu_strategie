#ifndef	GAME_H
#define GAME_H

#include <vector>

#include "player.h"
#include "graphicsManager.h"
#include "objectsManager.h"

class Game{
	std::vector<Player> players; // Peut etre modifié par un Array
	ObjectsManager objectsManager;
	GraphicsManager graphicsManager;

public:
	void run();
};

#endif