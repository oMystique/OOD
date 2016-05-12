#pragma once
#include "IShapeFactory.h"
#include <map>
#include <functional>
#include "Definitions.h"

class CShapeFactory
	: public IShapeFactory
{
	using ActionMap = std::map<std::string, std::function<std::unique_ptr<CShape>(std::istringstream & args)>>;
public:
	CShapeFactory();

	std::unique_ptr<CShape> CreateShape(const std::string & description) override;
private:
	std::unique_ptr<CShape> CreateRectangle(std::istringstream & in);
	std::unique_ptr<CShape> CreateTriangle(std::istringstream & in);
	std::unique_ptr<CShape> CreateEllipse(std::istringstream & in);
	std::unique_ptr<CShape> CreateRegularPolygon(std::istringstream & in);
private:
	const ActionMap m_actionMap;
};	