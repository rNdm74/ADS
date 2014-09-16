#pragma once

#include "StdAfx.h"

using namespace System;
using namespace System::Diagnostics;


template<class T>
ref class TNode
{
private:
	int freq;
	T data;

public:
	property int Frequency
	{
		int get() { return freq; }
        void set(int value) { freq = value; }    
    }

	property T Data
	{
		T get() { return data; }
        void set(T value) { data = value; }    
    }

	TNode<T>^ Left;
	TNode<T>^ Right;
	
	TNode();
	TNode(T data);
	TNode(T data, int freq);
};

/// <summary>
/// Summary for TNode
///	
/// PRE-CONDITION:	None
/// POST-CONDITION: Left and Right are set to nullptr 
/// </summary>
template<class T> TNode<T>::TNode()
{
	Left = nullptr;
	Right = nullptr;
};

/// <summary>
/// Summary for TNode
///	
/// PRE-CONDITION:	Must provide data
/// POST-CONDITION: data assigned, Left and Right are set to nullptr
/// </summary>
template<class T> TNode<T>::TNode(T data)
{	
	this->data = data;	

	Left = nullptr;
	Right = nullptr;
};

/// <summary>
/// Summary for TNode
///	
/// PRE-CONDITION:	Must provide data and frequency
/// POST-CONDITION: data and frequency are assigned, Left and Right are set to nullptr
/// </summary>
template<class T> TNode<T>::TNode(T data, int freq)
{	
	this->data = data;	
	this->freq = freq;

	Left = nullptr;
	Right = nullptr;
};

template<class T>
ref class Tree: public IComparable
{
protected:
	TNode<T>^ rootNode;

public:
	virtual Int32 CompareTo( Object^ obj ) 
	{
		if (obj == nullptr) return 1;

		if ( obj->GetType() == Tree<T>::typeid ) 
		{
			Tree<T>^ temp = dynamic_cast<Tree<T>^>(obj);

			return rootNode->Frequency.CompareTo( temp->getRootNode()->Frequency );
		}

		throw gcnew ArgumentException(  "Object is not a Tree" );
    }

	virtual String^ ToString() override
    {
		return rootNode->Frequency + ":" + rootNode->Data;
    }
	
	Tree();
	Tree(T rootValue, int freq);
	Tree(T rootValue, int freq, Tree<T>^ leftSubTree, Tree<T>^ rightSubTree);

	int Count();
	bool IsEmpty();
	
	void setRootNodeValue(T newRootNodeValue);
	T getRootNodeValue();
	TNode<T>^ getRootNode();

	void addLeftSubTree(Tree<T>^ newLeftSubTree);
	void addRightSubTree(Tree<T>^ newRightSubTree);

	int TreeHeight(TNode<T>^ node);
};

/// <summary>
/// Summary for Tree
///	
/// PRE-CONDITION:	None
/// POST-CONDITION: A default node is created 
/// </summary>
template<class T> Tree<T>::Tree()
{
	rootNode = gcnew TNode<T>();
};

/// <summary>
/// Summary for Tree
///	
/// PRE-CONDITION:	Must provide the rootTrees value its frequency
/// POST-CONDITION: The node is created with the rootValue and frequency 
/// </summary>
template<class T> Tree<T>::Tree(T rootValue, int freq)
{
	rootNode = gcnew TNode<T>(rootValue, freq);
};

/// <summary>
/// Summary for Tree
///	
/// PRE-CONDITION:	Must provide the rootTrees value its frequency, and the left and right subtrees
/// POST-CONDITION: The node is created and the left and right subtrees are added 
/// </summary>
template<class T> Tree<T>::Tree(T rootValue, int freq, Tree<T>^ leftSubTree, Tree<T>^ rightSubTree)
{
	rootNode = gcnew TNode<T>(rootValue, freq);

	addLeftSubTree(leftSubTree);
	addRightSubTree(rightSubTree);
};

/// <summary>
/// Summary for IsEmpty
///	
/// PRE-CONDITION:	None
/// POST-CONDITION: Returns if the tree is empty or not
/// </summary>
template<class T> bool Tree<T>::IsEmpty()
{
	return (rootNode == nullptr);
};

/// <summary>
/// Summary for setRootNodeValue
///	
/// PRE-CONDITION:	Must provide data to be set
/// POST-CONDITION: Sets the rootnodes data
/// </summary>
template<class T> void Tree<T>::setRootNodeValue(T newRootNodeValue)
{
	rootNode->Data = newRootNodeValue;
};

/// <summary>
/// Summary for getRootNodeValue
///	
/// PRE-CONDITION:	None
/// POST-CONDITION: Returns the data of the root node
/// </summary>
template<class T> T Tree<T>::getRootNodeValue()
{
	return rootNode->Data;
};

/// <summary>
/// Summary for getRootNode
///	
/// PRE-CONDITION:	None
/// POST-CONDITION: Returns the rootNode fo the tree
/// </summary>
template<class T> TNode<T>^ Tree<T>::getRootNode()
{
	return rootNode;
};

/// <summary>
/// Summary for addLeftSubTree
///	
/// PRE-CONDITION:	Must provide tree to be added
/// POST-CONDITION: Assigned to the Trees LeftNode  
/// </summary>
template<class T> void Tree<T>::addLeftSubTree(Tree<T>^ newLeftSubTree)
{
	rootNode->Left = newLeftSubTree->getRootNode();
};

/// <summary>
/// Summary for addRightSubTree
///	
/// PRE-CONDITION:	Must provide tree to be added
/// POST-CONDITION: Assigned to the Trees RightNode 
/// </summary>
template<class T> void Tree<T>::addRightSubTree(Tree<T>^ newRightSubTree)
{ 
	rootNode->Right = newRightSubTree->getRootNode();
};

/// <summary>
/// Summary for TreeHeight Recursive
///	
/// PRE-CONDITION:	Must provide a node of a tree
/// POST-CONDITION: Returns the height a the tree 
/// </summary>
template<class T> int Tree<T>::TreeHeight(TNode<T>^ node)
{
	if (node == nullptr) return 0;

	int left_height = TreeHeight(node->Left);
	int right_height = TreeHeight(node->Right);

	return (left_height > right_height) ? left_height + 1 : right_height + 1;
};