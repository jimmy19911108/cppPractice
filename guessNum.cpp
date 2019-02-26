#include <iostream>
#include <ctime>
#include <cmath>
#include <string>

using namespace std;

string setNumber() {

	string set_num;
	string temp;

	srand(time(0));
	set_num = (rand() % 10) + '0';

	for (int i = 0; i < 3; i++)
		while (true) {
			temp = (rand() % 10) + '0';

			if (set_num.find(temp) == string::npos) {
				set_num += temp;
				break;
			}
		}

	return set_num;
}

string inputNumber() {

	string input_num;
	
	while (true) {
		cout << "Guess the number: ";
		cin >> input_num;

		if (input_num.length() == 4)
			break;
		else
			cout << "\nIncorrect number\n\n";
	}

	return input_num;

}

bool judgment(string set_num, string input_num) {

	int a = 0;
	int b = 0;

	if (set_num.compare(input_num) == 0) {
		cout << "\nYou Win!!\n\n";
		return false;
	}
	else
	{
		for (int i = 0; i < 4; i++)
			for (int j = 0; j < 4; j++) {
				if (input_num[i] == set_num[j])
					if (i == j)
						a++;
					else
						b++;
			}

		cout << a << "A" << b << "B\n";
		a = 0;
		b = 0;
		return true;
	}
}

int main() {

	char play_again;
	string input_num;
	string set_num;
	bool judge_result;
	time_t timer;
	int counter;

	do {
		play_again = '0';
		counter = 0;
		judge_result = true;
		set_num = setNumber();
		timer = time(NULL);

		while (judge_result) {
			input_num = inputNumber();

			counter++;

			judge_result = judgment(set_num, input_num);
		}

		cout << time(NULL) - timer << " seconds\n\n";

		cout << counter << " moves\n\n";

		while (play_again != 'y' && play_again != 'n') {
			cout << "Want to play again¡H(y/n)";
			cin >> play_again;
		}

	} while (play_again == 'y');

	system("pause");
	return 0;
}