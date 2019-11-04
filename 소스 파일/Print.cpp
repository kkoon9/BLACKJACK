#include <iostream>
#include <Windows.h>
using namespace std;

#include "Print.h"


void Print() {
	PrintDealer(dealer);
	for (int i = 0;i < PLAY;i++) {
		PrintPlayer(i);
	}
}

void PrintDealer(PERSON_DATA& person) {
	system("cls");
	cout << "딜러 ";
	if (person.bust) {
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
		cout << "BUST";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8);
	}
	NormalPrint(person);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
}

void PrintPlayer(int i) {
	if (i < PLAY) {
		cout << i + 1 << "조";
	}
	else {
		cout << (i % PLAY) + 1 << "조";
	}
	if (player[i].alive == false) {
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED);
		cout << " DIE";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8);
	}
	else if (player[i].black)
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
		cout << " BLACK JACK!";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	}
	if (player[i].bust)
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
		cout << " BUST";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8);
	}
	if (player[i].mode == 2) { // 더블다운일 때
		DoubleDownPrint(player[i]);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	}
	else {
		NormalPrint(player[i]);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		if (player[i].bust)
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	}
	if (player[i].split) {
		PrintPlayer(i + PLAY);
	}

}

void DoubleDownPrint(PERSON_DATA& Person) {
	cout << Person.cardLine1;
	DoubleDownEnd(Person, 0);
	cout << Person.cardLine2;
	DoubleDownEnd(Person, 1);
	cout << Person.cardLine3;
	DoubleDownEnd(Person, 2);
	cout << Person.cardLine4;
	DoubleDownEnd(Person, 3);
	cout << Person.cardLine5;
	DoubleDownEnd(Person, 4);
	cout << Person.cardLine6;
	DoubleDownEnd(Person, 5);
	cout << Person.cardLine7;
	DoubleDownEnd(Person, 6);
}

void DoubleDownEnd(PERSON_DATA& Person, int i) {
	if (Person.bust) {
		switch (i) {
		case 0:
			printf("┌──────────┐ \n");
			break;
		case 1:
			printf("    │ double   │ \n");
			break;
		case 2:
			printf("──┐ │");
			cout << Person.cardKind << Person.strNum;
			printf("      │ \n");
			break;
		case 3:
			printf("  │ └──────────┘ \n");
			break;
		case 4:
			printf("  │ \n");
			break;
		case 5:
			printf("  │ \n");
			break;
		case 6:
			printf("──┘ \n");
			break;
		}
	}
	else {
		switch (i) {
		case 0:
			printf("   ┌──────────┐\n");
			break;
		case 1:
			printf("  │ double   │\n");
			break;
		case 2:
			printf("──│");
			cout << Person.cardKind << Person.strNum;
			printf("      │ \n");
			break;
		case 3:
			printf("  ├──────────┘\n");
			break;
		case 4:
			printf("  │ \n");
			break;
		case 5:
			printf("  │ \n");
			break;
		case 6:
			printf("──┘ \n");
			break;
		}
	}
}

void MakePrint(PERSON_DATA& Person) {
	Person.cardLine1 += ("  ");
	Person.cardLine2 += ("    ");
	Person.cardLine3 += ("┌───");
	Person.cardLine4 += ("│ ");
	Person.cardLine4 += Person.cardKind;
	Person.cardLine5 += ("│ ");
	Person.cardLine5 += Person.strNum;
	Person.cardLine6 += ("│   ");
	Person.cardLine7 += ("└───");
}

void NormalPrint(PERSON_DATA& Person) {
	cout << Person.cardLine1;
	NormalEnd(0);
	cout << Person.cardLine2;
	NormalEnd(1);
	cout << Person.cardLine3;
	NormalEnd(2);
	cout << Person.cardLine4;
	NormalEnd(3);
	cout << Person.cardLine5;
	NormalEnd(4);
	cout << Person.cardLine6;
	NormalEnd(5);
	cout << Person.cardLine7;
	NormalEnd(6);
}

void NormalEnd(int i) {
	switch (i) {
	case 0:
		printf("\n");
		break;
	case 1:
		printf("\n");
		break;
	case 2:
		printf("───┐ ");
		printf("\n");
		break;
	case 3:
		printf("   │ \n");
		break;
	case 4:
		printf("   │ \n");
		break;
	case 5:
		printf("   │ \n");
		break;
	case 6:
		printf("───┘ \n");
		break;
	}
}
void PrintBlackJack() {
	for (int i = 1; i <= 5; i++) {
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), i);
		BlackJack();
		Sleep(300);
	}
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	Print();
}
void BlackJack() {
	cout << "------------------------------------------------------" << "\n";
	cout << "******     **           **      *******     **    **  " << "\n";
	cout << "**    **   **          ** **    **     **   **   **  " << "\n";
	cout << "**     **  **         **   **   **      **  **  **   " << "\n";
	cout << "**     **  **        **     **  **          ** **   " << "\n";
	cout << "*******    **        *********  **          ** *   " << "\n";
	cout << "**     **  **       **       ** **          ** **    " << "\n";
	cout << "**      ** **       **       ** **      **  **  **   " << "\n";
	cout << "**     **  *******  **       ** **     **   **   **   " << "\n";
	cout << "*******    *******  **       ** *******     **    **      " << "\n";
	cout << "-------------------------------------------------------" << "\n";
	cout << "----------------------------------------------" << "\n";
	cout << " ***********     **      *******     **    ** " << "\n";
	cout << "       **       ** **    **     **   **   ** " << "\n";
	cout << "       **      **   **   **      **  **  ** " << "\n";
	cout << "       **     **     **  **          ** ** " << "\n";
	cout << "      **      *********  **          ** *   " << "\n";
	cout << " **   **    **        ** **          ** ** " << "\n";
	cout << " **   **    **        ** **      **  **  ** " << "\n";
	cout << " **   **    **        ** **     **   **   ** " << "\n";
	cout << " ******    **         ** *******     **    **   " << "\n";
	cout << "-----------------------------------------------" << "\n";
}
