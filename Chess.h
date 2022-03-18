#ifndef FIVECHESS_CHESS_H
#define FIVECHESS_CHESS_H

#include <string>
#include <vector>
using namespace std;

class Chess
{
public:
    int row = -1;
    int col = -1;
    int type;
    void chess_set();
    const string chess_symbol[4] = {"○", "●", "△", "▲"};
    const string chess_name[2] = {"黑子", "白子"};
    friend class Player;
};

#endif //FIVECHESS_CHESS_H
