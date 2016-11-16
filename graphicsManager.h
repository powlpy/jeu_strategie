#ifndef	GRAPHICS_MANAGER_H
#define GRAPHICS_MANAGER_H

#include "objectsManager.h"
#include "graphicsObject.h"

//#include <gf/ResourceManager.h>
#include <gf/RenderWindow.h>
#include <gf/Window.h>
#include <vector>

class GraphicsManager{
	const ObjectsManager& objectsManager; // peut etre un pointeur intelligent
	gf::Window window;
  	gf::RenderWindow renderer;

  	std::vector<GraphicsObject> graphicsObjects;

public:
	GraphicsManager(const ObjectsManager& om);
	gf::RenderWindow& getRenderer();
	gf::Window& getWindow();
	const std::vector<GraphicsObject>& getGraphicsObject() const;
};

#endif