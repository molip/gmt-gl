#include "PanelView.h"
#include "Window.h"

#include "gmt/App.h"

#include <SFML/Graphics.hpp>
#include <SFML/OpenGL.hpp>

int main()
{
	GMT::App app;

	Window window;
	window.setPosition({30, 50});
	window.setSize({ 1920 * 4 / 5 + 300, 1080 * 4 / 5 }); // TODO: Get from Window.
	window.setFramerateLimit(30);

	while (window.isOpen())
    {
		sf::Event event;
		while (window.pollEvent(event))
		{
			switch (event.type)
			{
			case sf::Event::Closed:
				window.TryClose();
				break;
			}

			window.PumpEvent(event);
		}

		window.Draw();
    }

    return EXIT_SUCCESS;
}
