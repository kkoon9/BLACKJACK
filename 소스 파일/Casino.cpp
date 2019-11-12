#include <Windows.h>
using namespace std;
#include "Casino.h"

bool totCard[CARD * KIND]; // 전체 카드뭉치
PERSON_DATA dealer;
PERSON_DATA player[PLAY * 4];

void Initial() {
	for (int cnt = 0; cnt < 2; cnt++) {
		for (int i = 0; i < PLAY; i++) {
			HitandStay(player[i]);
			MakePrint(player[i]);
		}
		HitandStay(dealer);
		if (cnt == 1) {
			dealer.cardKind = " ?";
			dealer.strNum = " ?";
		}
		MakePrint(dealer);

	}
	for (int i = 0; i < PLAY; i++) {
		if (IsBlackJack(player[i])) {
			player[i].black = true;
		}
		if (player[i].black && dealer.cardNum[0] == 1)
			player[i].evenMoney = true;

	}
	Print();

	system("pause");
	if (dealer.cardNum[0] == 1) {
		Insurance();
	}
	else if (dealer.cardNum[0] >= 10) {
		if (DealerHidden()) {
			Sleep(1000);
			DealerInit();
			Print();
			system("pause");
		}
	}
}
