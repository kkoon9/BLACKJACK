#include <cstdlib>
#include <ctime>
#include <locale.h>
#include <stddef.h>
#include <iostream>
using namespace std;

#include "Data.h"

string CardKind(int i) {
	string kind;
	switch (i) {
	case 0:
		kind = "◆";
		break;
	case 1:
		kind = "♥";
		break;
	case 2:
		kind = "♠";
		break;
	case 3:
		kind = "♣";
		break;
	}
	return kind;
}
void Ask(PERSON_DATA& person) {
	int input;
	cin >> input;
	person.mode = input;
	if (input == 3)
		person.alive = false;
	else if (input == 4)
		person.split = true;
}
void IsBust(PERSON_DATA& person) {
	int sum = person.cardSum;
	if (sum > 21) {
		person.bust = true;
	}
}
string PrintCardNum(int num) {
	string str;
	if (num == 1) {
		str = "A ";
	}
	else if (num == 11) {
		str = "J ";
	}
	else if (num == 12) {
		str = "Q ";
	}
	else if (num == 13) {
		str = "K ";
	}
	else if (num == 10) {
		str = "10";
	}
	else {
		str = to_string(num);
		str += " ";
	}
	return str;
}
bool IsBlackJack(PERSON_DATA& person) {
	int first = person.cardNum[0];
	int second = person.cardNum[1];
	if (first >= 10) {
		first = 10;
	}
	else if (first == 1)
		first = 11;
	if (second >= 10) {
		second = 10;
	}
	else if (second == 1)
		second = 11;
	return (first + second) == 21;
}