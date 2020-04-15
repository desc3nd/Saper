//
// Created by Marcinek on 06.04.2020.
//

#include "MSSFMLView.h"
#include "MinesweeperBoard.h"
#include <iostream>
using namespace std;
MSSFMLView::MSSFMLView(MinesweeperBoard &x) : board(x) {
    height = board.getBoardHeight();
    width = board.getBoardWidth();
    screenX = 1000;
    screenY = 1000;
    sf::Text eventTxt;
    drawRectangle();
       if (!font.loadFromFile("arial.ttf"))
       {
           std::cerr << "błąd w czytywaniu fontu";
       }
}
 int MSSFMLView::getScreenWidth() {
    return screenX;
}

 int MSSFMLView::getScreenHeight() {
    return screenY;
}

void MSSFMLView::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    for (int i = 0; i < height; i++)
    {
        for(int j = 0; j < width; j++)
        {
            target.draw(rectangle[i][j], states);
            target.draw(text[i][j],states);

        }
    }

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            target.draw(text[i][j], states);
        }
    }
    target.draw(eventTxt,states);
}



void MSSFMLView::drawRectangle() {
    float y=0;
    float x=0;
    for(int i=0; i<height; i++)
    {

        for(int j=0; j<width; j++)
        {
            rectangle[i][j].setPosition(x,y);
            rectangle[i][j].setSize(sf::Vector2f(float(screenX/width), float(screenY/height)));
            rectangle[i][j].setFillColor(sf::Color::Black);
            rectangle[i][j].setOutlineThickness(1);
            rectangle[i][j].setOutlineColor(sf::Color::White);
            x=x+screenX/width;
        }
        y=y+screenY/height;
        x=0;
    }

}

void MSSFMLView::eventController(sf::Event event) {
    float y=screenY/height;//80
    float x=0;//0
    float a=0;//x
    float b=0;//y
    for(int i=0;i<height; i++)
    {
        x=0;
        a=0;
        for(int j=0; j<width; j++)
        {
            x=x+screenX/width;
            if( event.mouseButton.x <x && event.mouseButton.x>a &&  event.mouseButton.y <y && event.mouseButton.y>b)
            {
                cout<<"x:"<<x<<endl<<"y:"<<y<<endl<<"a:"<<a<<endl<<"B:"<<b<<endl;
               rectangleEventReaction(i,j,event);
                if (event.mouseButton.button == sf::Mouse::Left)
               drawNumberOfBombs(i,j,x,y);
            }
            a=a+screenX/width;
        }
        y=y+screenY/height;
        b=b+screenY/height;
    }
}

void MSSFMLView::rectangleEventReaction(int x, int y,sf::Event event) {

    if (event.mouseButton.button == sf::Mouse::Left)
    {
        board.revealField(x, y);
        if (board.getFieldInfo(x, y) == 'x')
        {
            rectangle[x][y].setFillColor(sf::Color(100, 0, 0));
            eventTxt.setFont(font);
            eventTxt.setPosition((screenX/2-250),(screenY/2-100));
            eventTxt.setCharacterSize(100);
            eventTxt.setString("Game Over");
        }
    }
    if (board.getFieldInfo(x, y) == ' ')
    {
        rectangle[x][y].setFillColor(sf::Color(0, 100,0 ));
    }
    if (event.mouseButton.button == sf::Mouse::Right)
    {
        if(board.hasFlag(x,y))
            rectangle[x][y].setFillColor(sf::Color(0,0,0));

        board.toggleFlag(x,y);

        if(board.getFieldInfo(x,y)=='F')
            rectangle[x][y].setFillColor(sf::Color(50,50,50));
    }
}

void MSSFMLView::drawNumberOfBombs(int x, int y, int ix, int iy)
{
    char literka = board.getFieldInfo(x, y);
    int kodliterki = (int) literka;
        for (int i = 48; i < 58; i++)
        {

        if (kodliterki == i)
        {
            rectangle[x][y].setFillColor(sf::Color(0, 0, 100));

                text[x][y].setFont(font);
                text[x][y].setCharacterSize(float(screenY/ higher()));
                text[x][y].setPosition(ix-(screenX/float(width)/2), iy-(screenY/float(height)));
                text[x][y].setString(literka);
            }
        }

    }

int MSSFMLView::higher() {
    if(height>width)
        return height;
    return width;
}
