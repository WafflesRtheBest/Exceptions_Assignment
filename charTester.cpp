// Jaime Dano (Barnhill)
// CIS 1202 101
// 4/19/2021
// Description: a function to calculate character offsets, throwing exceptions in error conditions

#include <iostream>  //console
#include <iomanip>   //formating cout
#include <string>  //String stuff - possibly not needed

using namespace std;

//Function protocol
char character(char start, int offset);

int main() {
	
	//Variables
	char the_char, new_char; 
	int the_int;

	//Get input to test
	cout << "Type a char:" << endl;
	cin >> the_char;
	cout << "Type an int:" << endl;
	cin >> the_int;

	try {
		//Check if input is a letter and if not throw to the exception
		if (isalpha(the_char)) {
			new_char = character(the_char, the_int);
		}
		else {
			throw (the_char);
		}
	}
	catch (char wrong_char) {
		cout << "InvalidCharacterException" << endl; 
		// END Program - otherwise below code gets mad
		system("pause");
		return 0;
	}

	//Work with the new character
	try {
		//If it's a letter print a message to confirm for testing and if not throw it
		if (isalpha(new_char)) {
			cout << new_char << " is the new char" << endl;
		}
		else {
			throw (new_char);
		}
	}
	//Print the error message and the wrong char
	catch (char wrong_char) {
		cout << "invalidRangeException: " << wrong_char << endl;
	}

	// END Program
	system("pause");
	return 0;
}

//Change the Char to an int, to the offset, and then back to a char
char character(char start, int offset) {
	//Variables
	int new_num;
	char new_char;

	//Assign new char based on the offset and then return the new char
	new_num = int(start) + offset;
	new_char = char(new_num);
	return new_char;
}