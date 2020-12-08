#include"deck.h"

deck::deck() {
	for (int i = 0; i < 4; ++i) {
		mark[i] = i + 1;
	}

	for (int i = 0; i < 13; ++i) {
		no[i] = i + 1;
	}

	for (int i = 0; i < 52; ++i) {
		CheckMark[i] = i + 1;
	}
}

bool deck::Check(int a, int b) {//カードがすでに出ているかチェックする
	 if (CheckMark[a * b] > 0) {
	 	 CheckMark[a * b] = 0;
		 return true;
	 }
}
