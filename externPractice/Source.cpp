#include<iostream>
using std::cout;
using std::endl;

int get_value();
void set_value(int);
int *get_values();
extern int a;

int main() {
	set_value(3);
	cout << "a =" << a << endl
		<< "get_value() = " << get_value() << endl;

	*(get_values()) = 4;

	cout << "a =" << a << endl
		<< "*get_value() = " << get_value() << endl;

	return 0;
}