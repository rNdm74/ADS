#pragma once

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

#define MAXDISKS 8
#define DISKWIDTH 99

ref class TowerStack
{
private:
	PictureBox^ pole;
	int top;
	array<Point>^ locations;
	array<PictureBox^>^ disks;
public:
	TowerStack(PictureBox^ startPole);

	void Push(PictureBox^ pushImage);
	PictureBox^ Pop();
	bool isEmpty();
	void clear();
};

ref class HanoiDisplay
{
private:
	array<TowerStack^>^ poles;
	array<PictureBox^>^ disks;
public:
	HanoiDisplay(void);
	HanoiDisplay(array<PictureBox^>^ startDisks, PictureBox^ Pole1, PictureBox^ Pole2,
					PictureBox^ Pole3);
	void setUp(int nDisks);
	void moveTopDisk(int src, int dest);
};
