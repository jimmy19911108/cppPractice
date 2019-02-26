#include <iostream>

using namespace std;

int main() {

	int a[2][4] = { {0,1,2,3},{10,11,12,13} };

	
	cout << a << endl;				//the head of the array address
	cout << a[0] << endl;			//the head of the array address
	cout << &a[0] << endl;			//the head of the array address
	cout << &a[0][0] << endl;		//the head of the array address
	cout << a + 1 << endl;			//the head of the array address add 16 bytes(int*column of array) = the head of the second row address
	cout << a[0] + 1 << endl;		//the head of the array address add 4 bytes(int)
	cout << &a[0] + 1 << endl;		//the head of the array address add 16 bytes(int*column of array) = the head of the second row address
	cout << &a[0][0] + 1 << endl;	//the head of the array address add 4 bytes(int)


	system("pause");
	return 0;
}