#include <Windows.h>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <locale.h>
#include <stddef.h>
using namespace std;

#include "Rule.h"

void Split(int group) {
	player[group].EleCnt /= 2;
	player[group + PLAY].cardNum.push_back(player[group].cardNum[1]);
	player[group + PLAY].Kindvec.push_back(player[group].Kindvec[1]);
	player[group].cardNum.pop_back();
	player[group].Kindvec.pop_back();
	player[group].cardSum = 0;
	GetScore(player[group], player[group].cardNum[0]);
	GetScore(player[group + PLAY], player[group + PLAY].cardNum[0]);
	player[group].cardLine1 = "";
	player[group].cardLine2 = "";
	player[group].cardLine3 = "";
	player[group].cardLine4 = "";
	player[group].cardLine5 = "";
	player[group].cardLine6 = "";
	player[group].cardLine7 = "";
	player[group].cardKind = CardKind(player[group].Kindvec[0]);
	MakePrint(player[group]);
	player[group + PLAY].strNum = PrintCardNum(player[group+PLAY].cardNum[0]);
	player[group + PLAY].cardKind = CardKind(player[group + PLAY].Kindvec[0]);
	MakePrint(player[group + PLAY]);

	while (player[group + PLAY].mode == 1) {
		Print();
		if (player[group + PLAY].bust) break;
		cout << group + 1 << "조님 스플릿 선택하세요, stay(0) hit(1) double down(2) surrendar(3) split(4) : ";
		Ask(player[group + PLAY]);
		switch (player[group + PLAY].mode) {
		case 1: // hit
			HitandStay(player[group + PLAY]);
			MakePrint(player[group + PLAY]);
			break;
		case 2: // double down
			HitandStay(player[group + PLAY]); 
			Print();
			break;
		case 4: // split
			Split(group + PLAY);
			break;
		default:
			break;
		}
	}
}

void GetScore(PERSON_DATA& person, int num) {
	if (person.EleCnt > 0 && person.cardSum + num > 21) {
		person.EleCnt--;
		person.cardSum -= 10;
	}
	if (num == 1) { // A이면
		person.EleCnt++;
		if (person.cardSum + 11 > 21) {
			num = 1;
			person.EleCnt--;
		}
		else {
			num = 11;
		}
	}
	else if (num >= 11) {
		num = 10;
	}
	person.cardSum += num;
}

void Insurance() {
	system("cls");
	bool input;
	cout << "딜러";
	NormalPrint(dealer);
	for (int group = 0; group < PLAY; group++) {
		if (player[group].evenMoney)
			cout << group + 1 << "조님, 이븐머니 하시겠습니까?";
		else
			cout << group + 1 << "조님, 인셔런스 하시겠습니까?";
		cin >> input;
		player[group].insurance = input;
	}
	if (IsBlackJack(dealer)) {
		DealerInit();
	}
	system("cls");
	cout << "딜러";
	NormalPrint(dealer);
	for (int group = 0; group < PLAY; group++) {
		if (player[group].evenMoney) {
			if (player[group].insurance) {
				if (IsBlackJack(dealer))
					cout << group + 1 << "조 이븐머니 성공";
				else {
					cout << group + 1 << "조 이븐머니 실패";
					player[group].alive = false;
				}
			}
		}
		else {
			if (player[group].insurance) {
				if (IsBlackJack(dealer))
					cout << group + 1 << "조 인셔런스 성공";
				else {
					cout << group + 1 << "조 인셔런스 실패";
				}
			}
		}
		cout << endl;
	}

	system("pause");
}

void HitandStay(PERSON_DATA& person) {
	srand((unsigned int)time(NULL));
	if (person.alive && person.mode != 0 && person.mode != 3) {
		int a = rand() % (CARD * KIND);
		while (totCard[a]) {
			a = rand() % (CARD * KIND);
		}
		totCard[a] = true;
		int k = a / CARD; // 카드 종류
		int n = (a % CARD) + 1; // 카드 숫자
		person.cardKind = CardKind(k);
		person.cardNum.push_back(n);
		person.Kindvec.push_back(k);
		person.strNum = PrintCardNum(n);
		GetScore(person, n);
		IsBust(person);
	}
}
