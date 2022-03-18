#include <iostream>
#include "Game.h"
#include <string>
using namespace std;

int main()
{
    system("chcp 65001 > nul");
    cout << "输入游戏的模式(1,2,3,4)" << endl;
    cout << "1.人人对战" << endl;
    cout << "2.人机对战(玩家先手)" << endl;
    cout << "3.人机对战(电脑先手)" << endl;
    cout << "4.退出" << endl;
    int mode;
    cin >> mode;
    while (cin.fail() || mode > 4 || mode < 0) {
        system("cls");
        cin.clear();
        cin.sync();
        cout << "输入有误，再次输入游戏的模式(1,2,3,4)" << endl;
        cout << "1.人人对战" << endl;
        cout << "2.人机对战(玩家先手)" << endl;
        cout << "3.人机对战(电脑先手)" << endl;
        cout << "4.退出" << endl;
        cin >> mode;
    }
    Game game;
    switch (mode) {
        case 1:
            game.mode1();
            break;
        case 2:
            game.mode2();
            break;
        case 3:
            game.mode3();
            break;
        case 4:
            break;
    }
}
