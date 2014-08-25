#pragma once

using namespace System::Windows::Forms;
using namespace System::Drawing;

ref class SierPinski
{
private:
	Pen^ pen;
	Graphics^ graphics;

	//depth is the number of recursive steps
	int depth;
public:
	SierPinski(Graphics^ graphics);
	void Draw(int depth, int width, int height);
private:
	void Draw(float x1, float y1, float x2, float y2, float x3, float y3);
	void SubTriangle(int n, float x1, float y1, float x2, float y2, float x3, float y3);

};
