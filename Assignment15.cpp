//Tommy Scherbauer
//CIS 1202.800
//May 1, 2025

//Program to calculate character offsets using exception handling

#include <iostream>
#include <cctype>
using namespace std;

//Function prototype
char character(char, int);

//Classes for the two exceptions
class invalidCharacterException {
public:
	const char* message;
	invalidCharacterException() : message("Invalid character") {}
	
};

class invalidRangeException {
public:
	const char* message;
	invalidRangeException() : message("Invalid Range") {}
};

//function for "character"
char character(char start, int offset) {
	if (!isalpha(start)) {
		throw invalidCharacterException();
	}

	char result = start + offset;

	if ((islower(start) && (result < 'a' || result > 'z')) || (isupper(start) && (result < 'A' || result > 'Z'))) {
		throw invalidRangeException();
	}

	return result;
}

int main()
{
	try {
		cout << "character ('a', 1): " << character('a', 1) << endl;
	}
	catch (invalidCharacterException& error) {
		cout << "Character threw exception: " << error.message << endl;
	}
	catch (invalidRangeException& error) {
		cout << "Character threw exception: " << error.message << endl;
	}

	try {
		cout << "character ('a', -1): " << character('a', -1) << endl;
	}
	catch (invalidCharacterException& error) {
		cout << "Character threw exception: " << error.message << endl;
	}
	catch (invalidRangeException& error) {
		cout << "Character threw exception: " << error.message << endl;
	}

	try {
		cout << "character ('Z', -1): " << character('Z', -1) << endl;
	}
	catch (invalidCharacterException& error) {
		cout << "Character threw exception: " << error.message << endl;
	}
	catch (invalidRangeException& error) {
		cout << "Character threw exception: " << error.message << endl;
	}

	try {
		cout << "character ('?', 5): " << character('?', 5) << endl;
	}
	catch (invalidCharacterException& error) {
		cout << "Character threw exception: " << error.message << endl;
	}
	catch (invalidRangeException& error) {
		cout << "Character threw exception: " << error.message << endl;
	}

	try {
		cout << "character ('A', 32): " << character('A', 32) << endl;
	}
	catch (invalidCharacterException& error) {
		cout << "Character threw exception: " << error.message << endl;
	}
	catch (invalidRangeException& error) {
		cout << "Character threw exception: " << error.message << endl;
	}

	return 0;
}



