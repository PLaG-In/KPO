#include "stdafx.h"
#include "PerimeterVisitor.h"
#include "Circle.h"
#include "Rectangle.h"
#include "Triangle.h"

void PerimeterVisitor::Visit(Circle const& figure)
{
	m_result = figure.GetPerimeter();
}

void PerimeterVisitor::Visit(Rectangle const& figure)
{
	m_result = figure.GetPerimeter();
}

void PerimeterVisitor::Visit(Triangle const& figure)
{
	m_result = figure.GetPerimeter();
}

LongNum PerimeterVisitor::GetValue()
{
	return m_result;
}