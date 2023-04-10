
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <iostream>
using namespace sf;
using namespace std;

int main()
{
	ContextSettings sett;
	sett.antialiasingLevel = 8;
	

	RenderWindow window(VideoMode(640, 480), "First window",Style::Default, sett);

	CircleShape shape(80);
	CircleShape shape2(80,5);

	ConvexShape conv;
	conv.setPointCount(5);
	conv.setPoint(0, Vector2f(0, 0));
	conv.setPoint(1, Vector2f(150, 10));
	conv.setPoint(2, Vector2f(120, 90));
	conv.setPoint(3, Vector2f(30, 100));
	conv.setPoint(4, Vector2f(0, 50));
	conv.setFillColor(Color::Yellow);
	conv.setPosition(Vector2f(window.getSize().x / 4 * 3, window.getSize().y / 4 * 3));

	Color c(0,0,0);
	c.r = 0;
	c.g = 255;
	c.b = 0;
	shape.setFillColor(c);
	shape.setOrigin(Vector2f(shape.getRadius(), shape.getRadius()));
	shape.setPosition(Vector2f(window.getSize().x/2, window.getSize().y / 2));

	shape2.setFillColor(c);
	shape2.setOrigin(Vector2f(shape.getRadius(), shape.getRadius()));
	shape2.setPosition(Vector2f(window.getSize().x / 4, window.getSize().y / 4));
	int r = 0, g = 0, b = 0;
	const int change = 100;
	int cash = 0;
	const float speed= 0.01;
	Clock deltacl;
	Time dt;
	const int um = 3000;
	Texture tex_shape;
	if (!tex_shape.loadFromFile("C:\\Users\\Daniil\\Desktop\\IT_Lessons\\C_plus_48_2\\Lesson 3\\im2.jpg")) {
		exit(EXIT_FAILURE);
	}
	shape.setTexture(&tex_shape);
	while (window.isOpen()) {
		Event event;
		while (window.pollEvent(event)) {
			switch (event.type) {
			case Event::Closed:
					window.close();
					cout << "END! BTN WIN";
					break;
			default:
				break;
			}
		}
		window.clear();
		if (cash == change) {
			r++;
			g++;
			b++;
			if (r >= 255 and g >= 255 and b >= 255) {
				r = 0;
				g = 0;
				b = 0;
			}
			cash = 0;
		}
		cash++;
		Color col(r, g, b);
		shape.setFillColor(col);
		dt = deltacl.restart();
		
		if (Keyboard::isKeyPressed(Keyboard::Up)) {
			shape.move(Vector2f(0, -speed) * (dt.asSeconds()*um));
		}
		if (Keyboard::isKeyPressed(Keyboard::Down)) {
			shape.move(Vector2f(0, speed) * (dt.asSeconds() * um));
		}
		if (Keyboard::isKeyPressed(Keyboard::Left)) {
			shape.move(Vector2f(-speed,0) * (dt.asSeconds() * um));
		}
		if (Keyboard::isKeyPressed(Keyboard::Right)) {
			shape.move(Vector2f(speed, 0) * (dt.asSeconds() * um));
		}

		if (Keyboard::isKeyPressed(Keyboard::W)) {
			shape2.move(Vector2f(0, -speed) * (dt.asSeconds() * um));
		}
		if (Keyboard::isKeyPressed(Keyboard::S)) {
			shape2.move(Vector2f(0, speed) * (dt.asSeconds() * um));
		}
		if (Keyboard::isKeyPressed(Keyboard::A)) {
			shape2.move(Vector2f(-speed, 0) * (dt.asSeconds() * um));
		}
		if (Keyboard::isKeyPressed(Keyboard::D)) {
			shape2.move(Vector2f(speed, 0) * (dt.asSeconds() * um));
		}

		
		window.draw(shape);
		window.draw(shape2);
		window.draw(conv);
		window.display();
		
	}
	window.close();

	return EXIT_SUCCESS;
}
