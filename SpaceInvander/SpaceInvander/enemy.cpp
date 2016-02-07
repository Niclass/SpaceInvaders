#include "enemy.h"

float direction = 0.75f;

Enemy::Enemy(Score* score, float x, float y)
{
	this->active = 1;
	this->groupID = 2;
	this->Load("enemy.png");

	this->setPosition(x - this->getGlobalBounds().width / 2, y - this->getGlobalBounds().height);

	this->score = score;
}

void Enemy::Update(sf::RenderWindow* window)
{
	if (this->velocity.x != direction)
	{
		this->move(0, 32);
	}
	this->velocity.x = direction;

	Entity::Update(window);
	if (this->getPosition().x <= 0 || this->getPosition().x + this->getGlobalBounds().width >= window->getSize().x)
	{
		direction *= -1;
		this->velocity.x = direction;

		this->move(0, 32);
		Entity::Update(window);
		Entity::Update(window);
	}
}

void Enemy::Collision(Entity* entity)
{
	switch (entity->GroupID())
	{
	case 0:
		break;
	case 3:
		this->Destroy();
		this->score->IncrementScore();
		break;
	}
}