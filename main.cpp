
using namespace std;

#include <iostream>
#include <cstdlib>
#include <ctime>
#include "MinesweeperBoard.h"
#include "MSBoardTextView.h"
#include "Array2D.h"
#include "MSTextController.h"
int main() {
    srand(time(NULL));
    MinesweeperBoard x(10, 10, HARD);
    //x.Debug_Display();
    cout << x.getMineCount() << " ";
    //x.toggleFlag(3,4);
    //x.revealField(1,1);
    //cout<<" "<<x.getMineCount()<<" ";
    //cout<<x.countMines(1,1);
    MSBoardTextView view(x);
   /*view.display();
    x.revealField(3, 4);
    x.revealField(1, 2);
    view.display();
    x.hasFlag(0, 0);
    x.hasFlag(5, 10);
    x.hasFlag(10000, 10000);
    x.revealField(0, 0);
    x.revealField(5, 10);
    x.revealField(10000, 10000);
    x.getFieldInfo(0,0);
    x.getFieldInfo(5,10);
    x.getFieldInfo(10000,10000);
    x.countMines(0,0);
    x.countMines(5,10);
    x.countMines(10000,10000);
    x.toggleFlag(0,0);
    x.toggleFlag(5,10);
    x.toggleFlag(10000,10000);
    x.isRevealed(0,0);
    x.isRevealed(5,10);
    x.isRevealed(10000,10000);
    */
   MSTextController ctrl(x,view);
   ctrl.play();
}