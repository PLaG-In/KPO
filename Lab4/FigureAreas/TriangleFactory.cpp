#include "stdafx.h"
#include "TriangleFactory.h"
#include "Triangle.h"


shared_ptr<Figure> TriangleFactory::CreateBody(vector<ShapeParams> points) const
{
	return make_shared<Triangle>(points[0], points[1], points[2]);
}

TriangleFactory* TriangleFactory::GetInstance()
{
	if (!inst)
	{
		inst = new TriangleFactory();
	}
	return inst;
}

void TriangleFactory::DestroyInstance()
{
	if (inst)
	{
		delete inst;
		inst = nullptr;
	}
}

TriangleFactory *TriangleFactory::inst = nullptr;
