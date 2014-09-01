#include "StdAfx.h"
#include "BinaryTree.h"

BinaryTree::BinaryTree()
{
	leftAngle = 340;
	rightAngle = 200;
	angleOffset = 0;
	rootNode = gcnew BinaryTreeNode("0");
}

BinaryTree::BinaryTree(String^ rootValue)
{
	leftAngle = 340;
	rightAngle = 200;
	angleOffset = 0;
	rootNode = gcnew BinaryTreeNode(rootValue);
}

BinaryTree::BinaryTree(String^ rootValue, BinaryTree^ leftSubTree, BinaryTree^ rightSubTree)
{
	leftAngle = 340;
	rightAngle = 200;
	angleOffset = 0;
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
	// If leaf node
	if( inputRootNode != nullptr )
	{
		

		Pen^ p = gcnew Pen(Color::Black);

		int newOffsetX = currOffsetX * 0.75;
		angleOffset += 3;

		if(angleOffset > 5)
			angleOffset = 5;
		
		

		if(inputRootNode->getLeftChild() != nullptr)
		{
			leftAngle -= angleOffset;

			if(leftAngle >= 330)
				leftAngle = 330;

			// Convert to radians;
			double radiansAngle = leftAngle * 0.01745;

			int dstX = startX - (75 * Math::Cos(radiansAngle));
			int dstY = startY - (75 * Math::Sin(radiansAngle));
			
			// Draw edge to next node
			treeCanvas->DrawLine(p, startX, startY, dstX, dstY);

			// Recurse draw left child
			Draw(inputRootNode->getLeftChild(), dstX, dstY, newOffsetX, treeCanvas);			
		}

		//
		if(inputRootNode->getRightChild() != nullptr)
		{
			rightAngle += angleOffset;

			if(rightAngle >= 210)
				rightAngle = 210;

			double radiansAngle = rightAngle * 0.01745;

			int dstX = startX - (75 * Math::Cos(radiansAngle));
			int dstY = startY - (75 * Math::Sin(radiansAngle));

			// Draw edge to next node
			treeCanvas->DrawLine(p, startX, startY, dstX, dstY);

			// Recurse draw left child
			Draw(inputRootNode->getRightChild(), dstX, dstY, newOffsetX, treeCanvas);
		}

		// Return node value
		treeCanvas->FillEllipse(Brushes::White, startX - 25, startY - 25, 50, 50);
		treeCanvas->DrawString(inputRootNode->getNodeValue(), gcnew Font("Arial", 16),Brushes::Red, startX-10, startY-10);
		treeCanvas->DrawEllipse(p, startX - 25, startY - 25, 50, 50);
		
		//System::Threading::Thread::Sleep(1000);
	}
}