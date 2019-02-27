#include <iostream>

using std::cout;
using std::endl;

struct Point {
	int num;
	Point* next;
};

Point getElement(Point*, int);
int listDelete(Point**, int);
void creatNode(Point*, int );
void insertNode( Point**, int, Point* );
void printNode( Point* );
void printList( Point* );
void clearList( Point** );
void initialList( Point** );
bool listEmpty( Point* );
int locateElem(Point*, int );
int listLength(Point*);


int main() {

	Point* list = new Point;

	Point a;
	Point b;
	Point c;

	creatNode(&a, 1);
	creatNode(&b, 2);
	creatNode(&c, 3);

	initialList(&list);
	insertNode(&list, 1, &a);
	insertNode(&list, 2, &b);
	insertNode( &list, 3, &c );

	cout << "List¡G";
	if ( !listEmpty( list ))
		printList( list );

	cout << "Current Node¡G";
	if( !listEmpty( list ))
		printNode( list );
	cout << endl;

	cout << "List length¡G" << listLength(list) << endl;

	listDelete(&list, 1);

	clearList(&list);

	delete list;

	return 0;
}

int locateElem(Point* list, int num) {
	Point* temp = new Point;
	temp = list;
	int count = 1;

	while ( temp -> num != num )
		if ( temp -> next != NULL ) {
			temp = temp->next;
			count++;
		}
		else
			return 0;

	return count;
}

Point getElement(Point* list, int elemNum) {

	Point* temp = (Point*)malloc(sizeof(Point));
	Point e;
	int count = 1;

	temp = list;

	while (count != elemNum) {
		count++;
		temp = temp -> next;
	}

	e = *temp;

	return e;
}

void clearList( Point** list ) {
	Point* temp = new Point;
	Point* next;
	temp = *list;

	if (temp->next != NULL) {
		next = temp->next;
		temp->next = NULL;
		clearList(&next);
	}
	initialList(&*list);
}

void initialList( Point** list ) {
	*list = NULL;
}

bool listEmpty( Point* list ) {
	if ( list -> next == NULL )
		return true;
	return false;
}

void creatNode(Point*node, int num )
{
	Point* temp = (Point*) malloc(sizeof( Point ));
	node -> num = num;
	node -> next = NULL;
}

void insertNode(Point** list, int i, Point* point2) {

	Point *ltemp = new Point;
	Point *head = new Point;
	int count = 1;

	head = *list;
	ltemp = *list;

	if (i > 1) {
		while (count != i-1) {
			if (ltemp->next != NULL)
				ltemp = ltemp->next;
			count++;
		}
		point2->next = ltemp->next;
		ltemp->next = point2;
		*list = head;
	}
	else {
		point2->next = ltemp;
		ltemp = point2;
		*list = ltemp;
	}
}

int listDelete( Point** list, int i ) {

	Point* head = *list;
	Point* temp = *list;
	Point* preTemp = new Point;

	int count = 1;
	if (i > 1) {
		while (count != i) {
			if (count == i - 1)
				preTemp = temp;
			temp = temp->next;
			count++;
		}
		preTemp->next = temp->next;
		temp->next = NULL;

		*list = head;
		return temp->num;
	}
	else {
		preTemp = temp;
		temp = temp->next;
		preTemp->next = NULL;
		*list = temp;

		return preTemp->num;
	}
}

int listLength(Point* list) {
	int count = 1;

	if (list != NULL)
		while (list->next != NULL) {
			list = list->next;
			count++;
		}
	else
		count = 0;

	return count;
}

void printNode( Point* point ) {
	cout << point -> num;
}

void printList( Point* list ) {

	Point* temp = ( Point* ) malloc(sizeof(Point));
	temp = list;

	while ( temp != NULL ) {
		printNode( temp );
		if( temp -> next != NULL )
			cout << " -> ";
		
		temp = temp -> next;
	}
	cout << endl;

	free(temp);
}