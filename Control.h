#pragma once

#include "gmt/View.h"

#include "SFML/Graphics.hpp"

class Control : public GMT::View
{
protected:
	virtual void Draw(sf::RenderWindow& window) const override;
};

class ListControlVert : public Control
{
protected:
	virtual sf::Vector2i GetIdealSize(const sf::Vector2i& available) const override;
	virtual void Arrange(const sf::IntRect& rect) override;

	const int m_pad = 10;
	const int m_gap = 5;
};

class ListControl2D : public Control
{
protected:
	virtual sf::Vector2i GetIdealSize(const sf::Vector2i& available) const override;
	virtual void Arrange(const sf::IntRect& rect) override;

	const int m_pad = 10;
	const int m_gap = 5;
	const sf::Vector2i m_cellSize = { 60, 60 };
};

class ScrollerControl : public Control
{
protected:
	virtual void Arrange(const sf::IntRect& rect) override;
	virtual bool OnMouseWheel(float delta) override;

	int m_offset{};
};

