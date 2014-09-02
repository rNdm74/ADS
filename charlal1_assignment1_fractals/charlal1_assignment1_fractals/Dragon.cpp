#include "StdAfx.h"
#include "Dragon.h"

/// <summary>
/// Summary for Constructor
///	
/// PRE-CONDITION:	Must provide graphics object for drawing
/// POST-CONDITION: Assign the graphics object and create the pen for drawing 
/// </summary>
Dragon::Dragon(Graphics^ graphics)
{
	// 
	this->graphics = graphics;

	// Create pen
	pen = gcnew System::Drawing::Pen( Color::Red );
}

/// <summary>
/// Summary for Draw
///	
/// PRE-CONDITION:	Must provide the wanted running depth, 
///					Width and height of the canvas
///
/// POST-CONDITION: Graphics canvas is cleared for drawing
///					the start points are initialized, x1 & y1
///					The radian angle is initialized to 0
///					The recursive draw is called
/// </summary>
void Dragon::Draw(int depth, int width, int height)
{
	// Clear canvas
	graphics->Clear( Color::White );

	// Set starting points
	x1 = start;
	y1 = height / 2;

	// Init starting radian angle
	radian = 0;

	// Start the draw
	draw( width / 2, depth, 1 ); 
}

/// <summary>
/// Summary for draw recursive call
///	
/// PRE-CONDITION:	Must provide the length of line to draw, depth of iterations and the angle for drawing
/// POST-CONDITION: On each recursion when depth is greater than 0 call the turn function
///					
///					turn: change angle to 45 degrees
///					draw: length of line devide by scale, depth is reduced by 1 and angle is positive
///					turn: change angle to negative 90 degrees
///					draw: length of line devided by scale, depth is reduced by 1 and angle is negative
///					turn: change angle to 45 degrees
///
/// </summary>
void Dragon::draw(double length, int depth, double angle)
{
	// When depth is 0 draw line
	if(depth <= 0)
	{
		// Draw the line
		forward( length );
	}
	else
	{
		// Recurse call turn 45 degrees, draw, turn -90 degrees, draw, turn 45 degrees
		turn( angle * 45 );
		draw( length / scale, depth - 1, 1 );
		turn( -angle * 90 );
		draw( length /  scale, depth - 1, -1 );
		turn( angle * 45 );
	}
}

/// <summary>
/// Summary for turn
///	
/// PRE-CONDITION:	Must provide angle to be converted into radians
/// POST-CONDITION: Angle is converted to radian 
/// </summary>
void Dragon::turn(double angle)
{
	radian = radian + angle * Math::PI / 180;
}

/// <summary>
/// Summary for forward
///	
/// PRE-CONDITION:	Must provide length of line to draw
/// POST-CONDITION: A line is drawn on the graphics canvas 
/// </summary>
void Dragon::forward(double length)
{
	// Find the destination point
	int x2 = x1 + (int) ( Math::Cos( radian ) * length );
    int y2 = y1 + (int) ( Math::Sin( radian ) * length );

	// Draw the line
	graphics->DrawLine( pen, x1, y1, x2, y2 );

	// Change start location to x1, y1
	x1 = x2;
	y1 = y2;
}