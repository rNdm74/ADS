#include "StdAfx.h"
#include "BinaryTree.h"

BinaryTree::BinaryTree()
{
	rootNode = gcnew BinaryTreeNode("0");
}

BinaryTree::BinaryTree(String^ rootValue)
{
	rootNode = gcnew BinaryTreeNode(rootValue);
}

BinaryTree::BinaryTree(String^ rootValue, BinaryTree^ leftSubTree, BinaryTree^ rightSubTree)
{
	rootNode = gcnew BinaryTreeNode(rootValue);

	addLeftSubTree(leftSubTree);
	addRightSubTree(rightSubTree);
}

bool BinaryTree::IsEmpty()
{
	return (rootNode == nullptr);
}

void BinaryTree::setRootNodeValue(String^ newRootNodeValue)
{
	rootNode->setNodeValue(newRootNodeValue);
}

String^ BinaryTree::getRootNodeValue()
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

void BinaryTree::makeLeftChildNode(String^ nodeValue)
{
	//
	BinaryTreeNode^ newLeftNode = gcnew BinaryTreeNode(nodeValue);
	rootNode->setLeftChild(newLeftNode);
}

void BinaryTree::makeRightChildNode(String^ nodeValue)
{
	//
	BinaryTreeNode^ newRightNode = gcnew BinaryTreeNode(nodeValue);
	rootNode->setRightChild(newRightNode);
}

void BinaryTree::PreOrder(BinaryTreeNode^ inputRootNode, ListBox^ targetListBox)
{
	// Base case
	if(inputRootNode != nullptr)
	{		
		// Process the current root
		String^ currValue = inputRootNode->getNodeValue();
		targetListBox->Items->Add(currValue + " ");

		// Recurse down the left sub tree
		BinaryTreeNode^ leftRoot = inputRootNode->getLeftChild();
		PreOrder(leftRoot, targetListBox);

		// Recurse down the right sub tree
		BinaryTreeNode^ rightRoot = inputRootNode->getRightChild();
		PreOrder(rightRoot, targetListBox);
	}
}

void BinaryTree::InOrder(BinaryTreeNode^ inputRootNode, ListBox^ targetListBox)
{
	// Base case
	if(inputRootNode != nullptr)
	{
		// Recurse down the left sub tree
		BinaryTreeNode^ leftRoot = inputRootNode->getLeftChild();
		InOrder(leftRoot, targetListBox);

		// Process the current root
		String^ currValue = inputRootNode->getNodeValue();
		targetListBox->Items->Add(currValue + " ");

		// Recurse down the right sub tree
		BinaryTreeNode^ rightRoot = inputRootNode->getRightChild();
		InOrder(rightRoot, targetListBox);		
	}
}

void BinaryTree::PostOrder(BinaryTreeNode^ inputRootNode, ListBox^ targetListBox)
{
	// Base case
	if(inputRootNode != nullptr)
	{
		// Recurse down the left sub tree
		BinaryTreeNode^ leftRoot = inputRootNode->getLeftChild();
		PostOrder(leftRoot, targetListBox);

		// Recurse down the right sub tree
		BinaryTreeNode^ rightRoot = inputRootNode->getRightChild();
		PostOrder(rightRoot, targetListBox);

		// Process the current root
		String^ currValue = inputRootNode->getNodeValue();
		targetListBox->Items->Add(currValue + " ");
	}
}

void BinaryTree::Parse(BinaryTreeNode^ inputRootNode, ListBox^ targetListBox)
{
}

void BinaryTree::PostFix(BinaryTreeNode^ inputRootNode, ListBox^ targetListBox)
{
}

void BinaryTree::Draw(BinaryTreeNode^ inputRootNode, int startX, int startY, int currOffsetX, Graphics^ treeCanvas)
{
	// Get nodes
	BinaryTreeNode^ left = inputRootNode->getLeftChild();
	BinaryTreeNode^ right = inputRootNode->getRightChild();

	Pen^ p = gcnew Pen(Color::Black);

	// If leaf node
	if( left == nullptr && right == nullptr )
	{
		// Return node value
		treeCanvas->DrawEllipse(p, startX - 25, startY - 25, 50, 50);
	}
	else
	{		
		// Draw node
		treeCanvas->DrawEllipse(p, startX - 25, startY - 25, 50, 50);
		System::Threading::Thread::Sleep(1000);
		

		//
		if(left != nullptr)
		{
			int x1 = startX - 25;
			int y1 = startY + 25;

			y1 += 25;

			x1 -= currOffsetX;
			x1 += 15;
			
			// Draw edge to next node
			treeCanvas->DrawLine(p, x1, y1, startX, startY);

			// Recurse draw left child
			Draw(left, x1, y1, currOffsetX - 10, treeCanvas);			
		}

		//
		if(right != nullptr)
		{
			int x1 = startX - 25;
			int y1 = startY + 25;

			y1 += 25;

			x1 += currOffsetX;
			x1 -= 15;

			// Draw edge to next node
			treeCanvas->DrawLine(p, x1, y1, startX, startY);

			// Recurse draw left child
			Draw(right, x1, y1, currOffsetX-10, treeCanvas);
		}

		
	}

	
}