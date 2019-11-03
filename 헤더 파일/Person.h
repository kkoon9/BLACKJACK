#ifndef PERSON_DATA_H 
#define PERSON_DATA_H

#include <vector>
#include <string>
using namespace std;

typedef struct Person {
	int cardSum = 0;
	bool alive = true;
	int mode = 1; // 0 : stay, 1 : hit, 2 : double down, 3 : surrender, 4 : split
	int EleCnt = 0;
	bool black = false;
	bool split = false;
	bool bust = false;
	bool evenMoney = false;
	bool insurance = false;
	vector<int> cardNum;
	vector<int> Kindvec;
	string cardKind;
	string strNum;
	string cardLine1 = "";
	string cardLine2 = "";
	string cardLine3 = "";
	string cardLine4 = "";
	string cardLine5 = "";
	string cardLine6 = "";
	string cardLine7 = "";
} PERSON_DATA;
#endif
