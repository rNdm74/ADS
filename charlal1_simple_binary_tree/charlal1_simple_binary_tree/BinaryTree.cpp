#include "StdAfx.h"
#include "BinaryTree.h"

BinaryTree::BinaryTree()
{
}

BinaryTree::BinaryTree(int rootValue)
{
}

BinaryTree::BinaryTree(int rootValue, BinaryTree^ leftSubTree, BinaryTree^ rightSubTree)
{
}

bool BinaryTree::IsEmpty()
{
	return (rootNode == nullptr);
}

void BinaryTree::setRootNodeValue(int newRootNodeValue)
{
	rootNode->setNodeValue(newRootNodeValue);
}

int BinaryTree::getRootNodeValue()
{
	return rootNode->getNodeValue();
}

BinaryTreeNode^ BinaryTree::getRootNode()
{
	return rootNode;
}

void BinaryTree::addLeftSubTree(BinaryTree^ newLeftSubTree)
{
	BinaryTreeNode^ newSubRoot = newLeftSubTree->getRootNode();
	rootNode->setLeftChild(newSubRoot);
}

void BinaryTree::addRightSubTree(BinaryTree^ newRightSubTree)
{
	BinaryTreeNode^ newSubRoot = newRightSubTree->getRootNode();
	rootNode->setRightChild(newSubRoot);
}

void BinaryTree::makeLeftChildNode(int nodeValue)
{
}

void BinaryTree::makeRightChildNode(int nodeValue)
{
}