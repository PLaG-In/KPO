#pragma once

class Rectangle final :public Figure
{
public:
	Rectangle(Parser::SPoint p1, Parser::SPoint p2);
	~Rectangle();
	virtual double GetPerimeter() const override;
	virtual double GetArea() const override;
private:
	Parser::SPoint m_p1, m_p2;

};



