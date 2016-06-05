#pragma once


class TriangleFactory
{
public:
	std::shared_ptr<Figure> CreateBody(vector<Parser::ShapeParams> points) const;
	static TriangleFactory* GetInstance();
	static void DestroyInstance();

private:
	static TriangleFactory *inst;
};