#ifndef	ARCHETYPE_OBJECT_H
#define ARCHETYPE_OBJECT_H

#include "graphicsObject.h"
#include <gf/Color.h>
#include <string>

class ArchetypeObject{
	std::string name;
	const GraphicsObject& graphics; // peut etre un pointeur intelligent

public:
	ArchetypeObject(const std::string& _name, const GraphicsObject& _graphic);
	const std::string& getName() const;
	const GraphicsObject& getGraphics() const;
	//const gf::Texture& getTexture() const;
};

#endif