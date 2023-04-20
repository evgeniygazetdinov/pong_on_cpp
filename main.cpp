#include <SFML/Graphics.hpp>
#include <iostream>

using namespace sf;

float frame = 0.0;

class Player{
  public:
    float x, y, weight, height, vx, vy, speed = 0;
    int direction = 0;
    String filename;
    Image image;
    Texture texture;
    Sprite sprite;
    float wayDistance = 0.5;
    float animationSpeed = 0.01;
    Player(int posX, int posY, int playerWeight, int playerHeight, String cartonName){
        x = posX;
        y = posY;
        weight = playerWeight;
        height = playerHeight;
        filename = cartonName;
        image.loadFromFile("images/" + filename);
        texture.loadFromImage(image);
        // square for stretch texture
        sprite.setTexture(texture); // ширина и высота
        sprite.setTextureRect(IntRect(0, 0, weight, height));
        sprite.setPosition(x, y);
    }
    void update(float time){
      switch (dir)
      {
      case /* constant-expression */:
        /* code */
        break;
      
      default:
        break;
      }

    }
    

};

int main() {
  RenderWindow window(VideoMode(640, 480), "my turbo game");
  Player hero(50, 50, 31, 32, "player.png");
  


  //bound by time

  Clock myclock;

  while (window.isOpen()) {
    // recalculate time for more slow moving char
    float time = myclock.getElapsedTime().asMicroseconds();
    myclock.restart();
    time = time / 1500;
    Event event;

    // move variable

    while (window.pollEvent(event)) {
      if (event.type == Event::Closed)
        window.close();
      if(Keyboard::isKeyPressed(Keyboard::Escape)){
        window.close();
      }
    }
    //move into another class
    if (Keyboard::isKeyPressed(Keyboard::Left)) {
      player.move(-wayDistance * time, 0);
       if (frame > 2) frame -= 2;
        player.setTextureRect(IntRect(31 *int(frame),96, 31, 32));
    }
    if (Keyboard::isKeyPressed(Keyboard::Right)) {
      player.move(wayDistance * time, 0);
      if (frame > 2) frame -= 2;
        player.setTextureRect(IntRect(31 *int(frame),32, 31, 32));
    }
    if (Keyboard::isKeyPressed(Keyboard::Up)) {
      player.move(0, -wayDistance * time);
      if (frame > 2) frame -= 2;
        player.setTextureRect(IntRect(31 *int(frame),0, 31, 32));
    }
    if (Keyboard::isKeyPressed(Keyboard::Down)) {
      player.move(0, wayDistance * time);
      if (frame > 2) frame -= 2;
        player.setTextureRect(IntRect(31 *int(frame),64, 31, 32));
    }

    window.clear();
    window.draw(player);
    window.display();
  }

  return 0;
}
