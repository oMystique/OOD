#include "stdafx.h"
#include "Rectangle.h"

CRectangle::CRectangle(Vector2d const & pos, Vector2d const & bounds, Color const & color)
	: CShape(color)
	, m_pos(pos)
	, m_bounds(bounds)
{
}

void CRectangle::Draw(ICanvas & /*canvas*/)
{
}

Vector2d CRectangle::GetLeftTop() const
{
	return m_pos;
}

Vector2d CRectangle::GetRighthBottom()const
{
	return m_bounds;
}
