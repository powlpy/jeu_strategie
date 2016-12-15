#include "archetypeObject.h"

ArchetypeObject::ArchetypeObject(const std::string& _name, GraphicsObject&& _graphic)
: name(_name), graphics(std::move(_graphic))
{}

ArchetypeObject::ArchetypeObject(ArchetypeObject&& other)
: name(std::move(other.name)), graphics(std::move(other.graphics))
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