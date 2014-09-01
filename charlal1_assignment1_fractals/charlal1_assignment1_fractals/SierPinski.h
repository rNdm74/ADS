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
	void DrawTriangle(int depth, int width, int height);
	void DrawCarpet(int depth, int width, int height);
private:
	void drawTriangle(float x1, float y1, float x2, float y2, float x3, float y3);
	void subTriangle(int n, float x1, float y1, float x2, float y2, float x3, float y3);
	void drawCarpet(int n, int x, int y, int size);

};
