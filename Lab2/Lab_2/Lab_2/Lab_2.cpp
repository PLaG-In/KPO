// Lab_2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "LongNum.h"

using namespace std;

void WorkWithFile(const string &inFileName, const string &outFileName)
{
	ifstream instream(inFileName);
	ofstream outstream(outFileName);
	string  num1, num2;
	LongNum result;
	
	char op;
	if (!instream)
	{
		return;
	}
	while (!instream.eof())
	{
		instream >> num1;
		instream >> op;
		instream >> num2;
		pair<vector<int>, bool> vnum1, vnum2;
		vnum1.first = LongNum::ToVector(num1);
		vnum1.second = true;
		vnum2.first = LongNum::ToVector(num2);
		vnum2.second = true;
		switch (op)
		{
		case '+':
			result = (LongNum(vnum1) + LongNum(vnum2));
			break;
		case '-':
			result = (LongNum(vnum1) - LongNum(vnum2));
			break;
		case '*':
			result = (LongNum(vnum1) * LongNum(vnum2));
			break;
		case '/':
			try
			{
				result = (LongNum(vnum1) / LongNum(vnum2));
				break;
			}
			catch(runtime_error)
			{
				string error = "Error: Division by 0!";
				outstream << error << endl;
				continue;
			}
		}
		outstream << num1 << " " << op << " " << num2 << " = " << result.ToString() << endl;
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

