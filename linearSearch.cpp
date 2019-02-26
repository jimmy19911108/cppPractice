#include<iostream>

using std::cout;
using std::cin;
using std::endl;

int linear_search(const int[], int, const int);

int main() {

	const int arraySize = 100;
	int key;
	int data[arraySize];

	cout << "Enter Integer Search Key: ";
	cin >> key;

	for (int i = 0; i < arraySize; i++) {
		data[i] = 2 * i;
	}

	int element = linear_search(data, key, arraySize);

	if (element == -1) {
		cout << "Value not found." << endl;
	}
	else {
		cout << "Found value in element " << element << endl;
	}

	system("pause");
	return 0;
}

int linear_search(const int data[], int key, const int arraySize) {
	for (int i = 0; i < arraySize; i++) {
		if (data[i] == key) {
			return i;
		}
	}

	return -1;
}