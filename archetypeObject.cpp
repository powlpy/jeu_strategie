#include "archetypeObject.h"
#include "physicObject.h"

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
bool ArchetypeObject::createObject(const std::string& archetypeName, const Vector2d& pos) const{
	// SEGFAULT risque élevé
	std::cout << "a" << std::endl;
	PhysicObject obj((objectsManager.getArchetype(archetypeName)), pos);
	std::cout << "c" << std::endl;
	objectsManager.addObject(std::move(obj));
	std::cout << "ca" << std::endl;
	return true;
}//*/

/*
const gf::Texture& ArchetypeObject::getTexture() const{
	return graphics.getTexture();
}//*/

