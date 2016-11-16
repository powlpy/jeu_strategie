#ifndef	OBJECTS_MANAGER_H
#define OBJECTS_MANAGER_H

#include "physicObject.h"

#include <vector>
#include <gf/EntityContainer.h>
#include <gf/RenderTarget.h>

class ObjectsManager{
	std::vector<PhysicObject> objects; // le type peut etre changé
	gf::EntityContainer entitys; // héritage ??? doublon ???
	std::vector<ArchetypeObject> archetypes; // le type peut etre changé

public:
	void render(gf::RenderTarget &target) const;
	void addObject(const PhysicObject& o);
	void addArchetype(const ArchetypeObject& a);
};

#endif