#include "StdAfx.h"
#include "Tree.h"

Tree::Tree(Graphics^ graphics)
{
	this->graphics = graphics;

	pen = gcnew System::Drawing::Pen(Color::Red);	
}

void Tree::Draw(int depth, int width, int height)
{
	//
	this->depth = 100 - (depth * 10);

	// 
	if(this->depth < 1)
		this->depth = 1;

	// Clear canvas
	graphics->Clear(Color::White);

	draw(width / 2, height, height / 4, 90);
}

void Tree::draw(double x, double y, double length, double angle)
{	
	// Convert to radians;
	double radiansAngle = angle * 0.01745;

	if(length > depth)
	{
		double x1 = x + (length * Math::Cos(radiansAngle));
		double y1 = y - (length * Math::Sin(radiansAngle));

		graphics->DrawLine(pen, (float)x, (float)y, (float)x1, (float)y1);

		draw(x1, y1,length * 0.75, angle + 30);
		draw(x1, y1,length * 0.66, angle - 50);		
	}
}
