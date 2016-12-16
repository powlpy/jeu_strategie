#include "vector2d.h"
#include <gf/Clock.h>
#include <gf/RenderTarget.h>

class Effect{
	Vector2d position;
	float duration;

public:
	Effect(const Vector2d pos);
	void update(float dt);
	void render(gf::RenderTarget& target) const;

	Vector2d getPosition() const{return position;}
	float getDuration() const{return duration;}
};