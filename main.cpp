
using namespace std;

#include <iostream>
#include <cstdlib>
#include <ctime>

#include "MinesweeperBoard.h"
#include "MSBoardTextView.h"
#include "Array2D.h"
#include "MsTextController.h"
#include<SFML/Graphics.hpp>
#include "MSSFMLView.h"
#include "MSSFLMController.h"

int main()
{
    srand(time(NULL));
    MinesweeperBoard x(20,20, HARD);
    MSBoardTextView view(x);
    view.display();
    MSTextController ctrl(x, view);
    MSSFMLView SFMLView (x);
    MSSFLMController SFMLController(x,SFMLView);
    sf::RenderWindow win(sf::VideoMode(SFMLView.getScreenX(), SFMLView.getScreenY()), "Saper");
    win.setVerticalSyncEnabled(true);
    sf::Font font;
    sf::Event event;
    while (win.isOpen())
    {
        while (win.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                win.close();
            }
            if (event.type == sf::Event::MouseButtonPressed)
            {
               SFMLController.play(event);
                x.Debug_Display();
                std::cout << "X:" << event.mouseButton.x << std::endl;
                std::cout << "Y:" << event.mouseButton.y << std::endl;
            }

        }
        win.clear(sf::Color::Blue);
        win.draw(SFMLView);
        win.display();
    }
}