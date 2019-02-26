#include <iostream>

using std::cout;
using std::endl;

int main() {

	int a = 0;
	int *b; //int *b = a; error, cannot use int to initialize int*
	b = &a;
	int *c = &a;
	int **d;
	d = &c;
	int *e;
	e = c;

	cout << "a" << a << endl;
	cout << "b" << b << endl;
	cout << "c" << c << endl;
	cout << "d" << d << endl;
	cout << "*d" << *d << endl;
	cout << "e" << e << endl;

	system("pause");
	return 0;
}