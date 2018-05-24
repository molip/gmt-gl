#pragma once

#include "View.h"

class PanelView : public View
{
public:
	PanelView();

	virtual void Draw(sf::RenderWindow& window) const override;

private:
	virtual void UpdateLayout(const sf::FloatRect logRect) override;
	virtual void OnMouseMoved(const sf::Vector2f position) override;
};

