#pragma once
#include "Definitions.h"

class ICanvas
{
public:
	virtual void SetColor(Color const &color) = 0;
	virtual void DrawLine(Vector2d const &from, Vector2d const &to) = 0;
	virtual void DrawEllipse(Vector2d const &l, Vector2d const &t,
		Vector2d const &w, Vector2d const &h) = 0;

	virtual ~ICanvas() = default;
};
