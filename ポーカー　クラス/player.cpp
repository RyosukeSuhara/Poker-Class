#include"player.h"
#include<time.h>
#include<iostream>

Player::Player() {
	for (int i = 0; i < 5; ++i) {
		hundNo[i] = 0;
		hundMark[i] = 0;
	}
}

/*
void Player::choose() {
	int a = 0;
	srand(time(NULL));

	for (int i = 0; i < 5; ++i) {//“ü‚ê‘Ö‚¦
		cout << i << "–‡–Ú‚ð“ü‚ê‘Ö‚¦‚Ü‚·‚©H0:yes 1:no" << endl;
		cin >> a;

		while (true) {
			if (a == 0) {
				int b = rand() % 52 + 1;

				int c = hund[i];

				//hund[i] = de.Check(b);
				if (c != b) {
					return;
				}
			}
			else {
				return;
			}
		}
	}
}
*/