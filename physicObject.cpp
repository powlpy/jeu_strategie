#include "physicObject.h"
#include <gf/Shapes.h>

PhysicObject::PhysicObject(const ArchetypeObject& a, const gf::Vector2i& pos)
: archetype(a), position(pos)
{}

PhysicObject::PhysicObject(const PhysicObject& p)
: archetype(p.archetype), position(p.position)
{}

void PhysicObject::render(gf::RenderTarget& target) const{
	gf::RectangleShape shape({ 20.f, 20.f });
    shape.setPosition(position);
    shape.setColor(archetype.getColor());
    shape.setAnchor(gf::Anchor::Center);
    target.draw(shape);
}

void PhysicObject::update(){
	// TODO
}