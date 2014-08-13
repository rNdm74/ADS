#include "StdAfx.h"
#include "ImageManager.h"

//ref class ImageManager

//private:
//PictureBox^ myImage;

ImageManager::ImageManager(PictureBox^ startImage)
{
	myImage = startImage;
}

void ImageManager::MoveLeft(int moveDistance)
{
	myImage->Left += moveDistance;
}