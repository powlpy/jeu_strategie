#include "archetypeObject.h"

ArchetypeObject::ArchetypeObject(const std::string& _name, GraphicsObject&& _graphic, const Vector2d& _size)
: name(_name), graphics(std::move(_graphic)), size(_size)
{}

ArchetypeObject::ArchetypeObject(ArchetypeObject&& other)
: name(std::move(other.name)), graphics(std::move(other.graphics)), size(std::move(other.size))
{}

const std::string& ArchetypeObject::getName() const{
	return name;
}

const GraphicsObject& ArchetypeObject::getGraphics() const{
	return graphics;
}

Vector2d ArchetypeObject::getSize() const{
	return size;
}

/*
const gf::Texture& ArchetypeObject::getTexture() const{
	return graphics.getTexture();
}//*/