#pragma once

using namespace System;
using namespace System::Drawing;

ref class SierPinski
{
private:
	Pen^ pen;
	Graphics^ graphics;

	void drawTriangle(int depth, Point p1, Point p2, Point p3);
	Point midPoint(Point p1, Point p2);

	void drawCarpet(int depth, int x, int y, int size);

public:
	SierPinski(Graphics^ graphics);

	void DrawTriangle(int depth, int width, int height);
	void DrawCarpet(int depth, int width, int height);
};
