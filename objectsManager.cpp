#include "objectsManager.h"

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

void ObjectsManager::addArchetype(const std::string& name, const std::string& path){
	archetypes.emplace_back(name, path);
}

const std::vector<ArchetypeObject>& ObjectsManager::getArchetypes() const{
	return archetypes;
}