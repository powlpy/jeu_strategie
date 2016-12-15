#include "physicObject.h"
#include <gf/Shapes.h>

PhysicObject::PhysicObject(const ArchetypeObject& a, const Vector2d& pos)
: archetype(a), position(pos), velocity(0, 0), goal(pos)
{}

PhysicObject::PhysicObject(const PhysicObject& p)
: archetype(p.archetype), position(p.position), velocity(p.velocity), goal(p.goal) 
{}

void PhysicObject::render(gf::RenderTarget& target) const{
	gf::Sprite sprite;
	sprite.setTexture(archetype.getGraphics().getTexture());
    sprite.setPosition({position.x, position.y});
    sprite.setAnchor(gf::Anchor::Center);
    target.draw(sprite);
}

void PhysicObject::update(float dt) {
	updateVelocity();
    position = (position + (velocity * dt * 20)); 
}

void PhysicObject::setGoal(Vector2d m_goal){
	goal = m_goal;
}

void PhysicObject::updateVelocity(){
	velocity = goal - position;
	velocity = velocity.Normal();

}

void PhysicObject::setVelocity(Vector2d m_velocity) {
	velocity = m_velocity;
}

const ArchetypeObject& PhysicObject::getArchetype() const{
	return archetype;
}

Vector2d PhysicObject::getPosition() const{
	return position;
}

Vector2d PhysicObject::getSize() const{
	return archetype.getSize();
}
/*
bool PhysicObject::createObject(const std::string& archetypeName){
	// SEGFAULT risque élevé
	return archetype.createObject(archetypeName, position + Vector2d(0, 20));
}//*/