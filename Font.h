#pragma once

#include "SFML/Graphics/Rect.hpp"
#include <memory>

namespace sf
{
	class Font;
}

class Font
{
public:
	static sf::Font& Get();

private:
	static std::unique_ptr<sf::Font> s_font;
};

