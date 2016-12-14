#ifndef	GRAPHICS_OBJECT_H
#define GRAPHICS_OBJECT_H

#include <gf/Texture.h>
//#include <gf/Shape.h>
#include <gf/Color.h>
#include <string>

class GraphicsObject{
	gf::Texture texture; // plusieurs textures à l'avenir

public:
	GraphicsObject(const std::string& path);
	const gf::Texture& getTexture() const;

};

#endif