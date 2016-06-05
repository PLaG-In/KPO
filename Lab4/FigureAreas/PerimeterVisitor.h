#pragma once

#include "Visitor.h"
#include "LongNum.h"

class PerimeterVisitor : public Visitor
{
public:
	void Visit(Circle const& figure) override final;
	void Visit(Rectangle const& figure) override final;
	void Visit(Triangle const& figure) override final;
	LongNum GetValue();
private:
	LongNum m_result;
};
