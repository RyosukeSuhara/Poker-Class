#include"dealer.h"
#include"deck.h"
#include<time.h>
#include<iostream>
using namespace std;

/*
void dealer::Pass() {
	srand(time(NULL));

	for (int i = 0; i < 5; ++i) {
		while (chr.hund[i] == 0) {
			chr.hund[i] = de.Check(rand() % 52 + 1);
		}
	}
}
*/

int dealer::judgement(int N1, int N2, int N3, int N4, int N5,int M1,int M2,int M3,int M4,int M5) {
	int Num[5] = { N1,N2,N3,N4,N5 };
	int Mark[5] = { M1,M2,M3,M4,M5 };
	int z = 0;

	for (int i = 0; i < 3; ++i) {
		for (int j = 4; j > i; --j) {
			if (Num[j - 1] > Num[j]) {
				z = Num[j];
				Num[j] = Num[j - 1];
				Num[j - 1] = z;
			}
		}
	}
	if (Num[0] == 1 && Num[1] == 10 && Num[2] == 11 && Num[3] == 12 && Num[4] == 13 && Mark[0] == Mark[1] == Mark[2] == Mark[3] == Mark[4]) {
		cout << "���C�����X�g���[�g�t���b�V��";
		return 9;//���C�����X�g���[�g�t���b�V��
	}
	else if (Num[1] == Num[0] + 1 && Num[2] == Num[1] + 1 && Num[3] == Num[2] + 1 && Num[4] == Num[3] + 1 && Mark[0] == Mark[1] == Mark[2] == Mark[3] == Mark[4]) {
		cout << "�X�g���[�g�t���b�V��";
		return 8;//�X�g���[�g�t���b�V��
	}
	else if (Num[0] == Num[1] == Num[2] == Num[3] || Num[1] == Num[2] == Num[3] == Num[4]) {
		cout << "�t�H�[�J�[�h";
		return 7;//�S�J�[�h
	}
	else if ((Num[0] == Num[1] == Num[2] && Num[3] == Num[4]) || (Num[0] == Num[1] && Num[2] == Num[3] == Num[4])) {
		cout << "�t���n�E�X";
		return 6;//�t���n�E�X
	}
	else if (Mark[0] == Mark[1] == Mark[2] == Mark[3] == Mark[4]) {
		cout << "�t���b�V��";
		return 5;//�t���b�V��
	}
	else if (Num[1] == Num[0] + 1 && Num[2] == Num[1] + 1 && Num[3] == Num[2] + 1 && Num[4] == Num[3] + 1) {
		cout << "�X�g���[�g";
		return 4;//�X�g���[�g
	}
	else if (Num[0] == Num[1] == Num[2] || Num[1] == Num[2] == Num[3] || Num[2] == Num[3] == Num[4]) {
		cout << "�X���[�J�[�h";
		return 3;//�R�J�[�h
	}
	else if ((Num[0] == Num[1] && Num[2] == Num[3]) || (Num[0] == Num[1] && Num[3] == Num[4]) || (Num[1] == Num[2] && Num[3] == Num[4])) {
		cout << "�c�[�y�A";
		return 2;//�c�[�y�A
	}
	else if (Num[0] == Num[1] || Num[1] == Num[2] || Num[2] == Num[3] || Num[3] == Num[4]){
		cout << "�����y�A";
		return 1;//�����y�A
	}
	else {
		cout << "�n�C�J�[�h";
		return 0;//�n�C�J�[�h
	}



}