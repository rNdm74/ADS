#include "StdAfx.h"
#include "VigenereCipher.h"

VigenereCipher::VigenereCipher()
{
}

/// <precondition>
/// Clean up any resources being used.
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
/// Clean up any resources being used.
/// </postcondition>

/// <precondition>
/// Clean up any resources being used.
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
/// Clean up any resources being used.
/// </postcondition>