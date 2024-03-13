#include <iostream>
#include <SFML/Graphics.hpp>



int main()
{
   
    sf::RenderWindow window(sf::VideoMode(800, 600), "test sfml");
    int soccetSize = 60;
    std::vector<sf::RectangleShape>field;
    sf::RectangleShape soccet;
    for(int i=0; i < window.getSize().x - soccetSize; i += soccetSize)
    {
        for (int j = 0; j < window.getSize().x - soccetSize; j += soccetSize)
        {
            
            soccet.setOutlineThickness(2);
            soccet.setOutlineColor(sf::Color::Black);
            soccet.setSize(sf::Vector2f(soccetSize, soccetSize));
            soccet.setPosition(sf::Vector2f(j, i));
            field.push_back(soccet);
        }
    }

    

    bool kursor(soccetSize / 2);
    kursor = sf::Mouse::isButtonPressed(sf::Mouse::Left);
    int countSoccetWidth = window.getSize().x / soccetSize - 1;
    int countSoccetHeight = window.getSize().y / soccetSize - 1;
    bool isMouseClicked = false;

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            if(sf::Mouse::isButtonPressed(sf::Mouse::Left))
            {
                sf::Vector2i mousePos = sf::Mouse::getPosition(window);
                for(sf::RectangleShape& rect : field)
                {
                    if(rect.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos)))
                    {
                        if (isMouseClicked)
                            rect.setFillColor(sf::Color::Black);
                        else
                            rect.setFillColor(sf::Color::White);

                        isMouseClicked = !isMouseClicked;

                        break;
                    }
                }
            }
            
        }

      /*  sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
            {
                sf::Vector2i mousePos = sf::Mouse::getPosition(window);
                for (sf::RectangleShape& rect : field)
                {
                    if (rect.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos)))
                    {
                        rect.setFillColor(sf::Color::Black);
                        break;
                    }
                }
            }
            if (sf::Mouse::isButtonPressed(sf::Mouse::Right))
            {
                sf::Vector2i mousePos = sf::Mouse::getPosition(window);
                for (sf::RectangleShape& rect : field)
                {
                    if (rect.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos)))
                    {
                        rect.setFillColor(sf::Color::Green);
                        break;
                    }
                }
            }
        }*/

        window.clear(sf::Color::White);
        for(auto el: field)
        {
            window.draw(el);
        }
       // window.draw(circle);
        window.display();
        
    }

    return 0;
}


