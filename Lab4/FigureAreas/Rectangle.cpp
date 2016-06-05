#include "stdafx.h"
#include "Rectangle.h"

Rectangle::Rectangle(SPoint p1, SPoint p2)
	: m_p1(p1)
	, m_p2(p2)
{
}


Rectangle::~Rectangle()
{
}

void Rectangle::Accept(Visitor &visitor) const
{
	return visitor.Visit(*this);
}

LongNum Rectangle::GetPerimeter() const
{
	return ((m_p1.x - m_p2.x) + (m_p1.y - m_p2.y)) * two;
}

LongNum Rectangle::GetArea() const
{
	return ((m_p1.x - m_p2.x) * (m_p1.y - m_p2.y));
}
