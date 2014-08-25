#pragma once
#include "binarytree.h"
#include "LinkedListStack.h"

ref class ExpressionTree :
public BinaryTree
{
public:
	ExpressionTree();
	ExpressionTree(String^ rootValue);
	ExpressionTree(String^ rootValue, BinaryTree^ leftSubTree, BinaryTree^ rightSubTree);

	int ParseExpressionTree(BinaryTreeNode^ inputRootNode);
	virtual void Parse(BinaryTreeNode^ inputRootNode, ListBox^ targetListBox) override;
	virtual void PostFix(BinaryTreeNode^ inputRootNode, ListBox^ targetListBox) override;
};
