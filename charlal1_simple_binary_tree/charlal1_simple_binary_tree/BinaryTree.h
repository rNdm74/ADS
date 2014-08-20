#pragma once

#include "BinaryTreeNode.h"

ref class BinaryTree
{
protected:
	BinaryTreeNode^ rootNode;

public:
	BinaryTree();
	BinaryTree(int rootValue);
	BinaryTree(int rootValue, BinaryTree^ leftSubTree, BinaryTree^ rightSubTree);

	bool IsEmpty();

	void setRootNodeValue(int newRootNodeValue);
	int getRootNodeValue();
	BinaryTreeNode^ getRootNode();

	void addLeftSubTree(BinaryTree^ newLeftSubTree);
	void addRightSubTree(BinaryTree^ newRightSubTree);
	void makeLeftChildNode(int nodeValue);
	void makeRightChildNode(int nodeValue);

};
