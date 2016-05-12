#pragma once
#include <sstream>

struct Color
{
	Color() = default;
	Color(int r, int g, int b)
		: r(r)
		, g(g)
		, b(b)
	{};

	int r = 0;
	int g = 0;
	int b = 0;
};

Color ConvertColorToRGBFormat(std::string const &color);

struct Vector2d
{
	double x;
	double y;
};

std::istream &operator >> (std::istream &strm, Vector2d &vec);