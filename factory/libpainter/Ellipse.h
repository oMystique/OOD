#pragma once
#include "Shape.h"


class CEllipse
	:public CShape
{
public:
	CEllipse(Vector2d const &pos, double verticalRadius
		, double horizontalRadius, Color const &color);

	void Draw(ICanvas &canvas)override;

	Vector2d GetCenter()const;
	double GetHorizontalRadius()const;
	double GetVerticalRadius()const;
private:
	Vector2d m_pos;
	double m_verticalRadius;
	double m_horizontalRadius;
};