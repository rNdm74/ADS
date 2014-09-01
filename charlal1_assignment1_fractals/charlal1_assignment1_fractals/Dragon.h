#pragma once

using namespace System;
using namespace System::Drawing;

ref class Dragon
{
private:
	Pen^ pen;
	Graphics^ graphics;
	int depth;
	double angle;

	int x1, y1;

	void draw(double length, int split, double d);
	void turn(double degrees);
	void forward(double length);
	
public:
	Dragon(Graphics^ graphics);
	void Draw(int depth, int width, int height);

};
