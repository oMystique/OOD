#include "stdafx.h"
#include "Ellipse.h"

CEllipse::CEllipse(Vector2d const & pos, double verticalRadius
		, double horizontalRadius, Color const & color)
	: CShape(color)
	, m_pos(pos)
	, m_verticalRadius(verticalRadius)
	, m_horizontalRadius(horizontalRadius)
{
}

void CEllipse::Draw(ICanvas & /*canvas*/)
{
	//canvas.DrawEllipse()
}

Vector2d CEllipse::GetCenter() const
{
	return m_pos;
}

double CEllipse::GetHorizontalRadius() const
{
	return m_horizontalRadius;
}

double CEllipse::GetVerticalRadius() const
{
	return m_verticalRadius;
}
