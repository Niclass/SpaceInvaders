#include "bullet.h"

Bullet::Bullet(float x, float y, float direction)
{
	this->active = 1;
	this->groupID = 3;
	this->Load("ship.png");
	this->setColor(sf::Color::White);
	this->setScale(0.25f, 0.5f);

	this->velocity.y = direction;

	this->setPosition(x - this->getGlobalBounds().width / 2, y - this->getGlobalBounds().height);
}

void Bullet::Update(sf::RenderWindow* window)
{
	if (this->getPosition().y <= 0 || this->getPosition().y + this->getGlobalBounds().height >= window->getSize().y)
	{
		this->Destroy();
	}
	Entity::Update(window);
}

void Bullet::Collision(Entity* entity)
{
	switch (entity->GroupID())
	{
	case 3:
		break;
	default:
		this->Destroy();
		break;
	}
}