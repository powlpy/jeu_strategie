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

ArchetypeObject& ObjectsManager::addArchetype(const std::string& name, const std::string& path, const Vector2d& size){
	archetypes.emplace_back(name, path, size);
	return archetypes[archetypes.size() - 1];
}
//*
void ObjectsManager::addArchetype(ArchetypeObject&& a){
	archetypes.emplace_back(std::move(a));
}//*/


const std::vector<ArchetypeObject>& ObjectsManager::getArchetypes() const{
	return archetypes;
}
/*
PhysicObject* ObjectsManager::getObjectByPosition(Vector2d pos){
	for(auto& i : objects){
		Vector2d cornerMin = i.getPosition() - i.getSize() / 2;
		Vector2d cornerMax = i.getPosition() + i.getSize() / 2;
		if(pos.x > cornerMin.x && pos.x < cornerMax.x && pos.y > cornerMin.y && pos.y < cornerMax.y)
			return &i;
	}
	return nullptr;
}//*/

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
	idxDestroyed = -1;
	int idx = 0;
	for(auto& o : objects){
		if(o.isDestroyInNextTic())
			idxDestroyed = idx;
		else
			o.update(*this, dt);
		idx++;
	}

	if(idxDestroyed >= 0){
		objects.erase(objects.begin() + idxDestroyed);
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

std::vector<int> ObjectsManager::getRadius(Vector2d pos, int radius) const{
	std::vector<int> vec;

	for(int i = 0; i != objects.size(); i++){
		if((pos - objects[i].getPosition()).Magnitude() < radius){
			vec.push_back(i);
		}
	}
	return vec;
}
/*
int ObjectsManager::getMinRadius(Vector2d pos, int radius) const{
	for(int i = 0; i != objects.size(); i++){
		if(objects[i].isAlive()){
			if((pos - objects[i].getPosition()).Magnitude() < radius){
				return i;
			}
		}
	}
	return -1;
}//*/
