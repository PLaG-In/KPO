#include "stdafx.h"
#include "Circle.h"


Circle::Circle(Parser::SPoint p, double radius)
	: m_radius(radius)
	, m_point(p)
{
}


Circle::~Circle()
{
}

double Circle::GetPerimeter() const
{
	return 2 * pi * m_radius;
}

double Circle::GetArea() const
{
	return pi * pow(m_radius, 2);
}