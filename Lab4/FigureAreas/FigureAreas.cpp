// FigureAreas.cpp: определяет точку входа для консольного приложения.
//
#include "stdafx.h"
#include "AreaVisitor.h"
#include "PerimeterVisitor.h"

using namespace std;
void WorkWithFile(const string inFileName, const string outFileName)
{
	PerimeterVisitor perimeterVisitor;
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
		shared_ptr<Figure> body;
		body = type.ParseString(str);

		PerimeterVisitor perimeterVisitor;
		body->Accept(perimeterVisitor);

		AreaVisitor areaVisitor;
		body->Accept(areaVisitor);

		outstream << type.GetFigureType() << " P = " << perimeterVisitor.GetValue().ToString() << "; S = " << areaVisitor.GetValue().ToString() << endl;
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
	cout << "Finish!" << endl;
	return 0;
}

