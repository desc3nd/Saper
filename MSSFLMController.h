
#ifndef SAPER_MSSFLMCONTROLLER_H
#define SAPER_MSSFLMCONTROLLER_H
#include"MSSFMLView.h"
#include<SFML/Graphics.hpp>
#include "MinesweeperBoard.h"

class MSSFLMController {

MinesweeperBoard &board;
MSSFMLView &view;
float screenX;
float screenY;
int height;
int width;
sf::Event myEvent;
void shapeEventReaction(int x, int y, float ix, float iy);
public:
    MSSFLMController(MinesweeperBoard &x, MSSFMLView &y);
   void play(sf::Event &event);
};


#endif //SAPER_MSSFLMCONTROLLER_H
