//
// Created by ja on 21.03.2020.
//
#include "MSBoardTextView.h"
using namespace std;
MSBoardTextView::MSBoardTextView(MinesweeperBoard &x) : board (x)
{
    height=x.getBoardHeight();
    width=x.getBoardWidth();
}
void MSBoardTextView::display() const
{
    cout<<endl<<"+";
    for(int col=0; col < width; col++)
    {
        cout<<"|"<<col<<'|';
    }

    cout<<endl;
    for(int row=0; row < height; row++)
    {   cout<<row;
        for(int col=0; col < width; col++)
        {
            cout<<'|';
            cout<<board.getFieldInfo(row,col);
            cout<<'|';
        }
        cout<<endl;
    }

}



