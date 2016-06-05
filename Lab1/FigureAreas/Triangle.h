#pragma once

class Triangle final : public Figure
{
public:
	Triangle(Parser::SPoint p1, Parser::SPoint p2, Parser::SPoint p3);
	~Triangle();

	virtual double GetPerimeter() const override;
	virtual double GetArea() const override;
private:
	Parser::SPoint m_p1, m_p2, m_p3;
	static double GetLineLength(Parser::SPoint p1, Parser::SPoint p2);
};

