#include <iostream>
#include <random>
#include <ctime>

#define LENGTH 100

using namespace std;

void createSeq(int *num_seq, int length) {
	srand(time(0));
	
	for (int i = 0; i < length; i++) {
		num_seq[i] = rand() % length;
	}
}

void printSeq(int *num_seq) {
	for (int i = 0; i < LENGTH; i++) {
		cout << num_seq[i] << " ";
	}
	cout << endl << endl;
}

void bubbleSort(int *num_seq) {
	int i;
	int j;

	for (i = 0; i < LENGTH-1; i++) {
		for (j = 0; j < LENGTH-1-i; j++) {
			if (num_seq[j] > num_seq[j + 1])
				swap(num_seq[j], num_seq[j + 1]);
		}
	}
}

void selectionSort(int *num_seq) {

	int min_index;

	for (int i = 0; i < LENGTH; i++) {
		min_index = i;

		for (int j = i + 1; j < LENGTH; j++) {
			if (num_seq[j] < num_seq[min_index])
				min_index = j;
		}
		if (i != min_index) {
			swap(num_seq[i], num_seq[min_index]);
		}
	}
}

////////////////////////////////////////////////////////////////////////////
void copyArray(int *dst, int *src, int ibegin, int iend) {
	
	int length = iend - ibegin + 1;
	
	for (int i = 0; i < length; i++) {
		dst[i] = src[i + ibegin];
	}
}

void mergeSeq(int ibegin,int imiddle, int iend, int *num_seq) {
	
	int ileft = 0;
	int iright = 0;

	int leftSubLength = imiddle - ibegin + 1;
	int rightSubLength = iend - imiddle;
	int *leftSub = new int[leftSubLength];
	int *rightSub = new int[rightSubLength];

	copyArray(leftSub, num_seq, ibegin, imiddle);
	copyArray(rightSub, num_seq, imiddle+1, iend);

	for (int i = ibegin; i <= iend; i++) {
		if (ileft < leftSubLength && (iright >= rightSubLength || leftSub[ileft] < rightSub[iright])) {
			num_seq[i] = leftSub[ileft++];
		}
		else {
			num_seq[i] = rightSub[iright++];
		}
	}

	delete[]leftSub;
	delete[]rightSub;
}

void splitMergeSeq(int ibegin, int iend, int *num_seq) {

	int length = iend - ibegin;
	int imiddle = (iend + ibegin) / 2;
	
	if (length < 1) {
		return;
	}
	else if (length > 1) {	
		splitMergeSeq(ibegin, imiddle, num_seq);	//split left sequence
		splitMergeSeq(imiddle+1, iend, num_seq);	//split right sequence
	}
	mergeSeq(ibegin, imiddle, iend, num_seq);
}

void mergeSort(int *num_seq) {

	splitMergeSeq(0, LENGTH-1, num_seq);
}
////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////
int maximum(int iparent,int length, int *num_seq) {
	/*return the index of the max element*/

	int ilchild = iparent * 2 + 1;
	int irchild = ilchild + 1;
	int imax;

	if (ilchild < length && irchild < length) {
		if (num_seq[ilchild] < num_seq[irchild]) {
			imax = irchild;
		}
		else {
			imax = ilchild;
		}
		if (num_seq[imax] < num_seq[iparent]) {
			imax = iparent;
		}
	}
	else if (ilchild < length) {
		if (num_seq[iparent] < num_seq[ilchild]) {
			imax = ilchild;
		}
		else {
			imax = iparent;
		}
	}
	else {
		imax = iparent;
	}

	return imax;
}

void maxHeapify(int length, int *num_seq) {
	
	int imax = -1;
	int target;
	
	for (int i = length - 1; i >= 0; i--) {
		target = i;
		while (true) {
			imax = maximum(target, length, num_seq);
			if (imax != target) {
				swap(num_seq[target], num_seq[imax]);
				target = imax;
			}
			else {
				break;
			}
		}
	}
}

void heapSort(int *num_seq) {

	int *tmp = new int[LENGTH];
	memcpy(tmp, num_seq, LENGTH * sizeof(int));

	for (int i = LENGTH-1; i >= 0; i--) {
		maxHeapify(i+1, tmp);
		swap(tmp[0], tmp[i]);
		num_seq[i] = tmp[i];
	}

	delete[]tmp;

}
////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////
int pivotSelect(int ibegin, int iend) {
	
	int length = iend - ibegin + 1;

	srand(time(0));

	return ibegin + rand() % length;
}

void partQuickSort(int ibegin, int iend, int *num_seq) {

	int pivot = pivotSelect(ibegin, iend);
	int ileft = ibegin;

	swap(num_seq[pivot], num_seq[iend]);

	for (int i = ibegin; i < iend; i++) {
		if (num_seq[i] <= num_seq[iend]) {
			swap(num_seq[i], num_seq[ileft++]);
		}
	}

	swap(num_seq[iend], num_seq[ileft]);

	if (ileft - ibegin > 1) {
		partQuickSort(ibegin, ileft - 1, num_seq);
	}
	if (iend - ileft > 1) {
		partQuickSort(ileft + 1, iend, num_seq);
	}

}

void quickSort(int *num_seq) {
	partQuickSort(0, LENGTH - 1, num_seq);
}
////////////////////////////////////////////////////////////////////////////

int main() {

	int *num_seq = new int[LENGTH];
	int *bubble_seq = new int[LENGTH];
	int *selection_seq = new int[LENGTH];
	int *merge_seq = new int[LENGTH];
	int *heap_seq = new int[LENGTH];
	int *quick_seq = new int[LENGTH];

	createSeq(num_seq, LENGTH);
	printSeq(num_seq);

	memcpy(bubble_seq, num_seq, LENGTH * sizeof(int));
	bubbleSort(bubble_seq);
	printSeq(bubble_seq);

	memcpy(selection_seq, num_seq, LENGTH * sizeof(int));
	selectionSort(selection_seq);
	printSeq(selection_seq);

	memcpy(merge_seq, num_seq, LENGTH * sizeof(int));
	mergeSort(merge_seq);
	printSeq(merge_seq);

	memcpy(heap_seq, num_seq, LENGTH * sizeof(int));
	heapSort(heap_seq);
	printSeq(heap_seq);

	memcpy(quick_seq, num_seq, LENGTH * sizeof(int));
	quickSort(quick_seq);
	printSeq(quick_seq);

	system("pause");

	delete[]quick_seq;
	delete[]heap_seq;
	delete[]merge_seq;
	delete[]bubble_seq;
	delete[]selection_seq;
	delete[]num_seq;

	return 0;
}