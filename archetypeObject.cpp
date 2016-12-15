#include "archetypeObject.h"

ArchetypeObject::ArchetypeObject(const GraphicsObject& g)
: graphics(g)
{}

const GraphicsObject& ArchetypeObject::getGraphics() const{
	return graphics;
}

gf::Color4f ArchetypeObject::getColor() const{
	return graphics.getColor();
}