#ifndef	ARCHETYPE_OBJECT_H
#define ARCHETYPE_OBJECT_H

#include "graphicsObject.h"
#include <gf/Color.h>
#include <string>

class ArchetypeObject{
	std::string name;
	GraphicsObject graphics;
	Vector2d size;

public:
	ArchetypeObject(const std::string& _name, GraphicsObject&& _graphic, const Vector2d& _size);
	ArchetypeObject(ArchetypeObject&& other);
	const std::string& getName() const;
	const GraphicsObject& getGraphics() const;
	//const gf::Texture& getTexture() const;
	Vector2d getSize() const;
};

#endif