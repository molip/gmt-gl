#include <SFML/Graphics.hpp>
#include <SFML/OpenGL.hpp>

#include <gl/glu.h>

int main()
{
	sf::ContextSettings settings;
	sf::RenderWindow window(sf::VideoMode(1024, 768), "GMT", sf::Style::Default, settings);
	window.setFramerateLimit(30);

	while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
			if (event.type == sf::Event::Closed)
				window.close();

			if (event.type == sf::Event::KeyPressed)
				if (event.key.code == sf::Keyboard::Escape)
			       window.close();
        }

		window.display();
    }

    return EXIT_SUCCESS;
}
