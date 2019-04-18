#include "PanelView.h"
#include "Button.h"

#include "SFML/Graphics.hpp"

#include <iostream>


PanelView::PanelView()
{
	auto& scroller = AddChild(std::make_unique<ScrollerControl>());
	auto& list = scroller.AddChild(std::make_unique<ListControlVert>());
	
	for (int i = 0; i < 30; ++i)
		list.AddChild(std::make_unique<Button>());
}

void PanelView::Arrange(const sf::IntRect& rect)
{
	__super::Arrange(rect);

	const int pad = 10;

	sf::IntRect cellRect(rect.left + pad, rect.top + pad, rect.width - pad * 2, rect.height - pad * 2);

	m_children.front()->Arrange(cellRect);
}
