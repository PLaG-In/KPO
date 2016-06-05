#include "stdafx.h"
#include "RectangleFactory.h"
#include "Rectangle.h"


shared_ptr<Figure> RectangleFactory::CreateBody(vector<Parser::ShapeParams> points) const
{
	return make_shared<Rectangle>(points[0], points[1]);
}

RectangleFactory* RectangleFactory::GetInstance()
{
	if (!inst)
	{
		inst = new RectangleFactory();
	}
	return inst;
}

void RectangleFactory::DestroyInstance()
{
	if (inst)
	{
		delete inst;
		inst = nullptr;
	}
}

RectangleFactory *RectangleFactory::inst = nullptr;
