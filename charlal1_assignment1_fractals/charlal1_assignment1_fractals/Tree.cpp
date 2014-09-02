#include "StdAfx.h"
#include "Tree.h"

/// <summary>
/// Summary for Constructor
///	
/// PRE-CONDITION:	Must provide graphics object for drawing
/// POST-CONDITION: Assign the graphics object and create the pen for drawing 
/// </summary>
Tree::Tree(Graphics^ graphics)
{
	this->graphics = graphics;

	pen = gcnew System::Drawing::Pen(Color::Red);

	rGen = gcnew Random();
}

/// <summary>
/// Summary for Constructor
///	
/// PRE-CONDITION:	Must provide graphics object for drawing
/// POST-CONDITION: Assign the graphics object and create the pen for drawing 
/// </summary>
void Tree::Draw(int depth, int width, int height)
{
	// Clear canvas
	graphics->Clear(Color::White);

	leftOffset = rGen->Next(30) + 5;
	rightOffset = rGen->Next(50) + 5;

	draw(depth, width / 2, height, height / 4, 90);
}

/// <summary>
/// Summary for Constructor
///	
/// PRE-CONDITION:	Must provide graphics object for drawing
/// POST-CONDITION: Assign the graphics object and create the pen for drawing 
/// </summary>
void Tree::draw(int depth, int x, int y, int length, int angle)
{		
	if(depth >= 0)
	{
		// Convert to radians;
		double radiansAngle = angle * 0.01745;

		// End points
		int x1 = (int) x + (length * Math::Cos(radiansAngle));
		int y1 = (int) y - (length * Math::Sin(radiansAngle));

		// Draw line
		graphics->DrawLine(pen, x, y, x1, y1);
		
		// Recursive call
		draw(depth - 1, x1, y1, length * 0.75, angle + leftOffset);
		draw(depth - 1, x1, y1, length * 0.66, angle - rightOffset);		
	}
}
