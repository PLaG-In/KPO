#include "stdafx.h"
#include "Triangle.h"


Triangle::Triangle(Parser::SPoint p1, Parser::SPoint p2, Parser::SPoint p3)
	: m_p1(p1)
	, m_p2(p2)
	, m_p3(p3)
{
}


Triangle::~Triangle()
{
}

double Triangle::GetPerimeter() const
{
	double a, b, c;
	a = GetLineLength(m_p1, m_p2);
	b = GetLineLength(m_p2, m_p3);
	c = GetLineLength(m_p1, m_p3);
	return a + b + c;
}

double Triangle::GetArea() const
{
	double a, b, c;
	a = GetLineLength(m_p1, m_p2);
	b = GetLineLength(m_p2, m_p3);
	c = GetLineLength(m_p1, m_p3);
	double semiper = (a + b + c) / 2;
	return sqrt(semiper * (semiper - a) * (semiper - b) * (semiper - c));
}

double Triangle::GetLineLength(Parser::SPoint p1, Parser::SPoint p2)
{
	return sqrt(pow((p1.x - p2.x), 2) + pow((p1.y - p2.y), 2));
}
