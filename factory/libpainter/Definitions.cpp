#include "stdafx.h"
#include "Definitions.h"

using namespace std;

Color ConvertColorToRGBFormat(std::string const &color)
{
	istringstream strm(color);
	int dec;
	strm >> std::hex >> dec;

	Color rgbColor;
	rgbColor.r = dec / 0x10000;
	rgbColor.g = (dec / 0x100) % 0x100;
	rgbColor.b = dec % 0x100;

	return rgbColor;
}

std::istream &operator >> (std::istream &strm, Vector2d &vec)
{
	strm >> vec.x;
	strm >> vec.y;

	return strm;
}