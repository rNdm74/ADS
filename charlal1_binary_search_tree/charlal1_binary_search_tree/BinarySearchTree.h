#pragma once
#include "binarytree.h"

ref class BinarySearchTree :
public BinaryTree
{
public:
	BinarySearchTree();
	BinarySearchTree(String^ rootValue);
	BinarySearchTree(String^ rootValue, BinaryTree^ leftSubTree, BinaryTree^ rightSubTree);
	void addNode(String^ nodeValue);
	bool search(String^ targetValue);
private:
	void insertItem(BinaryTreeNode^ %treeRootPtr, String^ insertValue);
	bool findItem(BinaryTreeNode^ inputRootNode, String^ targetValue);
};
