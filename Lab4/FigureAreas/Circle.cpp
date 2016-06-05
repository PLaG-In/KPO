#include "stdafx.h"
#include "Circle.h"


Circle::Circle(SPoint p, LongNum radius)
	: m_radius(radius)
	, m_point(p)
{
}


Circle::~Circle()
{
}

void Circle::Accept(Visitor &visitor) const
{
	return visitor.Visit(*this);
}

LongNum Circle::GetPerimeter() const
{
	return two * num_pi * m_radius / den_pi;
}

LongNum Circle::GetArea() const
{
	return num_pi * Sqr(m_radius) / den_pi;
}