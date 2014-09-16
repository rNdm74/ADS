#pragma once

#include "StdAfx.h"

#include "Tree.h"
#include "PriorityQueue.h"

using namespace System;
using namespace System::Collections::Generic;
using namespace System::Diagnostics;
using namespace System::Windows::Forms;
using namespace System::Drawing;

ref class HuffmanCode
{
public: 
	String^ Code;	
	int Frequency;

	/// <summary>
	/// Summary for HuffmanCode
	///	
	/// PRE-CONDITION:	Constructor takes 2 arguments, String^ and int
	///					String^ is the binary code
	///					int is the frequency of the code
	///
	/// POST-CONDITION: code and freq are assigned
	/// </summary>
	HuffmanCode(String^ code, int freq)
	{
		this->Code = code;
		this->Frequency = freq;
	}
};

// Define types used in class
typedef String HuffCode;
typedef Dictionary<String^, HuffmanCode^> HuffCodeMap;
typedef Dictionary<String^, int> FrequencyMap;

ref class Huffman
{
private:
	Tree<String^>^ rootTree;
	HuffCodeMap^ huffMap;
	FrequencyMap^ freqMap;
public:
	property Tree<String^>^ Root
	{
		Tree<String^>^ get() { return rootTree; }
        void set(Tree<String^>^ value) { rootTree = value; }    
    }

	property HuffCodeMap^ Codes
	{
		HuffCodeMap^ get() { return huffMap; }
        void set(HuffCodeMap^ value) { huffMap = value; }    
    }

	String^ HuffCodeLength()
	{
		int huffCodeLength = 0;

		for each( KeyValuePair<String^, HuffmanCode^> kvp in huffMap )
		{
			huffCodeLength += (kvp.Value->Code->Length * kvp.Value->Frequency);
		}

		return Convert::ToString(huffCodeLength);
	}

	String^ FixedCodeLength(int codeLength)
	{
		int fixedCodeLength = 0;

		for each( KeyValuePair<String^, HuffmanCode^> kvp in huffMap )
		{
			fixedCodeLength += (codeLength * kvp.Value->Frequency);
		}

		return Convert::ToString(fixedCodeLength);
	}

		
	Huffman();
	String^ Encode(array<TextBox^>^ symbols, array<TextBox^>^ freq);
	String^ Encode(String^ s);
	String^ Decode(String^ s);
	void BuildTree(FrequencyMap^ map);
	void GenerateCodes(TNode<String^>^ node, HuffCode^ %prefix, HuffCodeMap^ %map);
	void DrawCodes(DataGridView^ dgv);
	void DrawTree(int width, int height, Graphics^ g);
	void Draw(TNode<String^>^ node, int minX, int maxX, int y, int yStep, Graphics^ g);
	void BuildFrequencyMap(String^ input, FrequencyMap^ %map);
	void BuildFrequencyMap(array<TextBox^>^ symbols, array<TextBox^>^ freq, FrequencyMap^ %map);
};

/// <summary>
/// Summary for Huffman
///	
/// PRE-CONDITION:	None
/// POST-CONDITION: Instantiates the Tree, Huffmap and FreqMap dictionaries
/// </summary>
Huffman::Huffman()
{
	rootTree = gcnew Tree<String^>();
	huffMap = gcnew HuffCodeMap();
	freqMap = gcnew FrequencyMap();
};

/// <summary>
/// Summary for BuildFrequencyMap
///	
/// PRE-CONDITION:	Must provide, the input string to calculate char frequencies
///					Must provide, FrequencyMap for the char and frequencies to be stored
///
/// POST-CONDITION: The frequencies are caluclated and the added to the map that was passed in
///					The result is a dictionary populated with char frequencies from a passed in string
/// </summary>
void Huffman::BuildFrequencyMap(String^ input, FrequencyMap^ %map)
{
	// Create array to hold frequencys of char all char codes
	array<int>^ frequencies = gcnew array<int>(127);

	// Populate frequencies
	for(int i = 0; i < input->Length; i++)
		frequencies[input[i]]++;

	// Add all frequencies greater than 0 to map
	for(int i = 0; i < frequencies->Length; i++)
	{
		if(frequencies[i] != 0)
		{
			map->Add(Convert::ToChar(i).ToString(), frequencies[i]);
		}
	}
};

/// <summary>
/// Summary for BuildFrequencyMap
///	
/// PRE-CONDITION:	Must provide, array of textboxs that hold chars
///					Must provide, array of textboxs that hold the chars frequencies
///					Must provide, FrequencyMap for the char and frequencies to be stored
///
/// POST-CONDITION: The frequencies are caluclated and the added to the map that was passed in
///					The result is a dictionary populated with char frequencies from a passed in textboxes
/// </summary>
void Huffman::BuildFrequencyMap(array<TextBox^>^ symbols, array<TextBox^>^ freq, FrequencyMap^ %map)
{
	// Loop through symbols
	for(int i = 0; i < symbols->Length; i++)
	{
		// Get the values
		String^ s = symbols[i]->Text;
		String^ f = freq[i]->Text;

		// If they are not empty add to map
		if( s != "" && f != "")
		{
			map->Add(s, Convert::ToInt16(f));
		}
	}
};

/// <summary>
/// Summary for Encode
///	
/// PRE-CONDITION:	Must provide, array of textboxs that hold chars
///					Must provide, array of textboxs that hold the chars frequencies
///
/// POST-CONDITION: Frequency map is built, the the tree is built and the codes are generated from the tree
///					A string is returned for user feedback
/// </summary>
String^ Huffman::Encode(array<TextBox^>^ symbols, array<TextBox^>^ freq)
{	
	// Build the map
	BuildFrequencyMap(symbols, freq, freqMap);
	// Build the huffman tree
	BuildTree(freqMap);
	// Get the codes from the tree
	GenerateCodes(rootTree->getRootNode(), gcnew HuffCode(""), huffMap);

	// Returns user feedback
	return "Manual encode selected";
};

/// <summary>
/// Summary for Encode
///	
/// PRE-CONDITION:	Must provide string to be encoded
/// POST-CONDITION: Frequency map is built, the the tree is built and the codes are generated from the tree
///					The resulting huffcodes are returned for user feedback
/// </summary>
String^ Huffman::Encode(String^ s)
{
	// Build the map
	BuildFrequencyMap(s, freqMap);
	// Build the huffman tree
	BuildTree(freqMap);
	// Get the codes from the tree
	GenerateCodes(rootTree->getRootNode(), gcnew HuffCode(""), huffMap);

	// Generate user feedback
	String^ output = "";

	for each( wchar_t c in s  )
		if(huffMap->ContainsKey(c.ToString()))
			output += huffMap[c.ToString()]->Code;

	// Return user feedback
	return output;
};

/// <summary>
/// Summary for Decode
///	
/// PRE-CONDITION:	Must provide string to be decoded
/// POST-CONDITION: Walks across the string and builds a string from the 1's, and 0's then returns the output 
/// </summary>
String^ Huffman::Decode(String^ s)
{
	// Create output string for user feedback
	String^ output = "";

	// Init the walker
	int walker = 0;

	// Get the root node
	TNode<String^>^ r = Root->getRootNode();

	// While there is a char to read
	while(walker < s->Length)
	{
		// If 1 set left else if 0 set right
		if(s[walker].ToString() == "1")
			r = r->Left;
		else if(s[walker].ToString() == "0")
			r = r->Right;

		// When at leaf node
		if(r->Left == nullptr && r->Right == nullptr)
		{
			// Append output string
			output += r->Data;
		
			// Go back to top of tree
			r = Root->getRootNode();
		}

		// Move to next char
		walker++;		
	}

	// Return user feedback
	return output;
};

/// <summary>
/// Summary for BuildTree
///	
/// PRE-CONDITION:	Must provide a frequency map of chars and their frequncies
/// POST-CONDITION: A huffman tree is returned  
/// </summary>
void Huffman::BuildTree(FrequencyMap^ map)
{
	// Instantiate Priority queue
	PriorityQueue<Tree<String^>^>^ trees = gcnew PriorityQueue<Tree<String^>^>();
 
	// Add new trees to queue
	for each( KeyValuePair<String^, int> kvp in map )
	{
		trees->Push(gcnew Tree<String^>(kvp.Key, kvp.Value));
	}

	// While there is more than one tree
    while (trees->Count() > 1)
    {
		// Get the two smallest trees
		Tree<String^>^ childL = trees->Pop();
        Tree<String^>^ childR = trees->Pop(); 
        
		// Create the new tree data and freq values
		int freq = childL->getRootNode()->Frequency + childR->getRootNode()->Frequency;
		String^ data = childL->getRootNode()->Data + childR->getRootNode()->Data;
 
		// Create the new tree from the two children
        Tree<String^>^ parent = gcnew Tree<String^>(data, freq, childL, childR);

		// Add it back to the queue
        trees->Push(parent);
    }

	// Pop the finished tree and return
    rootTree = trees->Pop();

};

/// <summary>
/// Summary for GenerateCodes Recursive
///	
/// PRE-CONDITION:	Must provide the node, a Huffcode holder for recursion, and a Map that holds the codes
/// POST-CONDITION: The Huffcode is modified on each call and the built map is then added to the map
/// </summary>
void Huffman::GenerateCodes(TNode<String^>^ node, HuffCode^ %prefix, HuffCodeMap^ %map)
{
	// When at a leaf node
	if( node->Left == nullptr && node->Right == nullptr )
	{		
		// Add to the code map
		map->Add(node->Data, gcnew HuffmanCode(prefix, node->Frequency)); //node->Frequency + "\t| " +  
	}
	else
	{
		// Add 1 to prefix and recurse left 
		HuffCode^ leftPrefix = prefix;
		leftPrefix += "1";
        GenerateCodes(node->Left, leftPrefix, map);
 
		// Add 0 to prefix and recurse right
        HuffCode^ rightPrefix = prefix;
        rightPrefix += "0";
        GenerateCodes(node->Right, rightPrefix, map);
	}
};

/// <summary>
/// Summary for DrawCodes
///	
/// PRE-CONDITION:	Must provide a datagrid view for the codes to be displayed to the user
/// POST-CONDITION: all codes in the huffmap are added to the datagridview
/// </summary>
void Huffman::DrawCodes(DataGridView^ dgv)
{
	// Clear the grid view
	dgv->Rows->Clear();

	// Add rows from the map
	for each( KeyValuePair<String^, HuffmanCode^> kvp in huffMap )
	{					 
		dgv->Rows->Add(kvp.Key, kvp.Value->Code, kvp.Value->Frequency);
	}
};

/// <summary>
/// Summary for DrawTree
///	
/// PRE-CONDITION:	Must provide the width and height for display and the graphics canvas
/// POST-CONDITION: The recusive draw function is called to draw the tree to the canvas 
/// </summary>
void Huffman::DrawTree(int width, int height, Graphics^ g)
{
	// Clear the canvas
	g->Clear(Color::White);

	// Get the tree depth
	int treeHeight = Root->TreeHeight(Root->getRootNode());

	// Draw the tree to the canvas
	Draw(Root->getRootNode(), 0, width, 0, height / treeHeight, g);
};

/// <summary>
/// Summary for Draw Recursive
///	
/// PRE-CONDITION:	Must provide Node to be drawn, minX distance, maxX distance, y position, the yStep distance, and the graphics canvas
/// POST-CONDITION: The Node is printed and the lines connecting the nodes are drawn to the canvas 
/// </summary>
void Huffman::Draw(TNode<String^>^ node, int minX, int maxX, int y, int yStep, Graphics^ g)
{
	// Node data
	String^ s = node->Data + " : " + node->Frequency;
        
	// Set font
    Font^ stringFont = gcnew Font("Arial", 8);

	// Create size holder
	SizeF^ stringSize = gcnew SizeF();
	
	// Get the size of the string
	stringSize = g->MeasureString(s, stringFont, 200);

	// Get is width and height
	int width = stringSize->Width;
	int height = stringSize->Height;

	// 
	int xSep = Math::Min((maxX - minX)/8, 10);

	// Draw the node
	g->DrawString(s ,stringFont,Brushes::Red, (minX + maxX)/2 - width/2, (y + yStep/2)-height);

	// Recurse left and draw
	if (node->Left != nullptr) 
	{
		g->DrawLine(gcnew Pen(Color::Black), (minX + maxX)/2 - xSep, y + yStep/2 + 5, (minX + (minX + maxX)/2) / 2, y + yStep + yStep/2 - height);
		Draw(node->Left, minX, (minX + maxX)/2, y + yStep, yStep, g);
    }

	// Recurse right and draw
	if (node->Right != nullptr) 
	{
		g->DrawLine(gcnew Pen(Color::Black), (minX + maxX)/2 + xSep, y + yStep/2 + 5,(maxX + (minX + maxX)/2) / 2, y + yStep + yStep/2 - height);
		Draw(node->Right, (minX + maxX)/2, maxX, y + yStep, yStep, g);
    }
};