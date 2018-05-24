#include "MainView.h"
#include "Object.h"

#include "SFML/Graphics.hpp"

MainView::MainView()
{
	m_object = std::make_unique<Object>();
}

MainView::~MainView() = default;

void MainView::Draw(sf::RenderWindow& window) const
{
	//m_object->Draw(window);
}

sf::FloatRect MainView::GetLogRect() const
{
	return sf::FloatRect(0, 0, 1920, 1080);
}

sf::FloatRect MainView::GetClipRect(const sf::IntRect& rect) const
{
	sf::FloatRect clipRect = View::GetClipRect(rect);

	sf::Vector2u devSize(rect.width, rect.height);
	if (devSize.x <= 0 || devSize.y <= 0)
		return sf::FloatRect();

	sf::FloatRect logRect = GetLogRect();

	const float devAspect = devSize.x / float(devSize.y);
	const float logAspect = logRect.width / float(logRect.height);

	if (devAspect > logAspect)
		clipRect.width = clipRect.height * logAspect;
	else
		clipRect.height = clipRect.width / logAspect;

	return clipRect;
}
