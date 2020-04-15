//
// Created by Marcinek on 15.04.2020.
//

#include "MSSFLMController.h"
#include "MSSFMLView.h"
using namespace std;
MSSFLMController::MSSFLMController(MinesweeperBoard &x, MSSFMLView &y) : board(x), view(y)
{
    screenX=view.getScreenX();
    screenY=view.getScreenY();
    height=board.getBoardHeight();
    width=board.getBoardWidth();
}
void MSSFLMController::play(sf::Event &event) {
float y=screenY/height;//80
float x=0;//0
float a=0;//x
float b=0;//y
myEvent=event;
for(int i=0;i<height; i++)
{
    x=0;
    a=0;
        for(int j=0; j<width; j++)
        {
            x=x+screenX/width;
            if( event.mouseButton.x <x && event.mouseButton.x>a &&  event.mouseButton.y <y && event.mouseButton.y>b)
            {
                shapeEventReaction(i, j, x, y);
            }
            a=a+screenX/width;
        }
            y=y+screenY/height;
            b=b+screenY/height;
}
}

void MSSFLMController::shapeEventReaction(int x, int y,float ix, float iy)
{
    if (myEvent.mouseButton.button == sf::Mouse::Left)
    {
        view.rectangleEventLeft(x,y);
        view.drawNumberOfBombs(x,y,ix,iy);
    }
    if (myEvent.mouseButton.button == sf::Mouse::Right)
    {
        view.rectangleEventRight(x,y);
    }
}





