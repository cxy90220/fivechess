#ifndef FIVECHESS_JUDGE_H
#define FIVECHESS_JUDGE_H

#include "Chessboard.h"
#include "Chess.h"
#define ROW 15
#define COL 15

class Judge
{
public:
    int index;
    int two = 0;
    bool inChessboard(int x,int y);
    bool empty(int x,int y,  Chessboard board);
    int length(Chess chess, Chessboard board);
    bool win(Chess chess, Chessboard board);
    bool equal(Chessboard board);
    bool ban(Chess chess, Chessboard board);
};

#endif //FIVECHESS_JUDGE_H
