#pragma once

using namespace System;
using namespace System::Drawing;

ref class Koch
{
private:
	Pen^ redPen;
	Graphics^ graphics;

	void draw(int depth, int x1, int y1, int x5, int y5);

public:
	Koch(Graphics^ graphics);
	void Draw(int depth, int width, int height);
};
