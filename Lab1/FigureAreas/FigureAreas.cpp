// FigureAreas.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"

using namespace std;
void WorkWithFile(const string inFileName, const string outFileName)
{
	ifstream instream(inFileName);
	ofstream outstream(outFileName);
	string str;
	if (!instream)
	{
		return;
	}
	while (!instream.eof())
	{
		getline(instream, str);
		if (str.length() == 0)
		{
			return;
		}
		Parser type;
		string figure = "";
		shared_ptr<Figure> body;
		body = type.ParseString(str);
		if (type.GetFigure() == Parser::TRIANGLE)
		{
			figure = "TRIANGLE:";
		}
		if (type.GetFigure() == Parser::RECTANGLE)
		{
			figure = "RECTANGLE:";
		}
		if (type.GetFigure() == Parser::CIRCLE)
		{
			figure = "CIRCLE:";
		}
		outstream << figure << " P = " << body->GetPerimeter() << "; S = " << body->GetArea() << endl;
	}
}

int main(int argc, char* argv[])
{
	if (argc != 3)
	{
		printf("Usage: lab1 [input file], [output file]\n");
		return 1;
	}
	WorkWithFile(argv[1], argv[2]);
	return 0;
}

