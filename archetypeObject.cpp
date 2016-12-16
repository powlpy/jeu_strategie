#include "archetypeObject.h"
#include "physicObject.h"

ArchetypeObject::ArchetypeObject(const std::string& _name, GraphicsObject&& _graphic, const Vector2d& _size, int _player)
: name(_name), 
  graphics(std::move(_graphic)), 
  size(_size), 
  player(_player)
{}

ArchetypeObject::ArchetypeObject(ArchetypeObject&& other)
: name(std::move(other.name)), 
  graphics(std::move(other.graphics)), 
  size(std::move(other.size)),
  player(other.player),
  life(other.life),
  attackContact(other.attackContact),
  reloadContact(other.reloadContact),
  speed(other.player)
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


void ArchetypeObject::addModuleLife(int _life){
	life = _life;
	module.push_back("life");
}

void ArchetypeObject::addModuleAttackContact(int _attackContact, float _reloadContact){
	attackContact = _attackContact;
	_reloadContact = _reloadContact;
	module.push_back("attackContact");
}

void ArchetypeObject::addModuleMoveable(float _speed){
	speed = _speed;
	module.push_back("moveable");
}
