#include "stdafx.h"
#include "AreaVisitor.h"
#include "Circle.h"
#include "Triangle.h"
#include "Rectangle.h"
#include "PerimeterVisitor.h"

void AreaVisitor::Visit(Circle const& figure)
{
	m_result = figure.GetArea();
}

void AreaVisitor::Visit(Rectangle const& figure)
{
	m_result = figure.GetArea();
}

void AreaVisitor::Visit(Triangle const& figure)
{
	m_result = figure.GetArea();
}

LongNum AreaVisitor::GetValue()
{
	return m_result;
}