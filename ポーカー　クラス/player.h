#pragma once
using namespace std;

class Player{
public:
	int hundNo[5];//プレイヤーの手札の数字
	int hundMark[5];//プレイヤーの手札のマーク

	Player();

	void choose();
};

