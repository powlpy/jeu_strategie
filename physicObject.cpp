#include "physicObject.h"
#include <gf/Shapes.h>

PhysicObject::PhysicObject(const ArchetypeObject& a, const Vector2d& pos)
: archetype(a), 
  position(pos), 
  velocity(0, 0), 
  goal(pos), 
  alive(true), 
  destroyInNextTic(false),
  moving(false),
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
  moving(p.moving),
  life(p.life),
  timeReload(p.timeReload)
{}

// Déclaré à cause de plaintes du compilateur
/*PhysicObject& PhysicObject::operator=(const PhysicObject& other){
	archetype = other.getArchetype(); // not compile
	position =  other.position;
	velocity =  other.velocity;
	goal =  other.goal;
	alive =  other.alive;
	destroyInNextTic =  other.destroyInNextTic;
	timeReload =  other.timeReload;
	return *this;
}*/

void PhysicObject::render(gf::RenderTarget& target) const{
	gf::Sprite sprite;
	if(alive){
		sprite.setTexture(archetype.get().getGraphics().getTexture());
	}
	else{
		sprite.setTexture(archetype.get().getGraphics().getTexture()); // TODO
	}

	sprite.setPosition({position.x, position.y});
	sprite.setAnchor(gf::Anchor::Center);
	target.draw(sprite);
}

void PhysicObject::update(ObjectsManager& manager, float dt) {
	if(alive){
		if(timeReload >= 0.){
			timeReload -= dt;
		}
		else{
			std::vector<int> vec = manager.getRadius(position, DIST_VISION_ATK_CONTACT);
			for(const auto& i : vec){
				PhysicObject& obj = manager.getObject(i);
				if(obj.getPlayer() != 0 && obj.getPlayer() != getPlayer()){
					attack(manager, obj);
				}
			}
		}

		if(moving){
			updateVelocity();
		    position = (position + (velocity * dt * archetype.get().getSpeed())); 
		}
	}
	else{
		destroyInNextTic = true; // TODO mettre un temps de mort
	}
}

void PhysicObject::setGoal(Vector2d m_goal){
	goal = m_goal;
	moving = true;
}

void PhysicObject::updateVelocity(){
	velocity = goal - position;
	if(velocity.Magnitude() < 3){
		moving = false;
	}
	else{
		velocity = velocity.Normal();
	}
}

void PhysicObject::setVelocity(Vector2d m_velocity) {
	velocity = m_velocity;
}

const ArchetypeObject& PhysicObject::getArchetype() const{
	return archetype.get();
}

Vector2d PhysicObject::getPosition() const{
	return position;
}

Vector2d PhysicObject::getSize() const{
	return archetype.get().getSize();
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

void PhysicObject::attack(ObjectsManager& manager, PhysicObject& other){
	if((position - other.getPosition()).Magnitude() < DIST_ATK_CONTACT){
		if(timeReload <= 0.){
			other.receiveDegats(*this);
			timeReload = archetype.get().getReloadContact();
			manager.addEffect(other.getPosition());
		}
	}
	else{
		setGoal(other.getPosition());
	}
}

int PhysicObject::getPlayer() const{
	return getArchetype().getPlayer();
}
