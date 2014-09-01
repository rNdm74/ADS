#include "StdAfx.h"
#include "Dragon.h"

Dragon::Dragon(Graphics^ graphics)
{
	this->graphics = graphics;

	pen = gcnew System::Drawing::Pen(Color::Red);
}

void Dragon::Draw(int depth, int width, int height)
{
	this->depth = depth;

	// Clear canvas
	graphics->Clear(Color::White);

	x1 = 125;
	y1 = height / 2;

	angle = 0;

	draw(width - 175, depth, 1); 
}

void Dragon::draw(double length, int split, double degrees)
{
	if(split == 0)
	{
		forward(length);
	}
	else
	{
		turn(degrees * 45);
		draw(length / 1.4142136, split - 1, 1);
		turn(-degrees * 90);
		draw(length / 1.4142136, split - 1, -1);
		turn(degrees * 45);
	}
}

void Dragon::turn(double degrees)
{
	angle = angle + degrees * Math::PI / 180;
}

void Dragon::forward(double length)
{
	int x2 = x1 + (int) (Math::Cos(angle) * length);
    int y2 = y1 + (int) (Math::Sin(angle) * length);

	graphics->DrawLine(pen, x1, y1, x2, y2);

	x1 = x2;
	y1 = y2;
}