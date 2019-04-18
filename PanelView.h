#pragma once

#include "Control.h"

class PanelView : public Control
{
public:
	PanelView();

private:
	virtual void Arrange(const sf::IntRect& rect) override;
};

