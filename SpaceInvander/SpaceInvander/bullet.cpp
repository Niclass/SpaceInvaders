#include "bullet.h"

Bullet::Bullet(float x, float y, float direction, bool good)
{
	this->active = 1;
	if (good)
	{
		this->groupID = 3;
	}
	else
	{
		this->groupID = 4;
	}
	this->Load("ship.png");
	this->setColor(sf::Color::White);
	this->setScale(0.25f, 0.5f);

	this->velocity.y = direction;

	this->setPosition(x - this->getGlobalBounds().width / 2, y - this->getGlobalBounds().height);
}

Bullet::Bullet(Score* score, float x, float y, float direction, bool good)
{
	this->active = 1;
	if (good)
	{
		this->groupID = 3;
	}
	else
	{
		this->groupID = 4;
	}
	this->Load("ship.png");
	this->setColor(sf::Color::White);
	this->setScale(0.25f, 0.5f);

	this->velocity.y = direction;

	this->score = score;

	this->setPosition(x - this->getGlobalBounds().width / 2, y - this->getGlobalBounds().height);
}

void Bullet::Update(sf::RenderWindow* window)
{
	if (this->getPosition().y <= 0 || this->getPosition().y + this->getGlobalBounds().height >= window->getSize().y)
	{
		if (this->GroupID() == 4)
		{
			ammo += 1;
		}
		this->Destroy();

	}
	Entity::Update(window);
}

void Bullet::Collision(Entity* entity)
{
	if (this->groupID == 3)
	{
		switch (entity->GroupID())
		{
		case 1:
		case 3:
		case 4:
			break;
		default:
			this->score->IncrementScore();
			entity->Destroy();
			this->Destroy();
			break;
		}
	}
	else if (this->groupID == 4)
	{
		switch (entity->GroupID())
		{
		case 2:
		case 3:
		case 4:
			break;
		default:
			ammo += 1;
			entity->Destroy();
			this->Destroy();
			break;
		}
	}
}