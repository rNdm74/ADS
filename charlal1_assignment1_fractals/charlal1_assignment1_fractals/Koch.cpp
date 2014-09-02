#include "StdAfx.h"
#include "Koch.h"

/// <summary>
/// Summary for Constructor
///	
/// PRE-CONDITION:	Must provide graphics object for drawing
/// POST-CONDITION: Assign the graphics object and create the pen for drawing 
/// </summary>
Koch::Koch(Graphics^ graphics)
{
	this->graphics = graphics;

	redPen = gcnew System::Drawing::Pen(Color::Red);
}

/// <summary>
/// Summary for Draw
///	
/// PRE-CONDITION:	Must provide the wanted running depth, 
///					Width and height of the canvas
///
/// POST-CONDITION: Graphics canvas is cleared for drawing
///					The three sides of the triangle are drawn
///
/// </summary>
void Koch::Draw(int depth, int width, int height)
{
	// Clear canvas
	graphics->Clear(Color::White);
	
	// Bottom
	draw(depth, 20, height - 150, width - 20,height - 150);
	// Right
	draw(depth, width - 20, height - 150, width / 2, 20);
	// Left
    draw(depth, width / 2, 20, 20, height - 150);
}

/// <summary>
/// Summary for draw
///	
/// PRE-CONDITION:	Must provide depth, the start point and end point of line
/// POST-CONDITION: When depth is 0, a line is drawn to the screen
///
/// </summary>
void Koch::draw(int depth, int x1, int y1, int x5, int y5)
{
	// Points
	int deltaX, deltaY, x2, y2, x3, y3, x4, y4;
 
	// Draw when depth is 0
	if (depth <= 0)
	{
		graphics->DrawLine(redPen, x1, y1, x5, y5);
	}
	else
	{
		// Length of line
		deltaX = x5 - x1;
		deltaY = y5 - y1;

		// Peak left base 
		x2 = x1 + deltaX / 3;
		y2 = y1 + deltaY / 3;

		// Peak
		x3 = (int) ( 0.5 * ( x1 + x5 ) + Math::Sqrt(3) * ( y1 - y5 ) / 6 );
		y3 = (int) ( 0.5 * ( y1 + y5 ) + Math::Sqrt(3) * ( x5 - x1 ) / 6 );

		// Peak right base
		x4 = x1 + 2 * deltaX / 3;
		y4 = y1 + 2 * deltaY / 3;

		// Recurse draw the four lines
		draw (depth - 1, x1, y1, x2, y2);
		draw (depth - 1, x2, y2, x3, y3);
		draw (depth - 1, x3, y3, x4, y4);
		draw (depth - 1, x4, y4, x5, y5);
	}
}