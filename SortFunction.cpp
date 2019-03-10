#include <iostream>
using std::cout;
using std::endl;

#include <algorithm>
using std::sort;

#include <vector>
using std::vector;

#include <iomanip>
using std::setw;

void printVector(vector<int>);
bool cmpElements(int, int);


struct myobj {
	bool operator () (int i, int j) { return i < j; }
}myobject;


int main() {

	int numList[10] = {8,5,4,6,7,9,1,0,2,3};

	vector<int> numVector (numList, numList+10);

	cout << "array¡G" << setw(10);
	printVector(numVector);

	sort(numVector.begin(), numVector.begin()+4);

	cout << "sort first four elements¡G" << setw(10);
	printVector(numVector);

	cout << "sort by function¡G";
	sort(numVector.begin(), numVector.end(), cmpElements);
	printVector(numVector);

	cout << "sort by object¡G";
	sort(numVector.begin(), numVector.end(), myobject);
	printVector(numVector);

	system("pause");
	return 0;
}

void printVector(vector<int> numVector) {
	for (int i = 0; i < numVector.size(); i++) {
		cout << numVector[i] << " ";
	}
	cout << endl;
}

bool cmpElements(int e1, int e2) {
	return e1 > e2;
}