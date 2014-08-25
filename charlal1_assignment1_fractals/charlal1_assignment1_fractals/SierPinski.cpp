#include "StdAfx.h"
#include "SierPinski.h"

SierPinski::SierPinski(Graphics^ graphics)
{
	this->graphics = graphics;

	pen = gcnew System::Drawing::Pen(Color::Red);
}

void SierPinski::Draw(int depth, int width, int height)
{		
	this->depth = depth;
	Draw((float)10, (float)height - 10, (float)width - 10, (float)height - 10, (float)width / 2, (float)10);
}

void SierPinski::Draw(float x1, float y1, float x2, float y2, float x3, float y3)
{	
	// Clear canvas
	graphics->Clear(Color::White);

	//Draw the 3 sides of the triangle as black lines
	graphics->DrawLine(pen, x1, y1, x2, y2);
	graphics->DrawLine(pen, x1, y1, x3, y3);
	graphics->DrawLine(pen, x2, y2, x3, y3);
	
	//Call the recursive function that'll draw all the rest. The 3 corners of it are always the centers of sides, so they're averages
    SubTriangle
    (
        1, //This represents the first recursion
        (x1 + x2) / 2, //x coordinate of first corner
        (y1 + y2) / 2, //y coordinate of first corner
        (x1 + x3) / 2, //x coordinate of second corner
        (y1 + y3) / 2, //y coordinate of second corner
        (x2 + x3) / 2, //x coordinate of third corner
        (y2 + y3) / 2  //y coordinate of third corner
    );
}

//The recursive function that'll draw all the upside down triangles
void SierPinski::SubTriangle(int n, float x1, float y1, float x2, float y2, float x3, float y3)
{
    //Draw the 3 sides as black lines
	graphics->DrawLine(pen, x1, y1, x2, y2);
	graphics->DrawLine(pen, x1, y1, x3, y3);
	graphics->DrawLine(pen, x2, y2, x3, y3);        
    //
    //Calls itself 3 times with new corners, but only if the current number of recursions is smaller than the maximum depth
    if(n < depth)
    {
        //Smaller triangle 1
        SubTriangle
        (
            n+1, //Number of recursions for the next call increased with 1
            (x1 + x2) / 2 + (x2 - x3) / 2, //x coordinate of first corner
            (y1 + y2) / 2 + (y2 - y3) / 2, //y coordinate of first corner
            (x1 + x2) / 2 + (x1 - x3) / 2, //x coordinate of second corner
            (y1 + y2) / 2 + (y1 - y3) / 2, //y coordinate of second corner
            (x1 + x2) / 2, //x coordinate of third corner
            (y1 + y2) / 2  //y coordinate of third corner
        );
        //Smaller triangle 2
        SubTriangle
        (
            n+1, //Number of recursions for the next call increased with 1
            (x3 + x2) / 2 + (x2 - x1) / 2, //x coordinate of first corner
            (y3 + y2) / 2 + (y2 - y1) / 2, //y coordinate of first corner
            (x3 + x2) / 2 + (x3 - x1) / 2, //x coordinate of second corner
            (y3 + y2) / 2 + (y3 - y1) / 2, //y coordinate of second corner
            (x3 + x2) / 2, //x coordinate of third corner
            (y3 + y2) / 2  //y coordinate of third corner
        );
        //Smaller triangle 3
        SubTriangle
        (
            n+1, //Number of recursions for the next call increased with 1
            (x1 + x3) / 2 + (x3 - x2) / 2, //x coordinate of first corner
            (y1 + y3) / 2 + (y3 - y2) / 2, //y coordinate of first corner
            (x1 + x3) / 2 + (x1 - x2) / 2, //x coordinate of second corner
            (y1 + y3) / 2 + (y1 - y2) / 2, //y coordinate of second corner
            (x1 + x3) / 2, //x coordinate of third corner
            (y1 + y3) / 2  //y coordinate of third corner        
        );                
    }             
}
