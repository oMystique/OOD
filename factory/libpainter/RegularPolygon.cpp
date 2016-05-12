#include "stdafx.h"
#include "RegularPolygon.h"

CRegularPolygon::CRegularPolygon(Vector2d const &center, unsigned vertexCount
		, double radius, Color const &color)
	: CShape(color)
	, m_center(center)
	, m_vertexCount(vertexCount)
	, m_radius(radius)
{
}

void CRegularPolygon::Draw(ICanvas & /*canvas*/)
{
}

Vector2d CRegularPolygon::GetCenter()const
{
	return m_center;
}

unsigned CRegularPolygon::GetVertexCount()const
{
	return m_vertexCount;
}

double CRegularPolygon::GetRadius()const
{
	return m_radius;
}
