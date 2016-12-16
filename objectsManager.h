#ifndef	OBJECTS_MANAGER_H
#define OBJECTS_MANAGER_H

#include "physicObject.h"

#include <vector>
#include <gf/EntityContainer.h>
#include <gf/RenderTarget.h>
#include "vector2d.h"

class PhysicObject;
class ArchetypeObject;

class ObjectsManager{
	std::vector<PhysicObject> objects; // le type peut etre changé
	//gf::EntityContainer entitys; // héritage ??? doublon ???
	std::vector<ArchetypeObject> archetypes; // le type peut etre changé

public:
	void render(gf::RenderTarget &target) const;
	void addObject(const PhysicObject& o);
	ArchetypeObject& addArchetype(const std::string& name, const std::string& path, const Vector2d& size);
	//void addArchetype(ArchetypeObject&& a);
	const std::vector<ArchetypeObject>& getArchetypes() const;
	const ArchetypeObject& getArchetype(const std::string& name) const;

	//PhysicObject* getObjectByPosition(Vector2d pos);
	int getIdxObjectByPosition(Vector2d pos);
	PhysicObject& getObject(int idx);
	void update(float dt);
};

#endif