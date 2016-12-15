#ifndef	PHYSIC_OBJECT_H
#define PHYSIC_OBJECT_H

#include "archetypeObject.h"
#include "vector2d.h"


#include <gf/Vector.h>
#include <gf/Entity.h>
#include <gf/RenderTarget.h>
#include "vector2d.h"

class ArchetypeObject;

class PhysicObject : public gf::Entity{
	const ArchetypeObject& archetype; // peut etre un pointeur intelligent
	Vector2d position;
	Vector2d velocity;
	Vector2d goal;


public:
	PhysicObject(const ArchetypeObject& a, const Vector2d& pos);
	PhysicObject(const PhysicObject& p);
	void render(gf::RenderTarget& target) const;

	void update(float dt);
	void setGoal(Vector2d m_goal);
	void updateVelocity();
	void setVelocity(Vector2d m_velocity);
	const ArchetypeObject& getArchetype() const;
	Vector2d getPosition() const;
	Vector2d getSize() const;
	//bool createObject(const std::string& archetypeName);
};

#endif