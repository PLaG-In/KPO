#pragma once

class Circle final : public Figure
{
public:
	Circle(Parser::SPoint p, double radius);
	~Circle();

	virtual double GetPerimeter() const override;
	virtual double GetArea() const override;

private:
	double m_radius;
	Parser::SPoint m_point;
	const double pi = 3.14159265;
};

