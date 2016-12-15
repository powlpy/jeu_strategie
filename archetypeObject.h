#ifndef	ARCHETYPE_OBJECT_H
#define ARCHETYPE_OBJECT_H

#include "graphicsObject.h"
#include <gf/Color.h>
#include <string>

class ArchetypeObject{
	std::string name;
	GraphicsObject graphics;

public:
	ArchetypeObject(const std::string& _name, GraphicsObject&& _graphic);
	ArchetypeObject(ArchetypeObject&& other);
	const std::string& getName() const;
	const GraphicsObject& getGraphics() const;
	//const gf::Texture& getTexture() const;
};

#endif