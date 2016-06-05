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

	struct SPoint
	{
		int x;
		int y;
	};

	struct ShapeParams
	{
		union {
			int x;
			int radius;
		};
		int y;

		operator SPoint();
	};

	enum EFigure
	{
		TRIANGLE,
		RECTANGLE,
		CIRCLE
	};

	shared_ptr<Figure> ParseString(string &fileStr);
	ShapeParams ParserPoint(string &paramsStr);

	EFigure GetFigure() const;

private:
	EFigure m_figure;
};

