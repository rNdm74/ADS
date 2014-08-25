#include "StdAfx.h"
#include "BinaryTreeNode.h"

BinaryTreeNode::BinaryTreeNode(String^ startValue)
{
	nodeValue = startValue;
	leftChild = nullptr;
	rightChild = nullptr;
}
