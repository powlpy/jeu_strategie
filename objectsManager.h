#ifndef	OBJECTS_MANAGER_H
#define OBJECTS_MANAGER_H

#include "physicObject.h"

#include <vector>
#include <gf/EntityContainer.h>
#include <gf/RenderTarget.h>
#include <gf/Math.h>

class ObjectsManager{
	std::vector<PhysicObject> objects; // le type peut etre changé
	gf::EntityContainer entitys; // héritage ??? doublon ???
	std::vector<ArchetypeObject> archetypes; // le type peut etre changé

public:
	void render(gf::RenderTarget &target) const;
	void addObject(const PhysicObject& o);
	void addArchetype(const std::string& name, const std::string& path, const Vector2d& size);
	const std::vector<ArchetypeObject>& getArchetypes() const;

	PhysicObject* getObjectByPosition(Vector2d pos);
};

#endif