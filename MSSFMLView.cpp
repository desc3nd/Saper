//
// Created by Marcinek on 06.04.2020.
//

#include "MSSFMLView.h"
#include "MSBoardTextView.h"
#include "MinesweeperBoard.h"
using namespace std;
MSSFMLView::MSSFMLView(MinesweeperBoard &x) : board(x) {
    screenX = 600;
    screenY = 800;
    height = board.getBoardHeight();
    width = board.getBoardWidth();
    for(int i=0;i<10;i++) {

            linex[i] = sf::VertexArray(sf::Lines);
    }

   drawBoard();
    rec();
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
        for(int j=0; j<width; j++)
        {
            target.draw(rectangle[i][j], states);
        }
    }
    for (int i = 0; i < height; i++)
    {
        target.draw(linex[i], states);
        target.draw(linex[i], states);
    }
    for (int i = 0; i < width; i++)
    {
        target.draw(linex[i], states);
    }
}


void MSSFMLView::drawBoard()
{
    int i=0;

    for (int x = 0; x <= screenX; x=x+screenX/width)
    {
        linex[i].append(sf::Vector2f(x,0));
        linex[i].append(sf::Vector2f(x, screenY));
        i++;
        if(i==width)
            break;
        }
    i=0;
    for (int y = 0; y <= screenY; y=y+screenY/height)
    {
        linex[i].append(sf::Vector2f(0,y));
        linex[i].append(sf::Vector2f(screenX, y));
        i++;
        if(i==height)
            break;
    }
    float y=0;
    float x=0;
    for(int i=0; i<height; i++)
    {

        for(int j=0; j<width; j++)
        {
             x=x+screenX/width;
            rectangle[i][j].setPosition(x,y);
           rectangle[i][j].setSize(sf::Vector2f(screenX/width, screenY/height));
            rectangle[i][j].setFillColor(sf::Color(0,0,0));

        }
        y=y+screenY/height;
    }


}

void MSSFMLView::rec() {
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
