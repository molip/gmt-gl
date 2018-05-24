#pragma once

#include "SFML/Graphics/RenderWindow.hpp"
#include "SFML/Window/Event.hpp"

#include <memory>
#include <vector>

class View;

class Window : public sf::RenderWindow
{
public:
	Window();
	virtual ~Window();

	void Draw();

	void OnMouseMoved(const sf::Event::MouseMoveEvent& event);

private:
	virtual void onResize() override;

	std::unique_ptr<View> m_mainView;
	std::unique_ptr<View> m_panelView;
	std::vector<View*> m_views;
};

