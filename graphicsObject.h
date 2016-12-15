#ifndef	GRAPHICS_OBJECT_H
#define GRAPHICS_OBJECT_H

#include <gf/Texture.h>
//#include <gf/Shape.h>
#include <gf/Color.h>
#include <string>
#include <iostream>
#include <gf/Sprite.h>

class GraphicsObject{
	//std::unique_ptr<gf::Texture> texture;
	gf::Texture texture;

public:
	GraphicsObject();
	GraphicsObject(const std::string& path);
	GraphicsObject(GraphicsObject&& other);
	~GraphicsObject();
	bool setTexture(const std::string& path);
	void updateSprite(gf::Sprite& sprite) const;
	const gf::Texture& getTexture() const;
};

#endif