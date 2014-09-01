#pragma once

#include "BinaryTreeNode.h"

using namespace System::Windows::Forms;
using namespace System::Drawing;

ref class BinaryTree
{
private:
	int leftAngle;
	int rightAngle;

protected:
	BinaryTreeNode^ rootNode;

public:
	BinaryTree();
	BinaryTree(String^ rootValue);
	BinaryTree(String^ rootValue, BinaryTree^ leftSubTree, BinaryTree^ rightSubTree);

	bool IsEmpty();

	void setRootNodeValue(String^ newRootNodeValue);
	String^ getRootNodeValue();
	BinaryTreeNode^ getRootNode();

	void addLeftSubTree(BinaryTree^ newLeftSubTree);
	void addRightSubTree(BinaryTree^ newRightSubTree);
	void makeLeftChildNode(String^ nodeValue);
	void makeRightChildNode(String^ nodeValue);

	void PreOrder(BinaryTreeNode^ inputRootNode, ListBox^ targetListBox);
	void InOrder(BinaryTreeNode^ inputRootNode, ListBox^ targetListBox);
	void PostOrder(BinaryTreeNode^ inputRootNode, ListBox^ targetListBox);

	virtual void Parse(BinaryTreeNode^ inputRootNode, ListBox^ targetListBox);
	virtual void PostFix(BinaryTreeNode^ inputRootNode, ListBox^ targetListBox);

	void Draw(BinaryTreeNode^ inputRootNode, int startX, int startY, int currOffsetX, Graphics^ treeCanvas);
};
