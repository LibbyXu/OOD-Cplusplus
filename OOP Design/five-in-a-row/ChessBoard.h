#pragma once
#include <iostream>
#define ROW 15
#define COL 15
using namespace std;

class ChessBoard//棋盘类
{
public:    
    char m_cSquare[ROW][COL];
    ChessBoard();
    void show();
};

ChessBoard::ChessBoard()
{
    for (int i = 1; i < ROW - 1; i++)
        for (int j = 1; j < COL - 1; j++)
            m_cSquare[i][j] = ' ';
    for (int j = 0; j < COL; j++)
        m_cSquare[0][j] = m_cSquare[ROW - 1][j] = '-';
    for (int i = 1; i < ROW; i++)
        m_cSquare[i][0] = m_cSquare[i][COL - 1] = '|';
}

void ChessBoard::show()
{
    system("cls");
    for (int i = 0; i < ROW; i++)
    {
        for (int j = 0; j < COL; j++)
            cout << m_cSquare[i][j] << ' ';//这里的“ <<' ' ”很重要，这样才能使屏幕上ROW*COL输出为方形
        cout << endl;
    }
}