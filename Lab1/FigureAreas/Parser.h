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
		double radius;
	};

	enum EFigure
	{
		TRIANGLE,
		RECTANGLE,
		CIRCLE
	};

	shared_ptr<Figure> ParseString(string &fileStr);
	SPoint ParserPoint(string &paramsStr);

	EFigure GetFigure() const;

private:
	EFigure m_figure;
};

