#include "View.h"
#include "Object.h"

#include "SFML/Graphics.hpp"

View::View()
{
}

View::~View() = default;

sf::View View::GetSFView(sf::RenderWindow& window) const
{
	sf::View view(GetLogRect());

	sf::FloatRect clipRect = GetClipRect(m_rect);
	
	const float width = float(window.getSize().x);
	const float height = float(window.getSize().y);
	view.setViewport(sf::FloatRect((m_origin.x + clipRect.left) / width, (m_origin.y + clipRect.top) / height, clipRect.width / width, clipRect.height / height));

	return view;
}

void View::SetOrigin(const sf::Vector2i& origin)
{
	m_origin = origin;

	for (auto& child : m_children)
		child->SetOrigin({ origin.x + m_rect.left, origin.y + m_rect.top });
}

void View::BaseDraw(sf::RenderWindow& window) const
{
	window.setView(GetSFView(window));

	Draw(window);

	for (auto& child : m_children)
		child->BaseDraw(window);
}

void View::SetRect(const sf::IntRect& rect)
{
	const bool sizeChanged = rect.width != m_rect.width || rect.height != m_rect.height;

	m_rect = rect;

	if (sizeChanged)
		UpdateLayout(GetLogRect());
}

sf::FloatRect View::GetLogRect() const
{
	return sf::FloatRect(0, 0, (float)m_rect.width, (float)m_rect.height);
}

sf::FloatRect View::GetClipRect(const sf::IntRect& rect) const
{
	return sf::FloatRect((float)rect.left, (float)rect.top, (float)rect.width, (float)rect.height);
}
