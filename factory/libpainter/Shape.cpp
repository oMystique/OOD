#include "stdafx.h"
#include "Shape.h"

CShape::CShape(Color const & color)
	: m_color(color)
{
}

Color CShape::GetColor()const
{
	return m_color;
}
