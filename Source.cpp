// Jaime Dano (Barnhill)
// CIS 1202 101
// 4/22/2021
// Description: a function to calculate character offsets, throwing exceptions in error conditions

#include <iostream>  //console
#include <iomanip>   //formating cout
#include <string>  //String stuff - possibly not needed
#include <cmath>

using namespace std;

//Function Protocols --------------------------

//Char function
char character(char start, int offset);

//Template function for doubles and floats
template <class T>
T half(T num) {
	return num / 2;
}

//Half function specifically for int
int half(int);

//Main function protocols
int math_stuff();
int exception_assign();

int main() {

	char assignment;
	
	do {
		//Which assignment?
		cout << "Which assignment?" << endl;
		cout << "a. 15a" << endl << "b. 15b" << endl << "q. Quit" << endl;
		cin >> assignment;

		//Call 1st assignment
		if (assignment == 'a') {
			exception_assign();
		}

		//Call 2nd assignment
		else if (assignment == 'b') {
			math_stuff();
		}

		else if (assignment == 'q') {
			//Quit!
			// END Program
			system("pause");
			return 0;
		}

		//Invalid
		else {
			cout << "Invalid, try again." << endl;
		}

	} while (assignment != 'q');

	// END Program
	system("pause");
	return 0;

}

//15b ------------------------------
int math_stuff() {

	//test data
	double a = 7.0;
	float b = 5.0f;
	int c = 3;

	cout << "Half of " << a << " is " << half(a) << endl;
	cout << "Half of " << b << " is " << half(b) << endl;
	cout << "Half of " << c << " is " << half(c) << endl;

	// END Program
	system("pause");
	return 0;
}

int half(int d) {

	//Turn the into into a float, call the half template function
	float temp_f = static_cast<float>(d);
	temp_f = half(temp_f);
	d = round(temp_f);

	return d;
}

//15a ------------------------------
int exception_assign() {

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