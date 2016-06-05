#pragma once

struct SPoint
{
	LongNum x;
	LongNum y;
};

struct ShapeParams
{
	LongNum x;
	LongNum radius;
	LongNum y;

	operator SPoint();
};