#pragma once

#include "entityManager.h"
#include "gameState.h"
#include "score.h"



class mainGame : public tinyState
{
public:
	void Initialize(sf::RenderWindow* window);
	void Update(sf::RenderWindow* window);
	void Render(sf::RenderWindow* window);
	void Destroy(sf::RenderWindow* window);
private:
	Score* score;

	sf::Text* pausedText;
	sf::Font* font;
	bool paused, enterKey;

	EntityManager* manager;
};