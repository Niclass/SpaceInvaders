#pragma once

#include "entity.h"
#include "score.h"

extern float direction;

class Enemy : public Entity
{
public:
	Enemy(Score* score, float x, float y);
	void Update(sf::RenderWindow* window);
	void Collision(Entity* entity);
private:
	Score* score;
};