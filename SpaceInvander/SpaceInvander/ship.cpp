#include "ship.h"
#include "bullet.h"

Ship::Ship(Score* score, EntityManager* manager, float x, float y)
{
	this->active = 1;
	this->groupID = 1;
	this->Load("ship.png");

	this->setPosition(x - this->getGlobalBounds().width / 2, y - this->getGlobalBounds().height);
	this->space = false;

	this->manager = manager;
	this->score = score;
}

void Ship::Update(sf::RenderWindow* window)
{
	this->velocity.x = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right) - sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left);
	if (!this->space && sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space))
	{
		this->manager->Add("bullet", new Bullet(this->score, this->getPosition().x + 16, this->getPosition().y - 5, -1, true));
	}
	this->space = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space);
	Entity::Update(window);
}

void Ship::Collision(Entity* entity)
{
}