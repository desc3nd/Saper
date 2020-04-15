
#ifndef SAPER_MSSFMLVIEW_H
#define SAPER_MSSFMLVIEW_H
#include<SFML/Graphics.hpp>
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


public:
   explicit MSSFMLView (MinesweeperBoard &x);
    void draw(sf::RenderTarget& target,sf::RenderStates states) const override;
    int getScreenX();
    int getScreenY();
    void rectangleEventLeft(int x,int y);
    void rectangleEventRight(int x,int y);
    void drawNumberOfBombs(int x, int y, int ix, int iy);
};


#endif //SAPER_MSSFMLVIEW_H
