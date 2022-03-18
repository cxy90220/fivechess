#include <iostream>
#include "Game.h"
#include "Chessboard.h"
#include "Player.h"
#include "Judge.h"
#include "PC.h"
#include <string>
using namespace std;

void Game::mode1()
{
    Chessboard board;
    Chess black, white;
    Player player1, player2;
    Judge judge;
    string command;
    black.type = 0, white.type = 1;
    board.show();
    while(1)
    {
        player1.setChess(black, board);
        board.show();
        if (judge.win(black, board))
        {
            system("cls");
            board.show();
            cout << black.chess_name[black.type] << "胜利,输入任何值回车后退出" << endl;
            cin >> command;
            cin.clear();
            cin.sync();
            break;
        }
        if (judge.ban(black, board))
        {
            system("cls");
            board.show();
            cout << black.chess_name[black.type] << "禁手，失败,输入任何值回车后退出" << endl;
            cin >> command;
            cin.clear();
            cin.sync();
            break;
        }
        player2.setChess(white, board);
        board.show();
        if (judge.win(white, board))
        {
            system("cls");
            board.show();
            cout << white.chess_name[white.type] << "胜利,输入任何值回车后退出" << endl;
            cin >> command;
            cin.clear();
            cin.sync();
            break;
        }
        if (judge.equal(board))
        {
            system("cls");
            board.show();
            cout << "和棋,输入任何值回车后退出" << endl;
            cin >> command;
            cin.clear();
            cin.sync();
            break;
        }
    }
}

void Game::mode2()
{
    Chessboard board;
    Chess black, white;
    Player player1;
    PC pc;
    Judge judge;
    string command;
    black.type = 0, white.type = 1;
    board.show();
    while(1)
    {
        player1.setChess(black, board);
        board.show();
        if (judge.win(black, board))
        {
            system("cls");
            board.show();
            cout << black.chess_name[black.type] << "胜利,输入任何值回车后退出" << endl;
            cin >> command;
            cin.clear();
            cin.sync();
            break;
        }
        if (judge.ban(black, board))
        {
            system("cls");
            board.show();
            cout << black.chess_name[black.type] << "禁手，失败,输入任何值回车后退出" << endl;
            cin >> command;
            cin.clear();
            cin.sync();
            break;
        }
        pc.setChess(white, board, black);
        board.show();
        if (judge.win(white, board))
        {
            system("cls");
            board.show();
            cout << white.chess_name[white.type] << "胜利,输入任何值回车后退出" << endl;
            cin >> command;
            cin.clear();
            cin.sync();
            break;
        }
        if (judge.equal(board))
        {
            system("cls");
            board.show();
            cout << "和棋,输入任何值回车后退出" << endl;
            cin >> command;
            cin.clear();
            cin.sync();
            break;
        }
        if (pc.time > 15)
        {
            system("cls");
            board.show();
            cout << white.chess_name[black.type] << "胜利,输入任何值回车后退出" << endl;
            cin >> command;
            cin.clear();
            cin.sync();
            break;
        }
    }
}

void Game::mode3()
{
    Chessboard board;
    Chess black, white;
    Player player2;
    PC pc;
    Judge judge;
    string command;
    black.type = 0, white.type = 1;
    board.show();
    while(1)
    {
        pc.setChess(black, board, white);
        board.show();
        if (judge.win(black, board))
        {
            system("cls");
            board.show();
            cout << black.chess_name[black.type] << "胜利,输入任何值回车后退出" << endl;
            cin >> command;
            cin.clear();
            cin.sync();
            break;
        }
        if (pc.time > 15)
        {
            system("cls");
            board.show();
            cout << white.chess_name[white.type] << "胜利,输入任何值回车后退出" << endl;
            cin >> command;
            cin.clear();
            cin.sync();
            break;
        }
        if (judge.ban(black, board))
        {
            system("cls");
            board.show();
            cout << black.chess_name[black.type] << "禁手，失败,输入任何值回车后退出" << endl;
            cin >> command;
            cin.clear();
            cin.sync();
            break;
        }
        player2.setChess(white, board);
        board.show();
        if (judge.win(white, board))
        {
            system("cls");
            board.show();
            cout << white.chess_name[white.type] << "胜利,输入任何值回车后退出" << endl;
            cin >> command;
            cin.clear();
            cin.sync();
            break;
        }
        if (judge.equal(board))
        {
            system("cls");
            board.show();
            cout << "和棋,输入任何值回车后退出" << endl;
            cin >> command;
            cin.clear();
            cin.sync();
            break;
        }
    }
}
