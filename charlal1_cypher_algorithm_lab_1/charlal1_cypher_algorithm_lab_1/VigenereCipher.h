#pragma once

using namespace System;
using namespace System::IO;
using namespace System::Text;

#define ALPHABET_LENGTH 26
#define DOUBLE			2

ref class VigenereCipher
{
private:
	
public:
	VigenereCipher();
	String^ enCipher(String^ word, String^ key);
	String^ deCipher(String^ word, String^ key);
};