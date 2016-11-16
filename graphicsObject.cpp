#include "graphicsObject.h"

GraphicsObject::GraphicsObject(const gf::Color4f& c)
: color(c)
{}

gf::Color4f GraphicsObject::getColor() const{
	//return color; // Ne s'affiche pas ou provoque un segfault, à corrigé
	return gf::Color::Blue;
}