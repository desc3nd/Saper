#include "MsTextController.h"
#include "MSBoardTextView.h"
#include "MinesweeperBoard.h"
#include <string>
#include <cstdlib>
using namespace std;
MSTextController::MSTextController(MinesweeperBoard &x, MSBoardTextView &y) : view(board), board(x)
{
    height=board.getBoardHeight();
    width=board.getBoardWidth();
    FlagCount=board.getMineCount();
}

void MSTextController::play()
{

    cout<<" Witaj,zacznijmy rozgrywke!"<<endl;
   for(int i=0;i<width;i++)
       cout<< " - ";
    Move_Communication();

}

void MSTextController::Move_Communication()
{
    string PlayerMove;
    int ix,iy;
    view.display();
    cout<<"Co chcesz zrobic?"<<endl<<"1.Postaw flage "<<"(liczba flag:"<<FlagCount<<")."<<endl<<"2.Odkryj Pole"<<endl<<"3.Wyjdz"<<endl;

    cin>>PlayerMove;

    if(PlayerMove=="3"|| PlayerMove=="Wyjdz"|| PlayerMove=="wyjdz"|| PlayerMove=="3.Wyjdz"|| PlayerMove=="3.wyjdz")
        exit(1);

    if(PlayerMove=="1"|| PlayerMove=="Postaw flage" || PlayerMove=="postaw flage"|| PlayerMove=="1.Postaw flage"|| PlayerMove=="1.postaw flage")
    {

        cout<<"Podaj wspolrzedne:";
        cin>>ix>>iy;
        if(ix>=height || iy>=width || ix<0 || iy<0)
        {
            cout<<"Bledne wspolrzedne.Sprobuj ponownie.";
            Move_Communication();
        }
        if(board.isRevealed(ix,iy))
        {
            cout << "Pole jest odkryte! Wykonaj inny ruch. ";
            Move_Communication();
        }

        if(!board.hasFlag(ix,iy))
            FlagCount--;
        if(board.hasFlag(ix,iy))
            FlagCount++;
        board.toggleFlag(ix,iy);
        Win();
        Move_Communication();
    }
    if(PlayerMove=="2"|| PlayerMove=="Odkryj pole" || PlayerMove=="odkryj pole"|| PlayerMove=="2.Odkryj pole"|| PlayerMove=="2.odkryj pole")
    {
        cout<<"Podaj wspolrzedne:";
        cin>>ix>>iy;
        if(ix>=height || iy>=width || ix<0 || iy<0)
        {
            cout<<"Bledne wspolrzedne.Sprobuj ponownie.";
            Move_Communication();
        }
        if(board.isRevealed(ix,iy) || board.hasFlag(ix,iy))
        {
            cout << "Pole jest juz odkryte lub posiada flage! Wykonaj inny ruch.";
            Move_Communication();
        }

        else
        {
            cout << "Odkryto pole " << ix << ',' << iy;
            board.revealField(ix,iy);
            if(board.getFieldInfo(ix,iy)=='x') {
                cout <<endl<< "Ups... wyglada na to ze trafileś na mine." << endl << "Spróbuj ponownie";
                exit(1);

            }
            Win();
            Move_Communication();
        }
    }
    else
    {
        cout<<"Bledny wybor.Sprobuj ponownie";
        Move_Communication();
    }
}

void MSTextController::Win() const
{
    if(board.getGameState()==FINISHED_WIN)
    {
        cout<<endl<<"Wygrales!";
        exit(1);
    }
}
