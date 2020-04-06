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
     int screenX;
    int screenY;
    int width;
    int height;
    sf::VertexArray linex[10];
    sf::RectangleShape rectangle[10][10];
public:
   explicit MSSFMLView (MinesweeperBoard &x);
    void draw(sf::RenderTarget& target,sf::RenderStates states) const;
    int getScreenWidth();
    int getScreenHeight();
    void drawBoard();
    void rec();


};


#endif //SAPER_MSSFMLVIEW_H
