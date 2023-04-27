
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <iostream>
using namespace std;
using namespace sf;

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <iostream>
using namespace std;
using namespace sf;
int main()
{
	RenderWindow win(VideoMode(640, 480), "NUM9");
	CircleShape sh(100, 6);
	sh.setOrigin(Vector2f(sh.getRadius(), sh.getRadius()));
	sh.setFillColor(Color::Red);
	sh.setPosition(Vector2f(win.getSize().x / 2, win.getSize().y / 2));

	while (win.isOpen())
	{
		Event event;
		while (win.pollEvent(event))
		{
			if (event.type == Event::Closed)
			{
				win.close();
				break;
			}
			win.clear();
			win.draw(sh);
			win.display();
		}
	}
	return EXIT_SUCCESS;
}