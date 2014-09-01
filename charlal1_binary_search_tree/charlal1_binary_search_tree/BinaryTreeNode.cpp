#include "StdAfx.h"
#include "BinaryTreeNode.h"

BinaryTreeNode::BinaryTreeNode(String^ startValue)
{
	nodeValue = startValue;
	LeftChild = nullptr;
	RightChild = nullptr;
}
