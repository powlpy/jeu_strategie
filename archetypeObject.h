#ifndef	ARCHETYPE_OBJECT_H
#define ARCHETYPE_OBJECT_H

#include "graphicsObject.h"
#include "objectsManager.h"
#include "vector2d.h"

//class ObjectsManager;
class GraphicsObject;

class ArchetypeObject{
	std::string name;
	GraphicsObject graphics;
	Vector2d size;
	//ObjectsManager& objectsManager;

public:
	ArchetypeObject(const std::string& _name, GraphicsObject&& _graphic, const Vector2d& _size);
	ArchetypeObject(ArchetypeObject&& other);
	const std::string& getName() const;
	const GraphicsObject& getGraphics() const;
	//const gf::Texture& getTexture() const;
	Vector2d getSize() const;
	//bool createObject(const std::string& archetypeName, const Vector2d& pos) const;
};

#endif