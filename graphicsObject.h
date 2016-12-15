#ifndef	GRAPHICS_OBJECT_H
#define GRAPHICS_OBJECT_H

#include <gf/Texture.h>
//#include <gf/Shape.h>
#include <gf/Color.h>

class GraphicsObject{
	//gf::Texture texture; // plusieurs textures à l'avenir
	gf::Color4f color; // temporaire

public:
	GraphicsObject(const gf::Color4f& c);
	gf::Color4f getColor() const;

};

#endif