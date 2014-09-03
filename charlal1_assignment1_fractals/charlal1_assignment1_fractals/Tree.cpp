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
}

/// <summary>
/// Summary for Draw
///	
/// PRE-CONDITION:	Must provide depth canvas width and height
/// POST-CONDITION: The canvas is cleared for drawing
///					The recursive draw call is made
/// </summary>
void Tree::Draw(int depth, int width, int height)
{
	// Clear canvas
	graphics->Clear(Color::White);

	// Recursive call, starting with line in center of screen
	draw(depth, width / 2, height, height / 4, 90);
}

/// <summary>
/// Summary for draw
///	
/// PRE-CONDITION:	Must provide depth, x,y start points line length and angle
/// POST-CONDITION: Draws line on canvas at specified angle
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
		draw(depth - 1, x1, y1, length * lScale, angle + lOffset);
		draw(depth - 1, x1, y1, length * rScale, angle - rOffset);		
	}
}
