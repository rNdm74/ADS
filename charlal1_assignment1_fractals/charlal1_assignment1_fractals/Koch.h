#pragma once

using namespace System;
using namespace System::Drawing;

ref class Koch
{
private:
	Pen^ redPen;
	Pen^ whitePen;
	Graphics^ graphics;
	int depth;

	int width;
	int height;
	Rectangle r;

	void draw(int x1, int y1, int x5, int y5, int n);

public:
	Koch(Graphics^ graphics);
	void Draw(int depth, int width, int height);
};
