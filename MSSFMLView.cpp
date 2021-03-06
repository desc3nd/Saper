
#include "MSSFMLView.h"
#include "MinesweeperBoard.h"
#include <iostream>
using namespace std;
MSSFMLView::MSSFMLView(MinesweeperBoard &x) : board(x) {
    height = board.getBoardHeight();
    width = board.getBoardWidth();
    screenX = 1000;
    screenY = 1000;
    drawRectangle();
       if (!font.loadFromFile("arial.ttf"))
       {
           std::cerr << "błąd w czytywaniu fontu";
       }
}
 float MSSFMLView::getScreenX() {
    return screenX;
}
float MSSFMLView::getScreenY() {
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
            x=x+screenX/float(width);
        }
        y=y+screenY/float(height);
        x=0;
    }
}

void MSSFMLView::rectangleEventLeft(int x, int y) {

    board.revealField(x, y);
        if (board.getFieldInfo(x, y) == 'x')
        {
            rectangle[x][y].setFillColor(sf::Color(100, 0, 0));
            eventTxt.setFont(font);
            eventTxt.setPosition((screenX/2-250),(screenY/2-100));
            eventTxt.setCharacterSize(100);
            eventTxt.setString("Game Over");
        }
    if (board.getFieldInfo(x, y) == ' ')
    {
        rectangle[x][y].setFillColor(sf::Color(0, 100,0 ));
    }
}
void MSSFMLView::rectangleEventRight(int x, int y) {
    {
        if(board.hasFlag(x,y))
            rectangle[x][y].setFillColor(sf::Color(0,0,0));

        board.toggleFlag(x,y);

        if(board.getFieldInfo(x,y)=='F')
            rectangle[x][y].setFillColor(sf::Color(50,50,50));
    }
}

void MSSFMLView::drawNumberOfBombs(int x, int y, float ix, float iy)
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