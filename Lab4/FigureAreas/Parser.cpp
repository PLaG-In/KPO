#include "stdafx.h"
#include "Triangle.h"
#include "Circle.h"
#include "Rectangle.h"

#include "TriangleFactory.h"
#include "RectangleFactory.h"
#include "CircleFactory.h"
#include <string>
using namespace std;

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

string Parser::GetFigureType() const
{
	return m_figure;
}

//Parser::ShapeParams::operator SPoint()
//{
//	SPoint result = { x, y };
//	return result;
//}

shared_ptr<Figure> Parser::ParseString(string &fileStr)
{
	stringstream stream;
	stream.str(fileStr);
	string type;
	stream >> type;
	if (type == "TRIANGLE:")
	{
		m_figure = "TRIANGLE:";
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
		m_figure = "RECTANGLE:";
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
		m_figure = "CIRCLE:";
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

ShapeParams Parser::ParserPoint(string &paramsStr)
{
	vector<string> args;
	const string symbols = " ,:;CR=P";
	LongNum coords;
	ShapeParams point;
	size_t a = 0, b = 0;
	pair<vector<int>, bool> number;
	while ((b = paramsStr.find_first_not_of(symbols, a)) != paramsStr.npos)
	{
		a = paramsStr.find_first_of(symbols, b);
		args.push_back((paramsStr.substr(b, a - b)));
		b = a;
	}
	number.second = true;
	if (args.size() == 3)
	{
		number.first = coords.ToVector(args[1]);
		point.x = number;
		number.first = coords.ToVector(args[2]);
		point.y = number;
	}
	else if (args.size() == 2)
	{
		number.first = coords.ToVector(args[0]);
		point.x = number;
		number.first = coords.ToVector(args[1]);
		point.y = number;
	}
	else if (args.size() == 1)
	{
		number.first = coords.ToVector(args[0]);
		point.radius = number;
	}
	return point;
}
