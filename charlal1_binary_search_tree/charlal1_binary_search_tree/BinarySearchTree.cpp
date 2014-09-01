#include "StdAfx.h"
#include "BinarySearchTree.h"

BinarySearchTree::BinarySearchTree()
{
	rootNode = gcnew BinaryTreeNode("0");
}

BinarySearchTree::BinarySearchTree(String^ rootValue)
{
	rootNode = gcnew BinaryTreeNode(rootValue);
}

BinarySearchTree::BinarySearchTree(String^ rootValue, BinaryTree^ leftSubTree, BinaryTree^ rightSubTree)
{
	rootNode = gcnew BinaryTreeNode(rootValue);

	addLeftSubTree(leftSubTree);
	addRightSubTree(rightSubTree);
}

void BinarySearchTree::insertItem(BinaryTreeNode^ %treeRootPtr, String^ insertValue)
{	
	// If leaf node
	if( treeRootPtr == nullptr )
	{
		// Create new node with value and attach to node pointer
		treeRootPtr = gcnew BinaryTreeNode(insertValue);
	}
	else
	{
		int v1 = Convert::ToInt16(insertValue);
		int v2 = Convert::ToInt16(treeRootPtr->getNodeValue());

		if(v1 < v2)
			insertItem(treeRootPtr->LeftChild, insertValue);
		else
			insertItem(treeRootPtr->RightChild, insertValue);		
	}
}

bool BinarySearchTree::findItem(BinaryTreeNode^ inputRootNode, String^ targetValue)
{
	// If leaf node
	if( inputRootNode == nullptr )
	{
		return false;
	}
	else if(inputRootNode->getNodeValue() == targetValue)
	{
		return true;
	}
	else
	{
		int v1 = Convert::ToInt16(targetValue);
		int v2 = Convert::ToInt16(inputRootNode->getNodeValue());

		if(v1 < v2)
			return findItem(inputRootNode->LeftChild, targetValue);
		else
			return findItem(inputRootNode->RightChild, targetValue);		
	}
}

void BinarySearchTree::addNode(String^ nodeValue)
{
	insertItem(rootNode, nodeValue);
}

bool BinarySearchTree::search(String^ targetValue)
{
	return findItem(rootNode, targetValue);
}