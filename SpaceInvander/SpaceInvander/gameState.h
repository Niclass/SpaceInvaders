#pragma once

#include <SFML\Graphics.hpp>

class tinyState
{
public:
	virtual void Initialize(sf::RenderWindow* window)
	{
	}

	virtual void Update(sf::RenderWindow* window)
	{
	}

	virtual void Render(sf::RenderWindow* window)
	{
	}

	virtual void Destroy(sf::RenderWindow* window)
	{
	}
};

class gameState
{
public:
	gameState()
	{
		this->state = NULL;
	}

	void SetWindow(sf::RenderWindow* window)
	{
		this->window = window;
	}

	void SetState(tinyState* state)
	{
		if (this->state != NULL)
		{
			this->state->Destroy(this->window);
		}
		this->state = state;
		if (this->state != NULL)
		{
			this->state->Initialize(this->window);
		}
	}

	void Update()
	{
		if (this->state != NULL)
		{
			this->state->Update(this->window);
		}
	}

	void Render()
	{
		if (this->state != NULL)
		{
			this->state->Render(this->window);
		}
	}

	~gameState()
	{
		if (this->state != NULL)
		{
			this->state->Destroy(this->window);
		}
	}
private:
	sf::RenderWindow* window;
	tinyState* state;
};

extern gameState coreState;
extern bool quitGame;