#include "PC.h"
#include "Player.h"
#include "Judge.h"
#include<ctime>

void PC::way1(Chessboard board, Chess chess, int len, int index)
{
    Judge judge;
    int direction = index / 9;
    int i = index % 9 - 3;
    switch (direction)
    {
        case 0:
            x = chess.row;
            y = chess.col + i;
            break;
        case 1:
            x = chess.row + i;
            y = chess.col;
            break;
        case 2:
            x = chess.row + i;
            y = chess.col + i;
            break;
        case 3:
            x = chess.row + i;
            y = chess.col - i;
            break;
    }
    if(judge.inChessboard(x, y) == 0 || judge.empty(x, y, board) == 0)
    {
        i = i - len -1;
        switch (direction)
        {
            case 0:
                x = chess.row;
                y = chess.col + i;
                break;
            case 1:
                x = chess.row + i;
                y = chess.col;
                break;
            case 2:
                x = chess.row + i;
                y = chess.col + i;
                break;
            case 3:
                x = chess.row + i;
                y = chess.col - i;
                break;
        }
    }
}

void PC::way2(Chessboard board, Chess chess)
{
    Judge judge;
    int len_pc, index_pc;
    len_pc = judge.length(chess, board);
    if (len_pc == 1)
    {
        int strux[8] = {1, 1, 1, 0, -1, -1, -1, 0};
        int struy[8] = {1, 0, -1, -1, -1, 0, 1, 1};
        for (int i = 0; i < 8; i++)
        {
            x = chess.row + strux[i];
            y = chess.col + struy[i];
            if (judge.inChessboard(x, y) && judge.empty(x, y, board))
                break;
        }
    }
    else if (len_pc > 1)
    {
        index_pc = judge.index;
        int direction = index_pc / 9;
        int i = index_pc % 9 - 3;
        switch (direction)
        {
            case 0:
                x = chess.row;
                y = chess.col + i;
                break;
            case 1:
                x = chess.row + i;
                y = chess.col;
                break;
            case 2:
                x = chess.row + i;
                y = chess.col + i;
                break;
            case 3:
                x = chess.row + i;
                y = chess.col - i;
                break;
        }
        if(judge.inChessboard(x, y) == 0 || judge.empty(x, y, board) == 0)
        {
            i = i - len_pc -1;
            switch (direction)
            {
                case 0:
                    x = chess.row;
                    y = chess.col + i;
                    break;
                case 1:
                    x = chess.row + i;
                    y = chess.col;
                    break;
                case 2:
                    x = chess.row + i;
                    y = chess.col + i;
                    break;
                case 3:
                    x = chess.row + i;
                    y = chess.col - i;
                    break;
            }
        }
    }
    else
    {
        x = (rand() % (ROW-5)) + 3;
        y = (rand() % (COL-5)) + 3;
    }
}

void PC::setChess(Chess &chess, Chessboard &board, Chess opp)
{
    clock_t start,finish;
    start = clock();
    Judge judge;
    int len_opp, index_opp;
    len_opp = judge.length(opp, board);
    if (len_opp > 2)
    {
        index_opp = judge.index;
        way1(board, opp, len_opp, index_opp);
    }
    if (judge.inChessboard(x, y) == 0 || judge.empty(x, y, board) == 0)
        way2(board, chess);
    if (judge.inChessboard(x, y) == 0 || judge.empty(x, y, board) == 0)
    {
        x = (rand() % (ROW-5)) + 3;
        y = (rand() % (COL-5)) + 3;
    }
    while (judge.empty(x, y, board) == 0)
    {
        x = (rand() % (ROW+1));
        y = (rand() % (COL+1));
        finish = clock();
        time = (finish - start) / CLOCKS_PER_SEC;
        if (time > 15)
            break;
    }
    if (time < 16)
    {
        board.symbol[x][y] = chess.chess_symbol[chess.type + 2];
        if (chess.row >= 0 && chess.col >= 0)
            board.symbol[chess.row][chess.col] = chess.chess_symbol[chess.type];
        chess.row = x;
        chess.col = y;
    }
}
