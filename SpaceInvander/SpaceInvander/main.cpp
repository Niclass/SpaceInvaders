#include <Windows.h>
#include "gameState.h"
#include "mainMenu.h"

gameState coreState;
bool quitGame = false;

int main()
{
	sf::RenderWindow window(sf::VideoMode(1280, 720), "PongPing");

	tinyState state;
	coreState.SetWindow(&window);
	coreState.SetState(new mainMenu());

	// run the program as long as the window is open
	while (window.isOpen())
	{
		// check all the window's events that were triggered since the last iteration of the loop
		sf::Event event;
		while (window.pollEvent(event))
		{
			// "close requested" event: we close the window
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear(sf::Color::Black);
		coreState.Update();
		coreState.Render();

		window.display();

		if (quitGame)
		{
			window.close();
		}
		Sleep(3);
	}

	return 0;
}