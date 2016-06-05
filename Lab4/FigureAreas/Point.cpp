#include "stdafx.h"
#include "Point.h"


ShapeParams::operator SPoint()
{
	SPoint result = { x, y };
	return result;
}