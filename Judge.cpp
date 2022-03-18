#include "Judge.h"
#include <algorithm>

bool Judge::inChessboard(int x, int y)
{
    if(x < ROW && x >= 0 && y < COL && y >= 0)
        return true;
    else
        return false;
}

bool Judge::empty(int x, int y, Chessboard board)
{
    bool flag = 1;
    Chess chess;
    for (int i = 0; i < 4;i++)
    {
        if (board.symbol[x][y].compare(chess.chess_symbol[i]) == 0)
            flag = 0;
    }
    if(flag == 1)
        return true;
    else
        return false;
}

int Judge::length(Chess chess, Chessboard board)
{
    int len[36];
    {for(int direction = 0;direction < 4;direction++) {
            int x, y;
            int num = 0;
            for (int i = -4; i < 5; i++)
            {
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
                if(inChessboard(x, y) && (board.symbol[x][y].compare(chess.chess_symbol[chess.type]) == 0 || i == 0))
                    num++;
                else
                    num = 0;
                len[direction*9 + i + 4] = num;
            }
        }
    }
    int max = *max_element(len, len + 36);
    index = max_element(len, len + 36) - len;
    if (max > 2)
        for (int i = 0; i < 36; i++)
            if (i != index && max == len[i])
            {
                two = 1;
                break;
            }
    return max;
}

bool Judge::win(Chess chess, Chessboard board)
{
    if (length(chess, board) == 5)
        return true;
    else
        return false;
}

bool Judge::equal(Chessboard board)
{
    for (int i = 0; i < ROW; i++ )
        for (int j = 0; j < COL; j++ )
            if (empty(i ,j, board))
                return false;
    return true;
}

bool Judge::ban(Chess chess, Chessboard board)
{
    if (length(chess, board) > 5 || two == 1)
        return true;
    else
        return false;
}