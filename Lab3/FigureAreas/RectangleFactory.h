#pragma once

class RectangleFactory
{
public:
	shared_ptr<Figure> CreateBody(vector<Parser::ShapeParams> points) const;
	static RectangleFactory* GetInstance();
	static void DestroyInstance();

private:
	static RectangleFactory *inst;
};

