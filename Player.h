#ifndef FIVECHESS_PLAYER_H
#define FIVECHESS_PLAYER_H

#include "Chessboard.h"
#include "Chess.h"

class Player
{
public:
    int x;
    int y;
    void setChess(Chess &chess, Chessboard &board);
};

#endif //FIVECHESS_PLAYER_H
