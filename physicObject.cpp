#include "physicObject.h"
#include <gf/Sprite.h>

PhysicObject::PhysicObject(const ArchetypeObject& a, const Vector2d& pos)
: archetype(a), position(pos)
{}

PhysicObject::PhysicObject(const PhysicObject& p)
: archetype(p.archetype), position(p.position)
{}

void PhysicObject::render(gf::RenderTarget& target) const{
	gf::Sprite sprite;
	sprite.setTexture(archetype.getGraphics().getTexture());
    sprite.setPosition({position.x, position.y});
    sprite.setAnchor(gf::Anchor::Center);
    target.draw(sprite);
}

void PhysicObject::update(){
	// TODO
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
