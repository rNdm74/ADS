#pragma once

ref class BinaryTreeNode
{
private:
	int nodeValue;
	BinaryTreeNode^ leftChild;
	BinaryTreeNode^ rightChild;

public:
	BinaryTreeNode(int startValue);

	//Gets and sets
	void setNodeValue(int v)						{ nodeValue = v; }
	void setLeftChild(BinaryTreeNode^ newLeft)		{ leftChild = newLeft; }
	void setRightChild(BinaryTreeNode^ newRight)	{ rightChild = newRight; }

	int getNodeValue()								{ return nodeValue; }
	BinaryTreeNode^ getLeftChild()					{ return leftChild; }
	BinaryTreeNode^ getRightChild()					{ return rightChild; }

};
