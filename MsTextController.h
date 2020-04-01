#ifndef UNTITLED1_MSTEXTCONTROLLER_H
#define UNTITLED1_MSTEXTCONTROLLER_H
#include"MinesweeperBoard.h"
#include"MSBoardTextView.h"


class MSTextController
{
    MinesweeperBoard board;
    MSBoardTextView view;
    int height;
    int width;
    int FlagCount;
    void Move_Communication() ;
    void Win()const;
public:
    MSTextController(MinesweeperBoard &x, MSBoardTextView &y);
    void play();

};


#endif //UNTITLED1_MSTEXTCONTROLLER_H
