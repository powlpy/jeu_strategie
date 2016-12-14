#include "graphicsObject.h"

GraphicsObject::GraphicsObject(const std::string& path)
{
	if (!texture.loadFromFile(path)) {
    	exit(EXIT_FAILURE);
 	}
}

const gf::Texture& GraphicsObject::getTexture() const{
	return texture;
}