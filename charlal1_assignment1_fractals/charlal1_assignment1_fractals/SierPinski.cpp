#include "StdAfx.h"
#include "SierPinski.h"

/// <summary>
/// Summary for Constructor
///	
/// PRE-CONDITION:	Must provide graphics object for drawing
/// POST-CONDITION: Assign the graphics object and create the pen for drawing 
/// </summary>
SierPinski::SierPinski(Graphics^ graphics)
{
	this->graphics = graphics;

	pen = gcnew System::Drawing::Pen(Color::Red);
}

/// <summary>
/// Summary for DrawTriangle
///	
/// PRE-CONDITION:	Must provide depth, the start point and end point of line
/// POST-CONDITION: When depth is 0, a line is drawn to the screen
///
/// </summary>
void SierPinski::DrawTriangle(int depth, int width, int height)
{
	// Clear canvas
	graphics->Clear(Color::White);

	// Triangle endpoints
	int triangleHeight = (int) Math::Round(512 * Math::Sqrt(3.0) / 2.0);

    Point p1 = Point(0, triangleHeight);
    Point p2 = Point(512 / 2, 0);
    Point p3 = Point(512, triangleHeight);

    drawTriangle(depth, p1, p2, p3);
}

/// <summary>
/// Summary for drawTriangle
///	
/// PRE-CONDITION:	Must provide depth, the start point and end point of line
/// POST-CONDITION: When depth is 0, a line is drawn to the screen
///
/// </summary>
void SierPinski::drawTriangle(int depth, Point p1, Point p2, Point p3)
{
	if (depth <= 0) 
	{		
		graphics->DrawPolygon(pen, gcnew array<Point>{ p1, p2, p3} );
    }
	else
	{
        // recursive case, split into 3 triangles
        Point p4 = midPoint(p1, p2);
        Point p5 = midPoint(p2, p3);
        Point p6 = midPoint(p1, p3);

        // recurse on 3 triangular areas
        drawTriangle(depth - 1, p1, p4, p6);
        drawTriangle(depth - 1, p4, p2, p5);
        drawTriangle(depth - 1, p6, p5, p3);
    }
}

/// <summary>
/// Summary for midPoint
///	
/// PRE-CONDITION:	Must provide two points
/// POST-CONDITION: returns the midpoint of p1 and p2
///
/// </summary>
Point SierPinski::midPoint(Point p1, Point p2) 
{
	return Point((p1.X + p2.X) / 2, (p1.Y + p2.Y) / 2);
}

/// <summary>
/// Summary for DrawCarpet
///	
/// PRE-CONDITION:	Must provide depth, the start point and end point of line
/// POST-CONDITION: When depth is 0, a line is drawn to the screen
///
/// </summary>
void SierPinski::DrawCarpet(int depth, int width, int height)
{
	// Clear canvas
	graphics->Clear(Color::White);

	// Recursive call
	drawCarpet(depth, 0, 0, width);
}

/// <summary>
/// Summary for draw
///	
/// PRE-CONDITION:	Must provide depth, the start point and end point of line
/// POST-CONDITION: When depth is 0, a line is drawn to the screen
///
/// </summary>
void SierPinski::drawCarpet(int depth, int x, int y, int size)
{
	// Draw when depth is 0
	if (depth >= 0)
	{		
		// Calc size of squares
		int subSize = size / 3;

		// Draw the square
		Rectangle rect = Rectangle(x + subSize, y + subSize, subSize, subSize);
		graphics->FillRectangle(Brushes::Red, rect);

		// Draw the top row
		drawCarpet(depth - 1, x, y, subSize);
		drawCarpet(depth - 1, x + subSize, y, subSize);
		drawCarpet(depth - 1, x + 2 * subSize, y, subSize);

		// Draw the middle row 
		drawCarpet(depth - 1, x, ( y + subSize ), subSize ); 
		drawCarpet(depth - 1, ( x + 2 * subSize ), ( y + subSize ), subSize );

		// Draw the bottom row 
		drawCarpet(depth - 1, x, ( y + 2 * subSize ), subSize); 
		drawCarpet(depth - 1, ( x + subSize ), ( y + 2 * subSize ), subSize ); 
		drawCarpet(depth - 1, ( x + 2 * subSize ), ( y + 2 * subSize ), subSize );
	}
}