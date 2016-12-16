#include "effect.h"
#include <gf/Shape.h>
#include <gf/Shapes.h>


Effect::Effect(const Vector2d pos)
: position(pos), duration(0.3f)
{}

void Effect::update(float dt){
	duration -= dt;
}

void Effect::render(gf::RenderTarget& target) const{
	gf::CircleShape circle({10});
      circle.setColor(gf::Color::Red);
      circle.setPosition({position.x, position.y});
      circle.setAnchor(gf::Anchor::Center);
      target.draw(circle);
}

