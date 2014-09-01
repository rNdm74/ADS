#pragma once

using namespace System;
using namespace System::Drawing;

ref class Tree
{
private:
	Pen^ pen;
	Graphics^ graphics;
	int depth;
	void draw(double x, double y, double length, double angle);

public:
	Tree(Graphics^ graphics);
	void Draw(int depth, int width, int height);
	
};
