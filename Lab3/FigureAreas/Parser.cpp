#include "stdafx.h"
#include "Triangle.h"
#include "Circle.h"
#include "Rectangle.h"

#include "TriangleFactory.h"
#include "RectangleFactory.h"
#include "CircleFactory.h"


Parser::Parser()
	: m_figure()
{
}


Parser::~Parser()
{
	CircleFactory::DestroyInstance();
	RectangleFactory::DestroyInstance();
	TriangleFactory::DestroyInstance();
}

Parser::EFigure Parser::GetFigure() const
{
	return m_figure;
}

Parser::ShapeParams::operator SPoint()
{
	SPoint result = { x, y };
	return result;
}

shared_ptr<Figure> Parser::ParseString(string &fileStr)
{
	stringstream stream;
	stream.str(fileStr);
	string type;
	stream >> type;
	if (type == "TRIANGLE:")
	{
		m_figure = TRIANGLE;
		vector<ShapeParams> points;
		while (points.size() != 3)
		{
			string paramsStr;
			stream >> paramsStr;
			points.push_back(ParserPoint(paramsStr));
		}
		return TriangleFactory::GetInstance()->CreateBody(points);
		//return make_shared<Triangle>(points[0], points[1], points[2]);
	}
	if (type == "RECTANGLE:")
	{
		m_figure = RECTANGLE;
		vector<ShapeParams> points;
		while (points.size() != 2)
		{
			string paramsStr;
			stream >> paramsStr;
			points.push_back(ParserPoint(paramsStr));
		}
		return RectangleFactory::GetInstance()->CreateBody(points);
		//return make_shared<Rectangle>(points[0], points[1]);
	}
	if (type == "CIRCLE:")
	{
		m_figure = CIRCLE;
		vector<ShapeParams> points;
		while (points.size() != 2)
		{
			string paramsStr;
			stream >> paramsStr;
			points.push_back(ParserPoint(paramsStr));
		}
		return CircleFactory::GetInstance()->CreateBody(points);
		//return make_shared<Circle>(points[0], points[1].radius);
	}
	return nullptr;
}

Parser::ShapeParams Parser::ParserPoint(string &paramsStr)
{
	vector<int> args;
	ShapeParams point;
	const string symbols = " ,:;CR=P";
	size_t e, b;
	e = 0;
	while ((b = paramsStr.find_first_not_of(symbols, e)) != paramsStr.npos)
	{
		e = paramsStr.find_first_of(symbols, b);
		args.push_back(stoi(paramsStr.substr(b, e - b)));
		b = e;
	}
	if (args.size() == 3)
	{
		point.x = args[1];
		point.y = args[2];
	}
	else if (args.size() == 2)
	{
		point.x = args[0];
		point.y = args[1];
	}
	else if (args.size() == 1)
	{
		point.radius = args[0];
	}
	return point;
}
