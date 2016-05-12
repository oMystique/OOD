#pragma once
#include "Shape.h"

class CRegularPolygon
	:public CShape
{
public:
	CRegularPolygon(Vector2d const &center, unsigned vertexCount
		, double radius, Color const &color);

	void Draw(ICanvas &canvas)override;

	Vector2d GetCenter()const;
	unsigned GetVertexCount()const;
	double GetRadius()const;
private:
	Vector2d m_center;
	unsigned m_vertexCount;
	double m_radius;
};