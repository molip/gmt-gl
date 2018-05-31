#pragma once

#include "gmt/Window.h"

namespace GMT
{
	class View;
}

class Window : public GMT::Window
{
public:
	Window();
	virtual ~Window();

private:
	virtual void onResize() override;

	std::unique_ptr<GMT::View> m_panelView;
};
