#pragma once

class Circle final : public Figure
{
public:
	Circle(SPoint p, LongNum radius);
	~Circle();

	void Accept(Visitor &visitor) const override;
	virtual LongNum GetPerimeter() const override;
	virtual LongNum GetArea() const override;

private:
	LongNum m_radius;
	SPoint m_point;
	const LongNum num_pi = 314;
	const LongNum den_pi = 100;
	const LongNum two = 2;
};

