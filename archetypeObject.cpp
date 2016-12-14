#include "archetypeObject.h"

ArchetypeObject::ArchetypeObject(const std::string& _name, const GraphicsObject& _graphic)
: name(_name), graphics(_graphic)
{}

const std::string& ArchetypeObject::getName() const{
	return name;
}

const GraphicsObject& ArchetypeObject::getGraphics() const{
	return graphics;
}
/*
const gf::Texture& ArchetypeObject::getTexture() const{
	return graphics.getTexture();
}//*/