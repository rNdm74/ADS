#pragma once

using namespace System;
using namespace System::Drawing;

ref class Tree
{
private:
	Pen^ pen;
	Graphics^ graphics;
	Random^ rGen;

	int leftOffset, rightOffset;

	void draw(int depth, int x, int y, int length, int angle);

public:
	Tree(Graphics^ graphics);
	void Draw(int depth, int width, int height);
	
};
