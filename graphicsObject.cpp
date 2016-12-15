#include "graphicsObject.h"

#include <gf/Sprite.h>

GraphicsObject::GraphicsObject(const std::string& path)
{
	//gf::Texture t;
	if (!texture.loadFromFile(path)) {
    	exit(EXIT_FAILURE);
 	}
 	//texture = std::make_unique<gf::Texture>(t);
}

GraphicsObject::GraphicsObject(GraphicsObject&& other){
	texture = std::move(other.texture);
}

GraphicsObject::~GraphicsObject()
{}

void GraphicsObject::updateSprite(gf::Sprite& sprite) const{
	sprite.setTexture(texture);
}

bool GraphicsObject::setTexture(const std::string& path){
	return texture.loadFromFile(path);
}

const gf::Texture& GraphicsObject::getTexture() const{
	return texture;
}