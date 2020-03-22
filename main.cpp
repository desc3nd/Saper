
using namespace std;

#include <iostream>
#include <cstdlib>
#include <ctime>
#include "MinesweeperBoard.h"
#include "MSBoardTextView.h"
int main()
{
    srand( time( NULL ) );
    MinesweeperBoard x(10,10,EASY);
    //x.Debug_Display();
    cout<<x.getMineCount()<<" ";
    //x.toggleFlag(3,4);
    //x.revealField(1,1);
    //cout<<" "<<x.getMineCount()<<" ";
    //cout<<x.countMines(1,1);
    MSBoardTextView view(x);
    view.display();
    x.revealField(3,4);
    x.revealField(1,2);
    view.display();
}