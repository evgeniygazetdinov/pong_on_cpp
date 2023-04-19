#include <SFML/Graphics.hpp>
#include <iostream>

using namespace sf;

float frame = 0.0;

int main() {
  RenderWindow window(VideoMode(640, 480), "my turbo game");

  Image image;
  image.loadFromFile("images/player.png");
  Texture texture;
  texture.loadFromImage(image);
  // square for stretch texture
  Sprite player;
  player.setTexture(texture); // ширина и высота
  player.setTextureRect(IntRect(0, 0, 31, 32));
  player.setPosition(10, 10);

  //bound by time

  Clock myclock;

  while (window.isOpen()) {
    // recalculate time for more slow moving char
    float time = myclock.getElapsedTime().asMicroseconds();
    myclock.restart();
    time = time / 1500;
    Event event;

    // move variable
    float wayDistance = 0.5;
    float animationSpeed = 0.05;
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
