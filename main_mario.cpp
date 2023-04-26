#include <SFML/Graphics.hpp>
#include <iostream>

using namespace sf;

// 

int main() {

  float currentFrame = 0;
  RenderWindow window(VideoMode(200, 200), "my turbo game");
  Texture myTexture;
  myTexture.loadFromFile("images/fang.png");
  Sprite mySprite;
  mySprite.setTexture(myTexture);
                                 // x y weight height
  mySprite.setTextureRect(IntRect(0, 244, 40, 50));
  mySprite.setPosition(50, 100);

  Clock myclock;

  while (window.isOpen()) {
    // float time = myclock.getElapsedTime().asMicroseconds();
    // myclock.restart();
    // time = time / 1500;
    Event event;


    while (window.pollEvent(event)) {
      if (event.type == Event::Closed)
        window.close();
      if(Keyboard::isKeyPressed(Keyboard::Escape)){
        window.close();
      }
      if (Keyboard::isKeyPressed(Keyboard::Left)) {
          mySprite.move(-10, 0);
          std::cout<<"LEFT"<<std::endl;
           currentFrame += 0.005;
         currentFrame += 1;
          if(currentFrame >6){
            currentFrame -=6;
          }
          // INVERTING POSITION 
          mySprite.setTextureRect(IntRect(40 * int(currentFrame)+40, 244,-40,50));

      }
      if (Keyboard::isKeyPressed(Keyboard::Right)) {
          mySprite.move(10, 0);
          currentFrame += 1;
          if(currentFrame >6){
            currentFrame -=6;
          }
          mySprite.setTextureRect(IntRect(40 * int(currentFrame), 244,40,50));
      }
    }
    window.clear();
    window.draw(mySprite);
    window.display();
  }

  return 0;
}