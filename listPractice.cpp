//a deck of cards(52 cards)
//get 5 cards in each hand
//11 hands in each comepare
//record the times that the last hand has a same hand in the other 10
//print the execution time and the recorded times

//list practice

#include<iostream>
using std::cout;
using std::cin;
using std::endl;

#include<list>
using std::list;

#include<ctime>

#define GET_CARD_TIMES 90000000

list<int> getCard();
bool getReapet(list<int>, int);
int checkReapet(list<list<int>>);

int main() {

	char time_str[26];
	time_t current_time;
	list<list<int>> cards;
	int repeatTimes = 0;
	srand(time(0));

	current_time = time(0);
	ctime_s(time_str, 26, &current_time);
	cout << time_str;

	for (int i = 1; i <= 100000; i++) {
		cards.push_back(getCard());

		if (i >= 11) {
			repeatTimes += checkReapet(cards);
			cards.pop_front();
		}
	}

	current_time = time(0);
	ctime_s(time_str, 26, &current_time);
	cout << time_str;

	cout << repeatTimes << endl;

	system("pause");
	return 0;
}

int checkReapet(list<list<int>> cards) {
	int count;
	int repeat = 0;
	list<int> tmp = cards.back();
	list<int>::iterator tmpIte;
	cards.pop_back();

	for (list<list<int>>::iterator i = cards.begin(); i != cards.end(); i++) {
		count = 0;
		tmpIte = tmp.begin();
		for (list<int>::iterator j = i->begin(); j != i->end(); j++, tmpIte++) {
			if (*tmpIte == *j)
				count++;
			else
				break;
		}
		if (count == 5)
			repeat++;
	}

	return repeat;
}

bool getReapet(list<int> cards, int card) {
	for (list<int>::iterator i = cards.begin(); i != cards.end(); i++) {
		if (card == *i)
			return true;
	}
	return false;
}

list<int> getCard() {
	list<int> cards;
	int tmp = 0;

	for (int i = 0; i < 5; i++) {
		tmp = (rand() % 52);
		
		if (getReapet(cards, tmp))
			i--;
		else
			cards.push_back(tmp);
	}

	cards.sort();
	return cards;
}