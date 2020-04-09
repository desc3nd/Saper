//
// Created by ja on 09.03.2020.
//
using namespace std;
#include<iostream>
#include "MinesweeperBoard.h"
#include <math.h>
#include <cstdlib>

MinesweeperBoard::MinesweeperBoard(int height,int width, GameMode mode)
{
   this->width=width;
   this->height=height;
   this->mode=mode;
   this->status_gry=RUNNING;

   this->number_of_player_action=0;
   covered=width*height;
    //zerowanie mapy
    for(int row=0; row<height; row++)
    {
        for(int col=0; col<width; col++)
        {
            board[row][col].hasFlag=0;
            board[row][col].hasMine=0;
            board[row][col].isRevealed=0;
        }
    }
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

            if(board[row][col].hasFlag)
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
   if(BeyondSize(x,y)!=true)
        return -1;
    if(!board[x][y].isRevealed)
        return -1;

        int number_of_bombs = 0;
        if(x+1<=height && board[x+1][y].hasMine)
            number_of_bombs++;
        if( x-1>=0 && board[x-1][y].hasMine )
            number_of_bombs++;
        if(y+1<=width && board[x][y+1].hasMine)
            number_of_bombs++;
        if(y-1>=0 && board[x][y-1].hasMine )
            number_of_bombs++;
        if(x+1<=height && y+1<=height && board[x+1][y+1].hasMine)
            number_of_bombs++;
        if(x-1>=0 && y-1>=0 && board[x-1][y-1].hasMine)
            number_of_bombs++;
        if( x+1<=height && y-1>=0 && board[x+1][y-1].hasMine)
            number_of_bombs++;
        if(x-1>=0 && y+1<=width && board[x-1][y+1].hasMine)
            number_of_bombs++;
        return number_of_bombs;
    }

bool MinesweeperBoard::hasFlag(int x, int y) const
{
    if(BeyondSize(x,y)!=true)
        return false;
    if(board[x][y].isRevealed)
        return false;
    if(board[x][y].hasFlag)
        return true;
    if(!board[x][y].hasFlag)
        return false;

        return false;
}

void MinesweeperBoard::toggleFlag(int x, int y)
{
    if(BeyondSize(x,y)!=true)
        return;
    if(board[x][y].isRevealed)
        return;
    if(status_gry==FINISHED_LOSS || status_gry==FINISHED_WIN)
        return;
    if(!board[x][y].hasFlag)
    {
        board[x][y].hasFlag=true;
        return;
    }
    if(board[x][y].hasFlag)
    {
        board[x][y].hasFlag=false;
    }
}

void MinesweeperBoard::revealField(int x, int y)
{
    if(BeyondSize(x,y)!=true)
        return;
    number_of_player_action++;
    if(board[x][y].isRevealed)
        return;
    if(status_gry!=RUNNING)
        return;
    if(board[x][y].hasFlag)
        return;
    if(!board[x][y].hasMine && !board[x][y].isRevealed)
    {
        board[x][y].isRevealed=true;
        covered--;
    }

    if(board[x][y].hasMine && !board[x][y].isRevealed)
    {
        if(number_of_player_action==1)
        {
            board[x][y].isRevealed=true;
            board[x][y].hasMine=false;
                int row = rand() % height;
                int col = rand() % width;
            while(board[row][col].hasMine)
            {
                row=rand()%height;
                col=rand()%width;
            }
            board[row][col].hasMine=true;
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
    if(BeyondSize(x,y)!=true)
         return false;
    if (board[x][y].isRevealed)
        return true;

        return false;
}

GameState MinesweeperBoard::getGameState() const
{
    if (status_gry == FINISHED_LOSS)
        return FINISHED_LOSS;
    if (status_gry == RUNNING && covered==bomb)
        return FINISHED_WIN;
    return RUNNING;
}

char MinesweeperBoard::getFieldInfo(int x, int y) const
{
    int mines_around=countMines(x, y);

    if(BeyondSize(x,y)!=true)
        return '#';
    if(!board[x][y].isRevealed && board[x][y].hasFlag)
        return 'F';
    if(!board[x][y].isRevealed && !board[x][y].hasFlag)
        return '_';
    if(board[x][y].isRevealed && board[x][y].hasMine)
        return 'x';
    if(board[x][y].isRevealed && mines_around==0)
        return ' ';
    if(board[x][y].isRevealed && mines_around!=0)
    {
        if(mines_around==1)
            return '0' + mines_around;
        if(mines_around==2)
            return '0' + mines_around;
        if(mines_around==3)
            return '0' + mines_around;
        if(mines_around==4)
            return '0' + mines_around;
        if(mines_around==5)
            return '0' + mines_around;
        if(mines_around==6)
            return '0' + mines_around;
        if(mines_around==7)
            return '0' + mines_around;
        if(mines_around==8)
            return '0' + mines_around;
    }
    return '.';
}

void MinesweeperBoard::BombOnBoard(float percentage)
{
    int NumberOfBombs=round(width*height*(percentage)); // round
    for(bomb=0;bomb<NumberOfBombs;)
    {
        int row=rand()%height;
        int col=rand()%width;
        if(board[row][col].hasMine==0)
        {
            board[row][col].hasMine = true;
            bomb++;
        }
    }
}
bool MinesweeperBoard::BeyondSize(int x, int y) const
        {
                if(x>=height || y>=width || x<0 || y<0)
                return false;
                return true;
        }

