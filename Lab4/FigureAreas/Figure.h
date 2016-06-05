#pragma once
#include "Visitor.h"

class Figure
{
public:
	Figure();
	virtual ~Figure();
	virtual void Accept(Visitor &visitor) const = 0;

	virtual LongNum GetArea() const;
	virtual LongNum GetPerimeter() const;

protected:
	LongNum m_perimetr = 0;
	LongNum m_area = 0;
};