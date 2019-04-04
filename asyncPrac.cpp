#include<iostream>
using std::cout;
using std::endl;

#include<future>
using std::future;
using std::async;

using std::ref;

void test(int&);

int main() {
	int var = 14;

	future<void> f = async(test, ref(var));

	cout << var << endl;

	return 0;
}

void test(int &var) {
	var = 13;
	cout << var << endl;
}