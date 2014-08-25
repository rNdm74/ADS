#include "StdAfx.h"
#include "ExpressionTree.h"

ExpressionTree::ExpressionTree()
{
	rootNode = gcnew BinaryTreeNode("0");
}

ExpressionTree::ExpressionTree(String^ rootValue)
{
	rootNode = gcnew BinaryTreeNode(rootValue);
}

ExpressionTree::ExpressionTree(String^ rootValue, BinaryTree^ leftSubTree, BinaryTree^ rightSubTree)
{
	rootNode = gcnew BinaryTreeNode(rootValue);

	addLeftSubTree(leftSubTree);
	addRightSubTree(rightSubTree);
}

int ExpressionTree::ParseExpressionTree(BinaryTreeNode^ inputRootNode)
{
	// Get nodes
	BinaryTreeNode^ left = inputRootNode->getLeftChild();
	BinaryTreeNode^ right = inputRootNode->getRightChild();

	// If leaf node
	if( left == nullptr && right == nullptr )
	{
		// Return node value
		return Convert::ToInt16( inputRootNode->getNodeValue() );
	}
	else
	{
		// Return operation on +-*/
		switch( Convert::ToChar( inputRootNode->getNodeValue() ) )
		{			
			case '+': return ParseExpressionTree(left) + ParseExpressionTree(right);

			case '-': return ParseExpressionTree(right) - ParseExpressionTree(left);

			case '*': return ParseExpressionTree(left) * ParseExpressionTree(right);

			case '/': return ParseExpressionTree(right) / ParseExpressionTree(left);
			
			default:  throw gcnew Exception("Bad operator found");
		}
	}
}

void ExpressionTree::Parse(BinaryTreeNode^ inputRootNode, ListBox^ targetListBox)
{
	targetListBox->Items->Add(ParseExpressionTree(inputRootNode));
}

void ExpressionTree::PostFix(BinaryTreeNode^ inputRootNode, ListBox^ targetListBox)
{
	// Base case
	if(inputRootNode != nullptr)
	{
		// Recurse down the left sub tree
		BinaryTreeNode^ leftRoot = inputRootNode->getLeftChild();
		PostFix(leftRoot, targetListBox);

		// Recurse down the right sub tree
		BinaryTreeNode^ rightRoot = inputRootNode->getRightChild();
		PostFix(rightRoot, targetListBox);

		if(targetListBox->Items->Count <= 1)
			targetListBox->Items->Add("");

		// Process the current root
		String^ currValue = targetListBox->Items[1] + inputRootNode->getNodeValue();
		
		targetListBox->Items[1] = currValue;
	}
}
