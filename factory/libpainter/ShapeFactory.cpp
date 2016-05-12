#include "stdafx.h"
#include "ShapeFactory.h"
#include "Rectangle.h"
#include "Triangle.h"
#include "Ellipse.h"
#include "RegularPolygon.h"

using namespace std;
using namespace std::placeholders;

CShapeFactory::CShapeFactory()
	: m_actionMap
	({
		{"rectangle", bind(&CShapeFactory::CreateRectangle, this, _1)},
		{"triangle", bind(&CShapeFactory::CreateTriangle, this, _1)},
		{"ellipse", bind(&CShapeFactory::CreateEllipse, this, _1)},
		{"regular_polygon", bind(&CShapeFactory::CreateRegularPolygon, this, _1)}
	})
{
}

unique_ptr<CShape> CShapeFactory::CreateShape(const string & description)
{
	string shape;
	istringstream strm(description);
	strm >> shape;
	
	auto it = m_actionMap.find(shape);
	if (it != m_actionMap.end())
	{
		return it->second(strm);
	}

	return nullptr;
}

unique_ptr<CShape> CShapeFactory::CreateRectangle(istringstream & in)
{
	Vector2d pos;
	Vector2d size;
	string color;

	in >> pos >> size >> color;

	return make_unique<CRectangle>(pos, size, ConvertColorToRGBFormat(color));
}

unique_ptr<CShape> CShapeFactory::CreateTriangle(istringstream & in)
{
	Vector2d vertex1;
	Vector2d vertex2;
	Vector2d vertex3;
	string color;

	in >> vertex1 >> vertex2 >> vertex3 >> color;

	return make_unique<CTriangle>(vertex1, vertex2, vertex3, ConvertColorToRGBFormat(color));
}

unique_ptr<CShape> CShapeFactory::CreateEllipse(istringstream & in)
{
	Vector2d pos;
	double verticalRadius;
	double horizontalRadius;
	string color;

	in >> pos >> verticalRadius >> horizontalRadius >> color;

	return make_unique<CEllipse>(pos, verticalRadius, horizontalRadius, ConvertColorToRGBFormat(color));
}

unique_ptr<CShape> CShapeFactory::CreateRegularPolygon(istringstream & in)
{
	Vector2d center;
	unsigned vertexCount;
	double radius;
	string color;

	in >> center >> vertexCount >> radius >> color;

	return make_unique<CRegularPolygon>(center, vertexCount, radius, ConvertColorToRGBFormat(color));
}
