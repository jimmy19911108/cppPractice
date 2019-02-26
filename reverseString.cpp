#include<iostream>
#include<string>
#include<string.h>
#include<cstring>
#include<algorithm>

using namespace std;

void reverseString(string&);

int main() {

	string input;

	cout << "Input a string: ";
	cin >> input;

	reverse(input.begin(), input.end());
	cout << "\nReverse by algorithm: " << input;

	reverseString(input);
	cout << "\nReverse by myself: " << input << "\n\n";

	//strrev is not recommended by VS. We must use _strrev and need to incude string.h.
	//However, _strrev caused the memory error.

	/*for (int i = 0; i < input.length(); i++) {
		char_input[i] = input[i];
	}
	cout << "\nreverse by string: " << _strrev(char_input);
	cout << "\nchar_input: ";
	for (int i = 0; i < input.length(); i++)
		cout << char_input[i];*/

	system("pause");

	return 0;
}

void reverseString(string &str) {
	for (int i = 0; i < str.length() / 2; i++)
		swap(str[i], str[str.length() - i - 1]);
}
