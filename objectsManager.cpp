#include "objectsManager.h"
//#include <gf/Math.h>

void ObjectsManager::render(gf::RenderTarget &target) const{
	//entitys.render(target);
	for(auto const& i : objects){
		i.render(target);
	}
}

void ObjectsManager::addObject(const PhysicObject& o){
	objects.push_back(o);
	entitys.addEntity(objects[objects.size() - 1]);
}

void ObjectsManager::addArchetype(const std::string& name, const std::string& path, const Vector2d& size){
	archetypes.emplace_back(name, path, size);
}

const std::vector<ArchetypeObject>& ObjectsManager::getArchetypes() const{
	return archetypes;
}

PhysicObject* ObjectsManager::getObjectByPosition(Vector2d pos){
	for(auto const& i : objects){
		gf::Vector2f cornerMin = i.getPosition() - i.getSize() / 2;
		gf::Vector2f cornerMax = i.getPosition() + i.getSize() / 2;
		if(pos.x > cornerMin.x && pos.x < cornerMax.x && pos.y > cornerMin.y && pos.y <_cornerMax.y)
			return &i;
	}
	return nullptr;
}