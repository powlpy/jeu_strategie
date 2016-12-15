#include "graphicsManager.h"


GraphicsManager::GraphicsManager(const ObjectsManager& om)
: objectsManager(om),
  window("Jeu de stratégie", { 640, 480 }), 
  renderer(window)
{
	//graphicsObjects.emplace_back("sprite.png");
}


gf::RenderWindow& GraphicsManager::getRenderer(){
	return renderer;
}

gf::Window& GraphicsManager::getWindow(){
	return window;
}
/*
const std::vector<GraphicsObject>& GraphicsManager::getGraphicsObject() const{
	return graphicsObjects;
}//*/