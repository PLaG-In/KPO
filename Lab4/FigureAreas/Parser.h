#pragma once
using namespace std;
#include <string>
#include <memory>
#include "Figure.h"
class Parser
{
public:
	Parser();
	virtual ~Parser();

	//struct SPoint
	//{
	//	LongNum x;
	//	LongNum y;
	//};

	//struct ShapeParams
	//{
	//	LongNum x;
	//	LongNum radius;
	//	LongNum y;

	//	operator SPoint();
	//};

	/*enum EFigure
	{
		TRIANGLE,
		RECTANGLE,
		CIRCLE
	};*/

	shared_ptr<Figure> ParseString(string &fileStr);
	ShapeParams ParserPoint(string &paramsStr);

	string GetFigureType() const;

private:
	string m_figure;
};

