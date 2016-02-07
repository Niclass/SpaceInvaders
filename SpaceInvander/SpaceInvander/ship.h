#pragma once

#include "entityManager.h"

class Ship : public Entity
{
public:
	Ship(EntityManager* manager, float x, float y);
	void Update(sf::RenderWindow* window);
	void Collision(Entity* entity);
private:
	EntityManager* manager;
	bool space;
};