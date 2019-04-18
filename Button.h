#pragma once

#include "Control.h"

class Button : public Control
{
public:
	Button();
	virtual void Draw(sf::RenderWindow& window) const;
	virtual sf::Vector2i GetIdealSize(const sf::Vector2i& available) const override;

protected:

private:
};

