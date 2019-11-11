#include "Dealer.h"

bool DealerHidden() {
	if (dealer.cardSum == 21) {
		return true;
	}
	return false;
}
void DealerInit() {
	dealer.cardLine1 = "";
	dealer.cardLine2 = "";
	dealer.cardLine3 = "";
	dealer.cardLine4 = "";
	dealer.cardLine5 = "";
	dealer.cardLine6 = "";
	dealer.cardLine7 = "";

	for (int i = 0; i < 2; i++) {
		dealer.strNum = PrintCardNum(dealer.cardNum[i]);
		dealer.cardKind = CardKind(dealer.Kindvec[i]);
		MakePrint(dealer);
	}
}
