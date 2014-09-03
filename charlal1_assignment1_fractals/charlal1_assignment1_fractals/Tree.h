#pragma once

using namespace System;
using namespace System::Drawing;

static const double lScale  = 0.75;
static const double rScale  = 0.66;
static const int	lOffset = 30;
static const int	rOffset = 50;

ref class Tree
{
private:
	Pen^ pen;
	Graphics^ graphics;

	void draw(int depth, int x, int y, int length, int angle);

public:
	Tree(Graphics^ graphics);
	void Draw(int depth, int width, int height);
};
