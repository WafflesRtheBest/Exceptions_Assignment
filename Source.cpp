// Jaime Dano (Barnhill)
// CIS 1202 101
// 4/19/2021
// Description: a function to calculate character offsets, throwing exceptions in error conditions

#include <iostream>  //console
#include <iomanip>   //formating cout
#include <string> // String stuff

using namespace std;

//Function protocol
char character(char start, int offset);

int main() {
	
	//Variables
	char the_char, new_char; 
	int the_int;

	//Get and test input
	cout << "Type a char:" << endl;
	cin >> the_char;
	cout << "Type an int:" << endl;
	cin >> the_int;

	try {
		
		if (isalpha(the_char)) {
			new_char = character(the_char, the_int);
		}
		else {
			throw (the_char);
		}
	}
	catch (char new_char) {
		cout << "InvalidCharacterException" << endl;
	}

	//Work with the new character
	try {

		if (isalpha(new_char)) {
			cout << new_char << " is the new char" << endl;
		}
		else {
			throw (new_char);
		}
	}
	catch (char wrong_char) {
		cout << "invalidRangeException: " << wrong_char << endl;
	}

	// END Program
	system("pause");
	return 0;
}

//Change the Char to an int, to the offset, and then back to a char
char character(char start, int offset) {
	int new_num;
	char new_char;

	new_num = int(start) + offset;
	new_char = char(new_num);
	return new_char;
}