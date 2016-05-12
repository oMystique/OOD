#include "stdafx.h"
#include "Triangle.h"

CTriangle::CTriangle(Vector2d const &topVertex, Vector2d const &leftVertex
		, Vector2d const &rightVertex, Color const &color) 
	: CShape(color)
	, m_topVertex(topVertex)
	, m_leftVertex(leftVertex)
	, m_rightVertex(rightVertex)
{
}

void CTriangle::Draw(ICanvas & /*canvas*/)
{
}

Vector2d CTriangle::GetVertex1() const
{
	return m_topVertex;
}

Vector2d CTriangle::GetVertex2() const
{
	return m_leftVertex;
}

Vector2d CTriangle::GetVertex3() const
{
	return m_rightVertex;
}

