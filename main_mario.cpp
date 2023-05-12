#include <SFML/Graphics.hpp>
#include <iostream>

using namespace sf;

int ground = 150;
const int H = 24;
const int W = 80;

String TileMap[H] = {
"BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB",
"B                                      B",
"B                                      B",
"B                                      B",
"B                                      B",
"B                                      B",
"B                                      B",
"B                                      B",
"BBBBBB      0                          B",
"B           0                          B",
"B           0                          B",
"BBBBB     BBBBBBBBBBBBBBBBBBBBBBBBBBBBBB",
};


class Player{
  public:
    float dx, dy;// speed variables
    FloatRect rect;
    bool onGround;
    Sprite sprite;
    float currentFrame;
   Player(Texture &image){
    sprite.setTexture(image);
    rect = FloatRect(0, 0, 40, 50);
    dx = dy = 40;
    currentFrame = 0;
   }
   void update(float time){
      rect.left += dx * time;
      if(!onGround) {
        dy=dy + 0.0005 * time;
        rect.top += dy * time;
        onGround=false;
      }
      if(rect.top > ground){
        rect.top = ground;
        dy = 0;
        onGround = true;
      }
      currentFrame+=0.05 * time;
      if(currentFrame >6){
        currentFrame -=6;
      }
      if(dx>0){
        sprite.setTextureRect(IntRect(40 * int(currentFrame), 244,40,50));
      }
      if(dx<0){
        sprite.setTextureRect(IntRect(40 * int(currentFrame)+40, 244,-40,50));
      }
      sprite.setPosition(rect.left, rect.top);
      dx = 0;
   }

};


int main() {

  float currentFrame = 0;
  RenderWindow window(VideoMode(200, 200), "my turbo game");
  Texture myTexture;
  myTexture.loadFromFile("images/fang.png");

  Player myPlayer(myTexture);  
  Clock myclock;

RectangleShape rectangle;


  while (window.isOpen()) {
    float time = myclock.getElapsedTime().asMicroseconds();
    myclock.restart();
    time = time / 800;
    Event event;


    while (window.pollEvent(event)) {

      if (event.type == Event::Closed)
        window.close();
      if(Keyboard::isKeyPressed(Keyboard::Escape)){
        window.close();
      }
      if (Keyboard::isKeyPressed(Keyboard::Left)) {
         myPlayer.dx = -30;

      }
      if (Keyboard::isKeyPressed(Keyboard::Right)) {
          myPlayer.dx = 30;

      }
      if (Keyboard::isKeyPressed(Keyboard::Up)) {
          if(myPlayer.onGround){
            myPlayer.dy=-0.2; myPlayer.onGround = false;
          }
      }
    }
    myPlayer.update(time);
    window.clear();
    for(int i=0;i<H;i++)
      for(int j=0;j<W;j++){
        if(TileMap[i][j] == 'B'){
          rectangle.setFillColor(Color::Blue);
          std::cout<<i<<std::endl;
        }
        if(TileMap[i][j] == ' '){
          continue;
        }
        if(TileMap[i][j] == '0'){
          rectangle.setFillColor(Color::Green);
        }
        rectangle.setPosition(0, 0);
        window.draw(rectangle);
      }
    
    window.draw(myPlayer.sprite);
    window.display();
  }

  return 0;
}