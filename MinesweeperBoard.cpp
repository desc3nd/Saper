//
// Created by ja on 09.03.2020.
//
using namespace std;
#include<iostream>
#include "MinesweeperBoard.h"

#include <cstdlib>



void MinesweeperBoard::BombOnBoard(float x)
{
    float my_percentage=width*height*(x);
    for(bomb=0;bomb<my_percentage;)
    {
        int row=rand()%width;
        int col=rand()%height;
        if(board[row][col].hasMine==0)
        {
            board[row][col].hasMine = true;
            bomb++;

        }
    }
}
MinesweeperBoard::MinesweeperBoard(int width, int height, GameMode mode)
{
   this->width=height;
   this->height=width;
   this->mode=mode;
   this->bomb=bomb;
   this->status_gry=RUNNING;
   this->mines_left=bomb;
   this->number_of_player_action=0;
    //zerowanie mapy
    for(int row=0;row<height;row++)
    {
        for(int col=0;col<width;col++)
        {
            board[row][col].hasFlay=0;
            board[row][col].hasMine=0;
            board[row][col].isRevealed=0;
        }
    }
    float my_percentage=0; //zmienna pomocnicza
    //tryby gry
    if(mode==DEBUG)
    {
        for(int row=0;row<height;row++)
        {
            for(int col=0;col<width;col++)
            {
                if(row==col)
                    board[row][col].hasMine=true;
                if(row==0)
                    board[row][col].hasMine=true;
                if(col==0 && row%2==0)
                    board[row][col].hasMine=true;
            }
        }
    }
    if (mode==EASY)
    {
        BombOnBoard(0.1);
    }
    if (mode==NORMAL)
    {
       BombOnBoard(0.2);
    }
    if (mode==HARD)
    {
       BombOnBoard(0.3);
    }
}

//funkcje
   void  MinesweeperBoard::Debug_Display() const
{
    for(int row=0;row<height;row++)
    {
        for(int col=0;col<width;col++)
        {
            cout<<"[";
            if(board[row][col].hasMine)
            {
                cout<<'M';
            }
            else cout<<".";
            if(board[row][col].isRevealed)
            {
                cout << 'o';
            }
            else cout<<'.';

            if(board[row][col].hasFlay)
            {
                cout << 'f';
            }
            else cout<<'.';
            cout<<"]";
        }
        cout<<endl;
    }
}

int MinesweeperBoard::getBoardHeight() const
{
    return height;
}

int MinesweeperBoard::getBoardWidth() const
{
    return width;
}

int MinesweeperBoard::getMineCount() const
{
    return bomb;    
}
int MinesweeperBoard::countMines(int x, int y) const
{
    if(!board[x][y].isRevealed)
        return -1;
    if(x>height || y>width || x<0 || y<0)
        return -1;
    else
    {
        int number_of_bombs = 0;
        if(x+1<=height && board[x+1][y].hasMine)
            number_of_bombs++;
        if( x-1>=height && board[x-1][y].hasMine )
            number_of_bombs++;
        if(y+1<=width && board[x][y+1].hasMine)
            number_of_bombs++;
        if(y-1>=width && board[x][y-1].hasMine )
            number_of_bombs++;
        if(x+1<=height && y+1<=width && board[x+1][y+1].hasMine)
            number_of_bombs++;
        if(x-1>=height && y-1>=width && board[x-1][y-1].hasMine)
            number_of_bombs++;
        if( x+1<=height && y-1>=width && board[x+1][y-1].hasMine)
            number_of_bombs++;
        if(x-1>=height && y+1<=width && board[x-1][y+1].hasMine)
            number_of_bombs++;
        return number_of_bombs;
    }
    }


bool MinesweeperBoard::hasFlag(int x, int y) const
{
    if(board[x][y].hasFlay)
        return true;
    if(x>width || y>height || x<0 || y<0)
        return false;
    if(!board[x][y].hasFlay)
        return false;
    if(board[x][y].isRevealed)
        return false;

        return false;
}

void MinesweeperBoard::toggleFlag(int x, int y)
{
    if(board[x][y].isRevealed)
        return;
    if(x>height || y>width || x<0 || y<0)
        return;
    if(status_gry==FINISHED_LOSS || status_gry==FINISHED_WIN)
        return;
    if(!board[x][y].hasFlay)
    {
        board[x][y].hasFlay=true;
    }
    if(!board[x][y].hasFlay && board[x][y].hasMine)
    {
        board[x][y].hasFlay=true;
        mines_left--;
    }
}

void MinesweeperBoard::revealField(int x, int y)
{
    number_of_player_action++;
    if(x>width || y>height || x<0 || y<0)
        return;
    if(board[x][y].isRevealed)
        return;
    if(status_gry!=RUNNING)
        return;
    if(board[x][y].hasFlay)
        return;

    if(!board[x][y].hasMine && !board[x][y].isRevealed)
        board[x][y].isRevealed=true;
    if(board[x][y].hasMine && !board[x][y].isRevealed)
    {
        if(number_of_player_action==1)
        {
            board[x][y].hasMine=false;
                int a = rand() % height;
                int b = rand() % width;
            while(board[a][b].hasMine)
            {
                a=rand()%height;
                b=rand()%width;
            }
            board[a][b].hasMine=true;
        }
        else
        {
            board[x][y].isRevealed=true;
            status_gry=FINISHED_LOSS;
        }


    }
}

bool MinesweeperBoard::isRevealed(int x, int y) const
{
    if (board[x][y].isRevealed)
        return true;

        return false;
}

GameState MinesweeperBoard::getGameState() const
{
    if (status_gry == FINISHED_LOSS)
        return FINISHED_LOSS;
    if (status_gry == RUNNING && mines_left== 0)
        return FINISHED_WIN;
    return RUNNING;
}

char MinesweeperBoard::getFieldInfo(int x, int y) const
{
    int mines_around=countMines(x, y);
    if(x>height || y>width || x<0 || y<0)
        return '#';
    if(!board[x][y].isRevealed && board[x][y].hasFlay)
        return 'F';
    if(!board[x][y].isRevealed && !board[x][y].hasFlay)
        return '_';
    if(board[x][y].isRevealed && board[x][y].hasMine)
        return 'x';
    if(board[x][y].isRevealed && mines_around==0)
        return ' ';
    if(board[x][y].isRevealed && mines_around!=0)
    {
        if(mines_around==1)
            return '1';
        if(mines_around==2)
            return '2';
        if(mines_around==3)
            return '3';
        if(mines_around==4)
            return '4';
        if(mines_around==5)
            return '5';
        if(mines_around==6)
            return '6';
        if(mines_around==7)
            return '7';
        if(mines_around==8)
            return '8';
    }



}



