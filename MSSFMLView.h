//
// Created by Marcinek on 06.04.2020.
//

#ifndef SAPER_MSSFMLVIEW_H
#define SAPER_MSSFMLVIEW_H
#include<SFML/Graphics.hpp>
#include "MSBoardTextView.h"
#include "MinesweeperBoard.h"

class MSSFMLView: public sf::Drawable {
    MinesweeperBoard &board;
    float screenX;
    float screenY;
    int width;
    int height;
    sf::RectangleShape rectangle[20][20];
    sf::Text text[20][20];
    sf::Text eventTxt;
    sf::Font font;
    void drawRectangle();
    int higher();
    void drawNumberOfBombs(int x, int y, int ix, int iy);
    void rectangleEventReaction(int x,int y,sf::Event event);
public:
   explicit MSSFMLView (MinesweeperBoard &x);
    void draw(sf::RenderTarget& target,sf::RenderStates states) const;
    int getScreenWidth();
    int getScreenHeight();
    void eventController(sf::Event event);
};


#endif //SAPER_MSSFMLVIEW_H
