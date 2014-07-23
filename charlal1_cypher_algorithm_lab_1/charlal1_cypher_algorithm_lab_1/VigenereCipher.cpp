#include "StdAfx.h"
#include "VigenereCipher.h"

VigenereCipher::VigenereCipher()
{
}

/// <precondition>
/// Function takes string(word) and string(key) used for cipher
/// </precondition>
String^ VigenereCipher::enCipher(String^ word, String^ key)
{
	// Enciphered word
	String^ out;

	// Loop through word
	for(int charPointer = 0, keyPointer = 0; charPointer < word->Length; charPointer++)
	{
		char c = word[charPointer];
	
		// Check if character is valid		
		if(c >= 'a' && c <= 'z')		// Check if input char is lower			
			c += 'A' - 'a';				// Convert to upper		
		else if(c < 'A' || c > 'Z')		// Strip invalid chars 
			continue;

		// Add enciphered character to enciphered word
		// Calculate shift then mod by alphabet length plus first char value
		out += Convert::ToChar((c + key[keyPointer] - DOUBLE * 'A') % ALPHABET_LENGTH + 'A');
	  
		// Reset keyPointer
		keyPointer = (keyPointer + 1) % key->Length;		
	}

	// Return enciphered word
	return out;
}
/// <postcondition>
/// Result will return a the input string ciphered using the input key
/// </postcondition>

/// <precondition>
/// Function takes any string(word) and string(key) used for decipher
/// </precondition>
String^ VigenereCipher::deCipher(String^ word, String^ key)
{
	// Enciphered word
	String^ out;

	// Loop through word
	for(int charPointer = 0, keyPointer = 0; charPointer < word->Length; charPointer++)
	{
		char c = word[charPointer];
	
		// Check if character is valid		
		if(c >= 'a' && c <= 'z')		// Check if input char is lower			
			c += 'A' - 'a';				// Convert to upper		
		else if(c < 'A' || c > 'Z')		// Strip invalid chars 
			continue;

		// Add enciphered character to enciphered word
		// Calculate shift then mod by alphabet length plus first char value
		out += Convert::ToChar((c - key[keyPointer] + ALPHABET_LENGTH) % ALPHABET_LENGTH + 'A');
	  
		// Reset keyPointer
		keyPointer = (keyPointer + 1) % key->Length;		
	}

	// Return enciphered word
	return out;
}
/// <postcondition>
/// Result will return a the input string deciphered using the input key
/// </postcondition>

/// <precondition>
/// Function takes input text list that is read from a file
/// </precondition>
List<String^>^ VigenereCipher::deCipherTextFile(List<String^>^ inputText)
{
	List<String^>^ out = gcnew List<String^>();

	List<String^>^ keys = gcnew List<String^>();

	// Get KEY count
	int keyCount = Convert::ToInt16(inputText[0]);
	// Remove from list
	inputText->RemoveAt(0);

	// Get all keys from the list
	while(keyCount > 0)
	{
		keys->Add(inputText[--keyCount]);					 
		inputText->RemoveAt(keyCount);
	}

	// to-do optimize
	for(int j = 0; j < keys->Count; j++)
		for(int i = 0; i < inputText->Count; i++)
		{			
			// Decipher text
			String^ result = deCipher(inputText[i], keys[j]);
			// Checking
			if(result->Contains("ENCE") || result->Contains("TECH") ||result->Contains("THE") ||result->Contains("GOOD")||result->Contains("MORE")||result->Contains("SIX"))
				out->Add(result + " : " + keys[j]);							 						 
		}

	return out;
}
/// <postcondition>
/// Result will return a list input strings that have been deciphered
/// </postcondition>
