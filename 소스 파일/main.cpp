#include <iostream>
#include <locale.h>
#include <stddef.h>
#include <Windows.h>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;
#include "Casino.h"
/********
** 함수
** 1. 카드 출력 : CardPrint
** 2. HIT / STAY  : HitandStay
** 3. 스플릿 : Split
** 4. Black Jack 출력 : BlackJack, PrintBlackJack
** 5. 버스트 : IsBust
** 6. Even Money : EvenMoney
** 7. HIT / STAY / DOUBLE DOWN / SURRENDER: Ask
** 8. 점수 계산 : GetScore
** 9. 더블 다운 : Doubledown
** 10. 초기 플레이어 당 2장씩 뽑는 함수 : Initial
** 11. 딜러 히든 카드 확인 : DealerHidden

** 구조체
** struct Person
** 카드 수 : cardNum
** 카드 합 : cardSum
** 가지고 있는 카드 문양 및 숫자 : card
** 생존 : alive
** HIT(1) / STAY(0) : mode
** ace 여부 : ACE
** ace 1 and 11 : EleCnt
** 블랙잭 여부 : black
*******************/

int main() {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	system("mode con: cols=80 lines=80");
	Initial();
	for (int i = 0; i < PLAY; i++) {
		Print();
		if (player[i].bust) continue;
		if (player[i].black) continue;
		cout << i + 1 << "조님 선택하세요, stay(0) hit(1) double down(2) surrendar(3) split(4) : ";
		Ask(player[i]);
		switch (player[i].mode) {
		case 1: // hit
			HitandStay(player[i]);
			MakePrint(player[i]);
			i -= 1;
			break;
		case 2:
			HitandStay(player[i]);
			break;
		case 0:
		case 3:
			break;
		case 4:
			Split(i);
			i -= 1;
		default:
			break;
		}
	}
	DealerInit();
	Print();
	while (dealer.cardSum < 17) {
		HitandStay(dealer);
		MakePrint(dealer);
		Print();
		system("pause");
	}
	cout << "딜러의 카드 합은  : " << dealer.cardSum << "입니다\n";
}
