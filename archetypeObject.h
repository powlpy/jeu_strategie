#ifndef	ARCHETYPE_OBJECT_H
#define ARCHETYPE_OBJECT_H

#include "graphicsObject.h"
#include "objectsManager.h"
#include "vector2d.h"

//class ObjectsManager;
class GraphicsObject;

const int DIST_ATK_CONTACT = 30; 

class ArchetypeObject{
	std::string name;
	GraphicsObject graphics;
	Vector2d size;
	int player;
	//ObjectsManager& objectsManager;

	int life;
	int attackContact;
	float reloadContact;
	float speed;

	std::vector<std::string> module;

public:
	ArchetypeObject(const std::string& _name, GraphicsObject&& _graphic, const Vector2d& _size, int _player = 0);
	ArchetypeObject(const std::string& _name, const std::string& path, const Vector2d& _size, int _player = 0);
	ArchetypeObject(ArchetypeObject&& other);
	const std::string& getName() const;
	const GraphicsObject& getGraphics() const;
	//const gf::Texture& getTexture() const;
	Vector2d getSize() const;
	//bool createObject(const std::string& archetypeName, const Vector2d& pos) const;

	void addModuleLife(int _life);
	void addModuleAttackContact(int _attackContact, float _reloadContact);
	void addModuleMoveable(float _speed);

	int getLife() const{return life;}
	int getAttackContact() const{return attackContact;}
	float getReloadContact() const{return reloadContact;}
	float getSpeed() const{return speed;}
};

#endif