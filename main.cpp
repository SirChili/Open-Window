#include "SFML/Graphics.hpp"
#include <vector>
#include <iostream>
#include <windows.h>
#include <ctime>

int main() {

    srand(time(0));

    //create window(x,y)
    sf::RenderWindow window(sf::VideoMode({ 1280,720 }), "Tony's Window");

    sf::Vector2f position(0.0f, 0.0f);

    std::vector<sf::Color> colors = { sf::Color::Blue, sf::Color::Red, sf::Color::Black, sf::Color::Magenta };
    int randomizer = rand() % colors.size();

	sf::Font font("E:\\Tony's Stuff\\.cpp files\\repos\\SFML\\Fonts\\spicy_sale\\SpicySale.ttf");
    sf::Text text(font);
    text.setString("WHATSSS UPPPPP CHATTTT");
	text.setCharacterSize(70);
    text.Regular;
	text.setPosition({ 100.0f,300.0f });
    
    sf::RectangleShape shape;
	shape.setSize({ 100.0f,100.0f });
    shape.setFillColor(colors[randomizer]);
    
    shape.setPosition(position);
    
    //While window is open, run
    while (window.isOpen()) {

        //Gets mouse position (x,y)
        sf::Vector2i mPosition = sf::Mouse::getPosition(window);

        window.clear(sf::Color::Black);
        window.draw(text);
        //window.draw(shape);
        window.display();

        while (const std::optional event = window.pollEvent()) {

            //std::cout << "Mouse Positiu87-on: ";
            std::cout << mPosition.x << "  ";
            std::cout << mPosition.y << '\n';

            
            if (event->is<sf::Event::Closed>()) {
                window.close();
            }

        }

    }

    return 0;
}
