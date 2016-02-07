#pragma once

#include "entity.h"


class Bullet : public Entity
{
public:
	Bullet(float x, float y, float direction);
	void Update(sf::RenderWindow* window);
	void Collision(Entity* entity);
private:
};