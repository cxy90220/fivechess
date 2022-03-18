#include <iostream>
#include "Player.h"
#include "Judge.h"

void Player::setChess(Chess &chess, Chessboard &board)
{
    Judge judge;
    cout << chess.chess_name[chess.type] << "的坐标：" << endl;
    char positon_y;
    int  positon_x;
    cin >> positon_y >> positon_x;
    y = positon_y - 'A';
    x = 15 - positon_x;
    while(cin.fail() || judge.inChessboard(x, y) == 0 || judge.empty(x, y, board) == 0)
    {
        system("cls");
        board.show();
        cout << "输入有误，再次输入" << chess.chess_name[chess.type] << "的坐标：" << endl;
        cin.clear();
        cin.sync();
        cin >> positon_y >> positon_x;
        y = positon_y - 'A';
        x = 15 - positon_x;
    }
    board.symbol[x][y] = chess.chess_symbol[chess.type + 2];
    if (chess.row >= 0 && chess.col >= 0)
        board.symbol[chess.row][chess.col] = chess.chess_symbol[chess.type];
    chess.row = x;
    chess.col = y;
}
