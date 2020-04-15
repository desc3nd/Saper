

#ifndef UNTITLED1_MSBOARDTEXTVIEW_H
#define UNTITLED1_MSBOARDTEXTVIEW_H
#include<iostream>

#include "MinesweeperBoard.h"

class MSBoardTextView
{
    MinesweeperBoard & board;
    int height;
    int width;
public:
    explicit MSBoardTextView(MinesweeperBoard &x);
    void display() const;


};


#endif //UNTITLED1_MSBOARDTEXTVIEW_H
