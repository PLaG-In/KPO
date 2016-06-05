#include "stdafx.h"
#include "CircleFactory.h"
#include "Circle.h"


shared_ptr<Figure> CircleFactory::CreateBody(vector<ShapeParams> points) const
{
	return make_shared<Circle>(points[0], points[1].radius);
}

CircleFactory* CircleFactory::GetInstance()
{
	if (!inst)
	{
		inst = new CircleFactory();
	}
	return inst;
}

void CircleFactory::DestroyInstance()
{
	if (inst)
	{
		delete inst;
		inst = nullptr;
	}
}

CircleFactory *CircleFactory::inst = nullptr;

