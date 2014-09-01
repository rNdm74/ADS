#pragma once

using namespace System;

ref class BinaryTreeNode
{
private:
	String^ nodeValue;	

public:
	BinaryTreeNode^ LeftChild;
	BinaryTreeNode^ RightChild;

	BinaryTreeNode(String^ startValue);

	//Gets and sets
	void setNodeValue(String^ v)					{ nodeValue = v; }
	void setLeftChild(BinaryTreeNode^ newLeft)		{ LeftChild = newLeft; }
	void setRightChild(BinaryTreeNode^ newRight)	{ RightChild = newRight; }

	String^ getNodeValue()							{ return nodeValue; }
	BinaryTreeNode^ getLeftChild()					{ return LeftChild; }
	BinaryTreeNode^ getRightChild()					{ return RightChild; }
	
};
