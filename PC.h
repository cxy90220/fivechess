#ifndef FIVECHESS_PC_H
#define FIVECHESS_PC_H

#include "Chessboard.h"
#include "Chess.h"
#define ROW 15
#define COL 15

class PC
{
public:
    int x = 7;
    int y = 7;
    int time = 0;
    void setChess(Chess &chess, Chessboard &board, Chess opp);
    void way1(Chessboard board, Chess chess, int len, int index);
    void way2(Chessboard board, Chess chess);
};

#endif //FIVECHESS_PC_H
