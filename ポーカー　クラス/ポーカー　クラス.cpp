#include <iostream>
#include"dealer.h"
#include"deck.h"
#include"player.h"
#include<time.h>
using namespace std;

int main()
{
    srand(time(NULL));

    Player* num1 = new Player;
    Player* num2 = new Player;

    deck de1;
    dealer dealer;

    //手札入れ替えなどに使う
    int loop1 = 0;
    int loop2 = 0;

    //手札入れ替えなどに使う
    bool draw = false;
    int drawNo = 0;
    int drawMark = 0;

    //手札入れ替えなどに使う
    int changeHund[5] = { 0 };

    //結果を調べるときに使う
    int result1;
    int result2;

    //プレイヤー1に最初の手札配布
    while (true) {
        bool draw = false;
        int drawNo = 0;
        int drawMark = 0;

        drawNo = rand() % 13 + 1;
        drawMark = rand() % 4 + 1;

        draw = de1.Check(drawNo,drawMark);

        if (draw == true) {
            num1->hundNo[loop1] = drawNo;
            num1->hundMark[loop1] = drawMark;

            ++loop1;
        }

        if (loop1 == 5) {
            break;
        }
    }

    //プレイヤー２に最初の手札を配布
    while (true) {
        draw = false;
        drawNo = 0;
        drawMark = 0;

        drawNo = rand() % 13 + 1;
        drawMark = rand() % 4 + 1;

        draw = de1.Check(drawNo, drawMark);

        if (draw == true) {
            num2->hundNo[loop2] = drawNo;
            num2->hundMark[loop2] = drawMark;

            ++loop2;
        }

        if (loop2 == 5) {
            break;
        }
    }

    cout << "あなたの今の手札は" << endl;

    for (int i = 0; i < 5; ++i) {
        switch (num1->hundMark[i])
        {
        case 1:
            cout << "ダイヤの"; break;
        case 2:
            cout << "ハートの"; break;
        case 3:
            cout << "スペードの"; break;
        case 4:
            cout << "クラブの"; break;
        }
        cout << num1->hundNo[i];
    }
    cout << "です" << endl;

    for (int i = 0; i < 5; ++i) {
        cout << i + 1<< "枚目を入れ替えますか？ 0:いいえ　1:はい" << endl;
        cin >> changeHund[i];
    }

    for (int i = 0; i < 5; ++i) {
        draw = false;
        drawNo = 0;
        drawMark = 0;

        while (true) {
            if (changeHund[i] == 1) {
                drawNo = rand() % 13 + 1;
                drawMark = rand() % 4 + 1;

                draw = de1.Check(drawNo, drawMark);

                if (draw == true) {
                    num1->hundNo[i] = drawNo;
                    num1->hundMark[i] = drawMark;

                    break;
                }
            }
            else {
                break;
            }
        }
    }

    cout << "あなたの今の手札は" << endl;

    for (int i = 0; i < 5; ++i) {
        switch (num1->hundMark[i])
        {
        case 1:
            cout << "ダイヤの"; break;
        case 2:
            cout << "ハートの"; break;
        case 3:
            cout << "スペードの"; break;
        case 4:
            cout << "クラブの"; break;
        }
        cout << num1->hundNo[i];
    }
    cout << "です" << endl;

    cout << "相手の今の手札は" << endl;

    for (int i = 0; i < 5; ++i) {
        switch (num2->hundMark[i])
        {
        case 1:
            cout << "ダイヤの"; break;
        case 2:
            cout << "ハートの"; break;
        case 3:
            cout << "スペードの"; break;
        case 4:
            cout << "クラブの"; break;
        }
        cout << num2->hundNo[i];
    }
    cout << "です" << endl;
    
    cout << "貴方の手役は";
    result1 = dealer.judgement(num1->hundNo[0], num1->hundNo[1], num1->hundNo[2], num1->hundNo[3], num1->hundNo[4], num1->hundMark[0], num1->hundMark[1], num1->hundMark[2], num1->hundMark[3], num1->hundMark[4]);
    cout << "でした" << endl;

    cout << "相手の手役は";
    result2 = dealer.judgement(num2->hundNo[0], num2->hundNo[1], num2->hundNo[2], num2->hundNo[3], num2->hundNo[4], num2->hundMark[0], num2->hundMark[1], num2->hundMark[2], num2->hundMark[3], num2->hundMark[4]);
    cout << "でした" << endl;

    if (result1 > result2) {
        cout << "win" << endl;
    }
    else if (result2 > result1) {
        cout << "lose" << endl;
    }
    else {
        cout << "draw" << endl;
    }

    delete num1;
    delete num2;
}