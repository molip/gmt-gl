#include "Button.h"
#include "Font.h"

#include "SFML/Graphics.hpp"

Button::Button()
{
}

void Button::Draw(sf::RenderWindow& window) const
{
	sf::RectangleShape rectShape;
	rectShape.setSize(sf::Vector2f((float)m_rect.width, (float)m_rect.height));
	rectShape.setFillColor(sf::Color(192, 192, 192));
	rectShape.setOutlineColor(sf::Color(128, 128, 128));
	rectShape.setOutlineThickness(1);
	window.draw(rectShape);

	sf::Text text("Hello", Font::Get());
	text.setCharacterSize(m_rect.height - 8);
	text.setColor(sf::Color::Black);

	sf::FloatRect bounds = text.getLocalBounds();
	text.setPosition((m_rect.width - bounds.width) / 2, (m_rect.height - bounds.height) / 2 - bounds.top);
	window.draw(text);
}
