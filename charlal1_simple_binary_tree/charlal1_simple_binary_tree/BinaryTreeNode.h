#pragma once

using namespace System;

ref class BinaryTreeNode
{
private:
	String^ nodeValue;
	BinaryTreeNode^ leftChild;
	BinaryTreeNode^ rightChild;

public:
	BinaryTreeNode(String^ startValue);

	//Gets and sets
	void setNodeValue(String^ v)					{ nodeValue = v; }
	void setLeftChild(BinaryTreeNode^ newLeft)		{ leftChild = newLeft; }
	void setRightChild(BinaryTreeNode^ newRight)	{ rightChild = newRight; }

	String^ getNodeValue()							{ return nodeValue; }
	BinaryTreeNode^ getLeftChild()					{ return leftChild; }
	BinaryTreeNode^ getRightChild()					{ return rightChild; }
	
};
