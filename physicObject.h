#ifndef	PHYSIC_OBJECT_H
#define PHYSIC_OBJECT_H

#include "archetypeObject.h"
#include "objectsManager.h"
#include "vector2d.h"

#include <gf/Vector.h>
#include <gf/Entity.h>
#include <gf/RenderTarget.h>

class ArchetypeObject;
class ObjectsManager;

const int DIST_ATK_CONTACT = 30;
const int DIST_VISION_ATK_CONTACT = 200;

class PhysicObject : public gf::Entity{
	const ArchetypeObject& archetype; // peut etre un pointeur intelligent
	Vector2d position;
	Vector2d velocity;
	Vector2d goal;

	bool alive;
	bool destroyInNextTic;
	bool moving;

	int life;
	float timeReload;

public:
	PhysicObject(const ArchetypeObject& a, const Vector2d& pos);
	PhysicObject(const PhysicObject& p);
	PhysicObject& operator=(PhysicObject); // Déclaré à cause de plaintes du compilateur

	void render(gf::RenderTarget& target) const;

	void update(ObjectsManager& manager, float dt);
	void setGoal(Vector2d m_goal);
	void updateVelocity();
	void setVelocity(Vector2d m_velocity);
	const ArchetypeObject& getArchetype() const;
	Vector2d getPosition() const;
	Vector2d getSize() const;
	//bool createObject(const std::string& archetypeName);

	bool isAlive() const;
	bool isDestroyInNextTic() const;
	void kill();
	void receiveDegats(int degats);
	void receiveDegats(const PhysicObject& attacker/*enum type*/);
	int getPlayer() const;
	void attack(PhysicObject& other);
};

#endif