#include "StdAfx.h"
#include "HanoiDisplay.h"



TowerStack::TowerStack(PictureBox^ startPole)
{
	pole = startPole;
	top = 0;

	disks = gcnew array<PictureBox^>(MAXDISKS);
	for (int i=0; i<MAXDISKS; i++)
		disks[i] = nullptr;

	locations = gcnew array<Point>(MAXDISKS);

	int poleWidth = pole->Width;
	int poleHeight = pole->Height;
	int heightInc = poleHeight/MAXDISKS;
	int poleBase = pole->Top + poleHeight;

	for (int i=0; i<MAXDISKS; i++)
	{
		locations[i].X = pole->Left + (poleWidth/2);
		locations[i].Y = poleBase - (heightInc * (i+1));
	}

}

void TowerStack::Push(PictureBox^ pushImage)
{
	Point newPos = locations[top];

	int imageWidth = pushImage->Width;
	int adjustment = imageWidth/2;

	pushImage->Left = newPos.X - adjustment;
	pushImage->Top = newPos.Y;

	disks[top] = pushImage;
	top++;
}

PictureBox^ TowerStack::Pop()
{
	top--;
	return disks[top];
}

bool TowerStack::isEmpty()
{
	if (top == 0)
		return true;
	else
		return false;
}

void TowerStack::clear()
{
	top = 0;
}

//----------------------------------------------------------------------------


HanoiDisplay::HanoiDisplay(void)
{
}

HanoiDisplay::HanoiDisplay(array<PictureBox^>^ startDisks, PictureBox^ Pole1, PictureBox^ Pole2,
					PictureBox^ Pole3)
{
	disks = gcnew array<PictureBox^>(MAXDISKS);
	poles = gcnew array<TowerStack^>(3);			// Tower of Hanoi has three poles

	for (int i=0; i<MAXDISKS; i++)
		disks[i] = startDisks[i];

	poles[0] = gcnew TowerStack(Pole1);
	poles[1] = gcnew TowerStack(Pole2);
	poles[2] = gcnew TowerStack(Pole3);

}

void HanoiDisplay::setUp(int nDisks)
{
		for (int i=0; i<3; i++)
			poles[i]->clear();

		for (int i=nDisks-1; i>=0; i--)
		{
			poles[0]->Push(disks[i]);
			disks[i]->Visible = true;
			disks[i]->Refresh();
		}
}

void HanoiDisplay::moveTopDisk(int src, int dest)
{
	PictureBox^ tempDisk;

	if ((src>=0) && (dest>=0) && (src<=3) && (dest<=3))
	{
		tempDisk = poles[src-1]->Pop();
		poles[dest-1]->Push(tempDisk);
	}
}
