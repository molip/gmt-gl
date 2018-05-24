#include "Window.h"
#include "MainView.h"
#include "PanelView.h"

#include "SFML/Graphics.hpp"

namespace
{
	const int PanelWidth = 300;
	const int ViewGap = 0;
}

Window::Window() : sf::RenderWindow(sf::VideoMode(), "GMT", sf::Style::Default, sf::ContextSettings())
{
	m_mainView = std::make_unique<MainView>();
	m_panelView = std::make_unique<PanelView>();

	m_views.push_back(m_mainView.get());
	m_views.push_back(m_panelView.get());
}

Window::~Window() = default;

void Window::Draw() 
{
	for (auto& view : m_views)
	{
		view->SetOrigin({});
		view->BaseDraw(*this);
	}

	display();
}

void Window::onResize()
{
	sf::IntRect windowRect(0, 0, getSize().x, getSize().y);

	sf::IntRect mainRect = windowRect;
	mainRect.left += ViewGap;
	mainRect.top += ViewGap;
	mainRect.height -= ViewGap * 2;
	mainRect.width -= PanelWidth + ViewGap * 2;
	m_mainView->SetRect(mainRect);

	sf::IntRect panelRect = windowRect;
	panelRect.width = PanelWidth;
	panelRect.left = windowRect.width - PanelWidth;
	m_panelView->SetRect(panelRect);
}

void Window::OnMouseMoved(const sf::Event::MouseMoveEvent& event)
{
	for (auto& view : m_views)
	{
		const sf::IntRect& viewRect = view->GetRect();
		if (viewRect.contains({ event.x, event.y }))
		{
			sf::Vector2f v = mapPixelToCoords({ event.x,event.y }, view->GetSFView(*this));
			//view->OnMouseMoved(sf::Event::MouseMoveEvent{ event.x - viewRect.left, event.y - viewRect.top });
			view->OnMouseMoved(v);
		}
	}
}