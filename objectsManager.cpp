#include "objectsManager.h"
//#include <gf/Math.h>

void ObjectsManager::render(gf::RenderTarget &target) const{
	//entitys.render(target);
	for(auto const& i : objects){
		i.render(target);
	}
}

void ObjectsManager::addObject(const PhysicObject& o){
	objects.emplace_back(o);
	//entitys.addEntity(objects[objects.size() - 1]);
}

void ObjectsManager::addArchetype(const std::string& name, const std::string& path, const Vector2d& size){
	archetypes.emplace_back(name, path, size);
}

const std::vector<ArchetypeObject>& ObjectsManager::getArchetypes() const{
	return archetypes;
}

PhysicObject* ObjectsManager::getObjectByPosition(Vector2d pos){
	for(auto& i : objects){
		Vector2d cornerMin = i.getPosition() - i.getSize() / 2;
		Vector2d cornerMax = i.getPosition() + i.getSize() / 2;
		if(pos.x > cornerMin.x && pos.x < cornerMax.x && pos.y > cornerMin.y && pos.y < cornerMax.y)
			return &i;
	}
	return nullptr;
}

int ObjectsManager::getIdxObjectByPosition(Vector2d pos){
	int idx = 0;
	for(auto& i : objects){
		Vector2d cornerMin = i.getPosition() - i.getSize() / 2;
		Vector2d cornerMax = i.getPosition() + i.getSize() / 2;
		if(pos.x > cornerMin.x && pos.x < cornerMax.x && pos.y > cornerMin.y && pos.y < cornerMax.y)
			return idx;
		idx++;
	}
	return -1;
}

void ObjectsManager::update(float dt){
	for(auto& i : objects){
		i.update(dt);
	}
}

const ArchetypeObject& ObjectsManager::getArchetype(const std::string& name) const{
	std::cout << "o" << std::endl;
	for(auto const& i : archetypes){
		if(i.getName().compare(name) == 0)
			return i;
	}
	std::cerr << "Archetype inconnue : " << __FILE__ << " " << __LINE__ << std::endl;
	exit(EXIT_FAILURE);
}

PhysicObject& ObjectsManager::getObject(int idx){
	if(idx < 0 || idx > (int)objects.size()){
		std::cerr << "out of bound " << idx << " : " << __FILE__ << " " << __LINE__ << std::endl;
		exit(EXIT_FAILURE);
	}
	return objects[idx];
}