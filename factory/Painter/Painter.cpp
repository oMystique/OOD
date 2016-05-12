// Painter.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "../libpainter/Designer.h"
#include "../libpainter/ShapeFactory.h"
#include <sstream>

using namespace std;

int main()
{

	CShapeFactory fact;
	CDesigner designer(fact);

	string in = "rectangle 10 20 30 40 #ff0011";

	istringstream strm(in);
	auto draft = designer.CreateDraft(strm);

	for (auto it : draft)
	{
		cout << 1 << endl;
	}

	return 0;
}

