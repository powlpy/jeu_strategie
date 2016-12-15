#ifndef	ARCHETYPE_OBJECT_H
#define ARCHETYPE_OBJECT_H

#include "graphicsObject.h"
#include <gf/Color.h>

class ArchetypeObject{
	const GraphicsObject& graphics; // peut etre un pointeur intelligent

public:
	ArchetypeObject(const GraphicsObject& g);
	const GraphicsObject& getGraphics() const;
	gf::Color4f getColor() const;
};

#endif