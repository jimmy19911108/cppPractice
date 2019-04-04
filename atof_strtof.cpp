#include <iostream>
using std::cout;
using std::endl;

#include <cstdlib>

int main() {
	char test[] = { "123.456 223.456" };
	char *endPtr;

	cout << atof(test) << endl;
	cout << strtof(test, &endPtr) << endl;
	cout << strtof(endPtr, NULL);

	return 0;
}