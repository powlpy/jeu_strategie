#ifndef	PHYSIC_OBJECT_H
#define PHYSIC_OBJECT_H

#include "archetypeObject.h"

class PhysicObject{
	const ArchetypeObject& archetype;

	//pos

public:
	PhysicObject(const ArchetypeObject& a/*, pos*/);
};

#endif