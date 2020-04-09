
using namespace std;

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <Graphics/RenderWindow.hpp>
#include "MinesweeperBoard.h"
#include "MSBoardTextView.h"
#include "Array2D.h"
#include "MsTextController.h"
#include<SFML/Graphics.hpp>
#include "MSSFMLView.h"

int main()
{
    srand(time(NULL));
    MinesweeperBoard x(10,10, HARD);

    MSBoardTextView view(x);
    view.display();


    MSTextController ctrl(x, view);


    MSSFMLView view1(x);
    sf::RenderWindow win(sf::VideoMode(view1.getScreenWidth(), view1.getScreenHeight()), "Saper");
    win.setVerticalSyncEnabled(true);

    while (win.isOpen())
    {
        sf::Event event;

        while (win.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                win.close();
            }
            if (event.type == sf::Event::MouseButtonPressed)
            {

                view1.GraphicController(event);
                x.Debug_Display();
                std::cout << "X:" << event.mouseButton.x << std::endl;
                std::cout << "Y:" << event.mouseButton.y << std::endl;

            }
            win.clear(sf::Color::Blue);
            win.draw(view1);
            win.display();
        }
    }
}