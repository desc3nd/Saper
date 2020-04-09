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
    screenX = 1200;
    screenY = 800;
    for(int i=0;i<higher();i++) {

            linex[i] = sf::VertexArray(sf::Lines);
    }

    drawBoard();
    drawRectangle();
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
    for (int i = 0; i < height; i++)
    {
        target.draw(linex[i], states);
    }
    for (int i = 0; i < width; i++)
    {
        target.draw(linex[i], states);
    }
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            target.draw(text[i][j], states);
        }
    }
}

void MSSFMLView::drawBoard()
{
    int i=0;

    for (int x = 0; x <= screenX; x = x+screenX/width)//round
    {
        linex[i].append(sf::Vector2f(x,0));
        linex[i].append(sf::Vector2f(x, screenY));
        if(i>=width) //tu zmiana
            break;
        i++;

        }
    i=0;
    for (int y = 0; y <= screenY; y = y+screenY/height)
    {
        linex[i].append(sf::Vector2f(0,y));
        linex[i].append(sf::Vector2f(screenX, y));
        if(i>=height) // tu zmiana
            break;
        i++;
    }
}

void MSSFMLView::drawRectangle() {
    float y=0;
    float x=0;
    for(int i=0; i<height; i++)
    {

        for(int j=0; j<width; j++)
        {
            rectangle[i][j].setPosition(x,y);
            rectangle[i][j].setSize(sf::Vector2f(screenX/width, screenY/height));
            rectangle[i][j].setFillColor(sf::Color(0,0,0));
            x=x+screenX/width;
        }
        y=y+screenY/height;
        x=0;
    }

}

void MSSFMLView::GraphicController(sf::Event event) {
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
               eventController(i,j,event);
                if (event.mouseButton.button == sf::Mouse::Left)
               drawNumberOfBombs(i,j,x,y);
            }
            a=a+screenX/width;
        }
        y=y+screenY/height;
        b=b+screenY/height;
    }
}

void MSSFMLView::eventController(int x, int y,sf::Event event) {

    if (event.mouseButton.button == sf::Mouse::Left)
    {
        board.revealField(x, y);
        if (board.getFieldInfo(x, y) == 'x')
        {
            rectangle[x][y].setFillColor(sf::Color(100, 0, 0));
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

    if (!font.loadFromFile("arial.ttf"))
    {
        std::cerr << "błąd w czytywaniu fontu";
    }
    char literka = board.getFieldInfo(x, y);
    int kodliterki = (int) literka;
        for (int i = 48; i < 58; i++)
        {

        if (kodliterki == i)
        {
            rectangle[x][y].setFillColor(sf::Color(0, 0, 100));

                text[x][y].setFont(font);
                text[x][y].setCharacterSize(screenY/ higher());
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
