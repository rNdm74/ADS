#include "StdAfx.h"
#include "Koch.h"

Koch::Koch(Graphics^ graphics)
{
	this->graphics = graphics;

	redPen = gcnew System::Drawing::Pen(Color::Red);
	whitePen = gcnew System::Drawing::Pen(Color::White);
}

void Koch::Draw(int depth, int width, int height)
{
	this->width = width;
	this->height = height;
	this->depth = depth;

	int length = 400;

	// Clear canvas
	graphics->Clear(Color::White);

	int x1 = 100;
	int y1 = 150;
	int size = width - 200;

	int x2, y2, x3, y3;

	x2 = x1 + size;
	y2 = y1; 

	x3 = x1 + size / 2; 
	y3 = (y1 + size);
	
	// Top line
	draw(x1, y1, x3, y3, depth);
	// Right line
	draw(x3, y3, x2, y2, depth);
	// Left line
	draw(x2, y2, x1, y1, depth);
}

void Koch::draw(int x1, int y1, int x5, int y5, int n)
{
	int x2, y2, x3, y3, x4, y4;

	double d, a, h;

	graphics->DrawLine(redPen, x1, y1, x5, y5);

	if(n == 0)
		return;

	d = Math::Sqrt((x5-x1) * (x5-x1) + (y5-y1) * (y5-y1)) / 3;	// 1/3 of the length
	a = Math::Atan2((double) (y5-y1), (double) (x5-x1));		// angle of the line
	h = 2 * d * Math::Cos(30 * Math::PI / 180);					// distance to peak

	x2 = x1 + (int) (d * Math::Cos(a)); 
	y2 = y1 + (int) (d * Math::Sin(a));
	x3 = x1 + (int) (h * Math::Cos((a + 30 * Math::PI / 180)));	// coordinates of peak
	y3 = y1 + (int) (h * Math::Sin((a + 30 * Math::PI / 180)));
	x4 = x1 + (int) (2 * d * Math::Cos(a));
	y4 = y1 + (int) (2 * d * Math::Sin(a));
	
	// Erase the middle
	graphics->DrawLine(whitePen, x1, y1, x5, y5);

	// Recursive calls to replace line with new pattern
	draw(x1, y1, x2, y2, n - 1);	 
	draw(x2, y2, x3, y3, n - 1);
	draw(x3, y3, x4, y4, n - 1);
	draw(x4, y4, x5, y5, n - 1);

}