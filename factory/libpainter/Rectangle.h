#pragma once
#include "Shape.h"

class CRectangle
	: public CShape
{
public:
	CRectangle(Vector2d const &pos, Vector2d const &bounds, Color const &color);

	void Draw(ICanvas &canvas)override;

	Vector2d GetLeftTop()const;
	Vector2d GetRighthBottom()const;
private:
	Vector2d m_pos;
	Vector2d m_bounds;
};