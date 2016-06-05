#pragma once

class Rectangle final :public Figure
{
public:
	Rectangle(SPoint p1, SPoint p2);
	~Rectangle();

	void Accept(Visitor &visitor) const override;
	virtual LongNum GetPerimeter() const override;
	virtual LongNum GetArea() const override;
private:
	SPoint m_p1, m_p2;
	const LongNum two = 2;
};



