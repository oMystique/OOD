#pragma once
#include "ICanvas.h"

class CShape
{
public:
	CShape(Color const &color);
	CShape() = default;

	Color GetColor()const;

	virtual void Draw(ICanvas &canvas) { canvas; };
private:
	Color m_color;
};

