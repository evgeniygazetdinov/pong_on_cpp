#include <SFML/Graphics.hpp>

using namespace sf;

int main()
{
    RenderWindow window(VideoMode(640, 480), "SFML works!");

    Image image;
    image.loadFromFile("images/player.png");
    Texture texture;
    texture.loadFromImage(image);
    // квадрат на который натягивается текстура
    Sprite player;
    player.setTexture(texture);     // ширина и высота
    player.setTextureRect(IntRect(0, 0, 31, 32));
    player.setPosition(10, 10);


    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();

            
        }

        //move into another class
        if(Keyboard::isKeyPressed(Keyboard::Left)){
            player.move(-1.0, 0);
        }
        if(Keyboard::isKeyPressed(Keyboard::Right)){
            player.move(1.0, 0);
        }
        if(Keyboard::isKeyPressed(Keyboard::Up)){
            player.move(0, -1.0);
        }
        if(Keyboard::isKeyPressed(Keyboard::Down)){
            player.move(0, 1.0);
        }

        window.clear();
        window.draw(player);
        window.display();
    }

    return 0;
}