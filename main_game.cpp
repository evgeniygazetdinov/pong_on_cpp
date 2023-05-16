#include <SFML/Graphics.hpp>
#include "game.h"

using namespace sf;

int main()
{
	RenderWindow window(VideoMode(600, 600), "15");
	window.setFramerateLimit(60);
	Font font;
	font.loadFromFile("fonts/calibri.ttf");
	Text text("F2 new game/ ESC exit /Arrow keys for moving", font, 20);
	text.setFillColor(Color::Cyan);
	text.setPosition(5.f, 5.f);

	Game game;
	game.setPosition(50.f, 50.f);
	Event event;

	int move_counter = 0;

	while(window.isOpen())
	{
		while(window.pollEvent(event))
		{
			if(event.type == Event::Closed) window.close();
			if(event.type == Event::KeyPressed)
			{
				if (event.key.code == sf::Keyboard::Escape) window.close();
				if (event.key.code == sf::Keyboard::Left) game.Move(Direction::Left);
				if (event.key.code == sf::Keyboard::Right) game.Move(Direction::Right);
				if (event.key.code == sf::Keyboard::Up) game.Move(Direction::Up);
				if (event.key.code == sf::Keyboard::Down) game.Move(Direction::Down);

				if(event.key.code == sf::Keyboard::F2)
				{
					game.Init();
					move_counter = 100;
				}


			}
		}
		// если счетчик меньше нуля продолжаем перемещать головоломку
		if(move_counter--  > 0) game.Move((Direction) (rand() % 4));

		window.clear();
		window.draw(game);
		window.draw(text);
		window.display();
	}

	return 0;
}