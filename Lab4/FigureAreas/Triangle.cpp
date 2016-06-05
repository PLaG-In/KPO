#include "stdafx.h"
#include "Triangle.h"


Triangle::Triangle(SPoint p1, SPoint p2, SPoint p3)
	: m_p1(p1)
	, m_p2(p2)
	, m_p3(p3)
{
}


Triangle::~Triangle()
{
}

void Triangle::Accept(Visitor &visitor) const
{
	return visitor.Visit(*this);
}

LongNum Triangle::GetPerimeter() const
{
	LongNum a, b, c;
	a = GetLineLength(m_p1, m_p2);
	b = GetLineLength(m_p2, m_p3);
	c = GetLineLength(m_p1, m_p3);
	return a + b + c;
}

LongNum Triangle::GetArea() const
{
	LongNum a, b, c;
	a = GetLineLength(m_p1, m_p2);
	b = GetLineLength(m_p2, m_p3);
	c = GetLineLength(m_p1, m_p3);
	LongNum semiper = (a + b + c) / two;
	return Sqrt(semiper * (semiper - a) * (semiper - b) * (semiper - c));
}

LongNum Triangle::GetLineLength(SPoint p1, SPoint p2)
{
	return Sqrt(Sqr((p1.x - p2.x)) + Sqr((p1.y - p2.y)));
}
