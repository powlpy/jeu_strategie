#include "physicObject.h"
#include <gf/Sprite.h>

PhysicObject::PhysicObject(const ArchetypeObject& a, const gf::Vector2i& pos)
: archetype(a), position(pos)
{}

PhysicObject::PhysicObject(const PhysicObject& p)
: archetype(p.archetype), position(p.position)
{}

void PhysicObject::render(gf::RenderTarget& target) const{
	gf::Sprite sprite;
	sprite.setTexture(archetype.getGraphics().getTexture());
    sprite.setPosition(position);
    sprite.setAnchor(gf::Anchor::Center);
    std::cout << "a" << std::endl;
    target.draw(sprite);
    std::cout << "b" << std::endl;
}

void PhysicObject::update(){
	// TODO
}