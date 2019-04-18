#include "Window.h"
#include "PanelView.h"

#include "SFML/Graphics.hpp"

#include <iostream>

namespace
{
	const int PanelWidth = 300;
	const int ViewGap = 0;
}

Window::Window() 
{
	m_panelView = std::make_unique<PanelView>();

	m_views.push_back(m_panelView.get());
}

Window::~Window() = default;

void Window::onResize()
{
	sf::IntRect windowRect(0, 0, getSize().x, getSize().y);

	sf::IntRect mainRect = windowRect;
	mainRect.left += ViewGap;
	mainRect.top += ViewGap;
	mainRect.height -= ViewGap * 2;
	mainRect.width -= PanelWidth + ViewGap * 2;
	m_mainView->Arrange(mainRect);

	sf::IntRect panelRect = windowRect;
	panelRect.width = PanelWidth;
	panelRect.left = windowRect.width - PanelWidth;
	m_panelView->Arrange(panelRect);
}
