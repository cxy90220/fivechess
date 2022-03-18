#include "Chessboard.h"
#include "iostream"

Chessboard::Chessboard()
{
    for (int i = 1; i < ROW-1; i++ )
        for (int j = 1; j < COL-1; j++ )
            symbol[i][j] = "╋ ";
    for (int j = 1; j < COL-1; j++ )
    {
        symbol[0][j] = "┳ ";
        symbol[ROW-1][j] = "┻ ";
    }
    for (int i = 1; i < ROW-1; i++ )
    {
        symbol[i][0] = "┣ ";
        symbol[i][COL-1] = "┫ ";
    }
    symbol[0][0] = "┏ ";
    symbol[0][COL-1] = "┓ ";
    symbol[ROW-1][0] = "┗ ";
    symbol[ROW-1][COL-1] = "┛ ";
}

void Chessboard::show()
{
    system("cls");
    for (int i = 0; i < ROW; i++)
    {
        if (15 - i > 9 )
            cout << 15 - i;
        else
            cout << " " << 15 - i;
        for (int j = 0; j < COL; j++)
            cout << symbol[i][j];
        cout << endl;
    }
    cout << "  ";
    for (int i = 0; i < ROW; i++)
    {
        char rowname = 'A';
        cout << char(rowname + i)<< " ";
    }
    cout << endl;
}

