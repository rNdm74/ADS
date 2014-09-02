#pragma once

using namespace System;
using namespace System::Drawing;

static const double scale = 1.4142136;
static const int	start = 125;

ref class Dragon
{
private:
	Pen^ pen;
	Graphics^ graphics;

	double radian;

	int x1, y1;

	void draw(double length, int depth, double angle);
	void turn(double angle);
	void forward(double length);
	
public:
	Dragon(Graphics^ graphics);
	void Draw(int depth, int width, int height);

};
