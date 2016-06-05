#pragma once

class Circle;
class Rectangle;
class Triangle;

class Visitor
{
public:
	virtual ~Visitor() = default;
	virtual void Visit(Circle const& figure) = 0;
	virtual void Visit(Rectangle const& figure) = 0;
	virtual void Visit(Triangle const& figure) = 0;
};
