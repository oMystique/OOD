#pragma once
#include "Shape.h"

class CTriangle
	: public CShape
{
public:
	CTriangle(Vector2d const &topVertex, Vector2d const &leftVertex
			, Vector2d const &rightVertex, Color const &color);

	void Draw(ICanvas &canvas) override;

	Vector2d GetVertex1()const;
	Vector2d GetVertex2()const;
	Vector2d GetVertex3()const;
private:
	Vector2d m_topVertex;
	Vector2d m_leftVertex;
	Vector2d m_rightVertex;	
};