#ifndef	PHYSIC_OBJECT_H
#define PHYSIC_OBJECT_H

#include "archetypeObject.h"

#include <gf/Vector.h>
#include <gf/Entity.h>
#include <gf/RenderTarget.h>

class PhysicObject : public gf::Entity{
	const ArchetypeObject& archetype; // peut etre un pointeur intelligent
	gf::Vector2i position;

public:
	PhysicObject(const ArchetypeObject& a, const gf::Vector2i& pos);
	PhysicObject(const PhysicObject& p);
	void render(gf::RenderTarget& target) const;
	void update();
};

#endif