#pragma once

class Triangle final : public Figure
{
public:
	Triangle(SPoint p1, SPoint p2, SPoint p3);
	~Triangle();

	void Accept(Visitor &visitor) const override;
	virtual LongNum GetPerimeter() const override;
	virtual LongNum GetArea() const override;
private:
	SPoint m_p1, m_p2, m_p3;
	static LongNum GetLineLength(SPoint p1, SPoint p2);
	const LongNum two = 2;
};

