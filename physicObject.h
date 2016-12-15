#ifndef	PHYSIC_OBJECT_H
#define PHYSIC_OBJECT_H

#include "archetypeObject.h"

#include <gf/Vector.h>
#include <gf/Entity.h>
#include <gf/RenderTarget.h>

class PhysicObject : public gf::Entity{
	const ArchetypeObject& archetype; // peut etre un pointeur intelligent
	Vector2d position;

public:
	PhysicObject(const ArchetypeObject& a, const Vector2d& pos);
	PhysicObject(const PhysicObject& p);
	void render(gf::RenderTarget& target) const;
	void update();
	const ArchetypeObject& getArchetype() const;
	Vector2d getPosition() const;
	Vector2d getSize() const;
};

#endif