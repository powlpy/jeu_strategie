#ifndef	PHYSIC_OBJECT_H
#define PHYSIC_OBJECT_H

#include "archetypeObject.h"

#include <gf/Vector.h>
#include <gf/Entity.h>
#include <gf/RenderTarget.h>

class PhysicObject : public gf::Entity{
	const ArchetypeObject& archetype; // peut etre un pointeur intelligent
	gf::Vector2f position;
	gf::Vector2f velocity;
	gf::Vector2f goal;


public:
	PhysicObject(const ArchetypeObject& a, const gf::Vector2f& pos);
	PhysicObject(const PhysicObject& p);
	void render(gf::RenderTarget& target) const;
	void update(float dt);
	void setGoal(gf::Vector2f m_goal);
	void updateVelocity();
	void setVelocity(gf::Vector2f m_velocity);
};

#endif