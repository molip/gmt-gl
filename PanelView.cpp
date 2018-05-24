#include "PanelView.h"
#include "Button.h"

#include "SFML/Graphics.hpp"

#include <iostream>

PanelView::PanelView()
{
	m_children.push_back(std::make_unique<Button>());
}

void PanelView::Draw(sf::RenderWindow& window) const
{
	sf::RectangleShape rectShape;
	rectShape.setSize(sf::Vector2f((float)m_rect.width, (float)m_rect.height));
	rectShape.setFillColor(sf::Color::White);
	window.draw(rectShape);
}

void PanelView::UpdateLayout(const sf::FloatRect logRect)
{
	const int height = 30;
	const int gap = 10;

	sf::IntRect rect(gap, gap, (int)logRect.width - gap * 2, height);

	for (auto& control : m_children)
	{
		control->SetRect(rect);
		rect.top += height + gap;
	}
}

void PanelView::OnMouseMoved(const sf::Vector2f position)
{
	std::cout << position.x << ',' << position.y << std::endl;

}
