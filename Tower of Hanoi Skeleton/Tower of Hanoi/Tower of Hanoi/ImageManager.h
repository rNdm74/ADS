#pragma once

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;



ref class ImageManager
{
private:
	PictureBox^ myImage;
public:
	ImageManager(PictureBox^ startImage);
	void MoveLeft(int moveDistance);
};
