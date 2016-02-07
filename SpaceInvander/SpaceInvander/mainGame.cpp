#include "mainGame.h"
#include "mainMenu.h"
#include "enemy.h"
#include "ship.h"


void mainGame::Initialize(sf::RenderWindow* window)
{
	this->font = new sf::Font();
	this->font->loadFromFile("Graphics/font.ttf");
	this->score = new Score(*font, 64U);

	this->pausedText = new sf::Text("Paused\nPress Escape to Quit", *font, 64U);
	this->pausedText->setOrigin(this->pausedText->getGlobalBounds().width / 2, this->pausedText->getGlobalBounds().height / 2);
	this->pausedText->setPosition(window->getSize().x / 2, window->getSize().y / 2);

	this->paused = false;
	this->enterKey = false;

	manager = new EntityManager();
	
	this->manager->Add("ship", new Ship(this->manager, window->getSize().x / 2, window->getSize().y));
	this->manager->Add("enemy", new Enemy(this->score, 16, 32));
	this->manager->Add("enemy", new Enemy(this->score, 16 + 64, 32));
}
void mainGame::Update(sf::RenderWindow* window)
{
	if (this->paused)
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Return) && !this->enterKey)
		{
			this->paused = false;
		}
		

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape))
		{
			coreState.SetState(new mainMenu());
		}
	}
	else
	{
		this->manager->Update(window);
		this->score->Update();
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Return) && !this->enterKey)
		{
			this->paused = true;
		}
	}
}
void mainGame::Render(sf::RenderWindow* window)
{
	this->manager->Render(window);
	window->draw(*this->score);
	if(this->paused)
	{
		window->draw(*this->pausedText);
	}
}
void mainGame::Destroy(sf::RenderWindow* window)
{
	delete this->score;
	delete this->font;
	delete this->manager;
	delete this->pausedText;
}
