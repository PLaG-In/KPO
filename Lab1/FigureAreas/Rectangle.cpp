#include "stdafx.h"
#include "Rectangle.h"

Rectangle::Rectangle(Parser::SPoint p1, Parser::SPoint p2)
	: m_p1(p1)
	, m_p2(p2)
{
}


Rectangle::~Rectangle()
{
}

double Rectangle::GetPerimeter() const
{
	return (abs(m_p1.x - m_p2.x) + abs(m_p1.y - m_p2.y)) * 2;
}

double Rectangle::GetArea() const
{
	return (abs(m_p1.x - m_p2.x) * abs(m_p1.y - m_p2.y));
}
