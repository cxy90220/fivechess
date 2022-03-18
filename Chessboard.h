#ifndef FIVECHESS_CHESSBOARD_H
#define FIVECHESS_CHESSBOARD_H

#include <string>
#define ROW 15
#define COL 15
using namespace std;

class Chessboard
{
public:
    string symbol[ROW][COL];
    Chessboard();
    void show();
    const string chessboard_symbol[9] = {"╋ ", "┳ ", "┻ ", "┣ ", "┫ ", "┏ ", "┓ ", "┗ ", "┛ "};
    friend class Player;
};

#endif //FIVECHESS_CHESSBOARD_H
