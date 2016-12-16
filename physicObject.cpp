#include "physicObject.h"
#include <gf/Shapes.h>

PhysicObject::PhysicObject(const ArchetypeObject& a, const Vector2d& pos)
: archetype(a), 
  position(pos), 
  velocity(0, 0), 
  goal(pos), 
  alive(true), 
  destroyInNextTic(false), 
  life(a.getLife()),
  timeReload(0.)
{}

PhysicObject::PhysicObject(const PhysicObject& p)
: archetype(p.archetype), 
  position(p.position), 
  velocity(p.velocity), 
  goal(p.goal), 
  alive(p.alive), 
  destroyInNextTic(p.destroyInNextTic),
  timeReload(0.)
{}

// Déclaré à cause de plaintes du compilateur
PhysicObject& PhysicObject::operator=(PhysicObject other){
	//std::swap(archetype, other.archetype); // not compile
	std::swap(position, other.position);
	std::swap(velocity, other.velocity);
	std::swap(goal, other.goal);
	std::swap(alive, other.alive);
	std::swap(destroyInNextTic, other.destroyInNextTic);
	std::swap(timeReload, other.timeReload);
	return *this;
}

void PhysicObject::render(gf::RenderTarget& target) const{
	gf::Sprite sprite;
	if(alive){
		sprite.setTexture(archetype.getGraphics().getTexture());
	}
	else{
		sprite.setTexture(archetype.getGraphics().getTexture()); // TODO
	}

	sprite.setPosition({position.x, position.y});
	sprite.setAnchor(gf::Anchor::Center);
	target.draw(sprite);
}

void PhysicObject::update(float dt) {
	if(alive){
		updateVelocity();
	    position = (position + (velocity * dt * archetype.getSpeed())); 
	}
	else{
		destroyInNextTic = true; // TODO mettre un temps de mort
	}
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

bool PhysicObject::isAlive() const {
	return alive;
}

bool PhysicObject::isDestroyInNextTic() const {
	return destroyInNextTic;
}

void PhysicObject::kill() {
	alive = false;
}

void PhysicObject::receiveDegats(int degats){
	life -= degats;
	if(life <= 0){
		alive = false;
	}
}

void PhysicObject::receiveDegats(const PhysicObject& attacker/*enum type*/){
	receiveDegats(attacker.getArchetype().getAttackContact());
}