#pragma once
class Figure
{
public:
	Figure();
	virtual ~Figure();
	virtual double GetArea() const = 0;
	virtual double GetPerimeter() const = 0;
};