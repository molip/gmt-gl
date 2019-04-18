#include "Control.h"

void Control::Draw(sf::RenderWindow& window) const
{
	sf::RectangleShape rectShape;
	rectShape.setSize(sf::Vector2f((float)m_rect.width, (float)m_rect.height));
	rectShape.setFillColor(sf::Color::White);
	window.draw(rectShape);
}



sf::Vector2i ListControlVert::GetIdealSize(const sf::Vector2i& available) const
{
	int height = m_pad * 2;

	for (auto& control : m_children)
		height += control->GetIdealSize(available).y;

	return { available.x, height + m_gap * std::max(0, int(m_children.size()) - 1) };
}

void ListControlVert::Arrange(const sf::IntRect& rect)
{
	__super::Arrange(rect);

	sf::IntRect cellRect(rect.left + m_pad, rect.top + m_pad, rect.width - m_pad * 2, 0);

	for (auto& control : m_children)
	{
		cellRect.height = control->GetIdealSize({ rect.width, rect.height }).y;
		control->Arrange(cellRect);
		cellRect.top += cellRect.height + m_gap;
	}
}



sf::Vector2i ListControl2D::GetIdealSize(const sf::Vector2i& available) const
{
	const int cellsPerRow = (available.x + m_gap - m_pad * 2) / (m_cellSize.x + m_gap);
	const int rows = ((int)m_children.size() / cellsPerRow) + ((int)m_children.size() % cellsPerRow > 0);

	return { available.x, m_pad * 2 + rows * (m_cellSize.y + m_gap) - m_gap * (m_children.empty() ? 0 : 1) };
}

void ListControl2D::Arrange(const sf::IntRect& rect)
{
	__super::Arrange(rect);

	sf::IntRect cellsRect(rect.left + m_pad, rect.top + m_pad, rect.width - m_pad * 2, 0);
	sf::IntRect cellRect({ cellsRect.left, cellsRect.top }, m_cellSize);

	for (auto& control : m_children)
	{
		control->Arrange(cellRect);
		cellRect.left += cellRect.width + m_gap;
		if (cellRect.left + cellRect.width > cellsRect.left + cellsRect.width)
		{
			cellRect.left = cellsRect.left;
			cellRect.top += cellRect.height + m_gap;
		}
	}

	m_rect.height = cellRect.top - m_gap + m_pad - m_rect.top;
}



void ScrollerControl::Arrange(const sf::IntRect& rect)
{
	__super::Arrange(rect);

	const int childHeight = m_children.front()->GetIdealSize({ rect.width, rect.height }).y;

	m_offset = std::max(0, std::min(m_offset, childHeight - rect.height));

	auto childRect = rect;
	childRect.top -= m_offset;
	childRect.height = childHeight;

	m_children.front()->Arrange(childRect);
}

bool ScrollerControl::OnMouseWheel(float delta)
{
	m_offset -= int(delta * 10);
	__super::Arrange();
	return true;
}
