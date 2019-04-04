#include<iostream>

using namespace std;

class test {
public:
	virtual void show() {
		cout << "test";
	}
};

class test2 :public test {
public:
	void show() {
		cout << "test2";
	}
};

class test3 :public test {
public:
	void show() {
		cout << "test3";
	}
};

int main() {
	test *t;
	test2 t2;
	test3 t3;
	test  t4;

	t = &t4;
	t->show();

	t = &t2;
	t->show();

	t = &t3;
	t->show();

	return EXIT_SUCCESS;
}