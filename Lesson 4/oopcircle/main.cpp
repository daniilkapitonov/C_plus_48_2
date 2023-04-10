
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <cmath>
#include <ctime>
#include <cstdlib>
using namespace sf;

class Ball : public CircleShape {
public:
	double speed = 0.01;
	Ball (){}
	Ball(int d, Vector2f pos, Color col = Color::Red):CircleShape(d){
		this->setFillColor(col);
		this->setOrigin(Vector2f(this->getRadius(), this->getRadius()));
		this->setPosition(pos);
	}
	void setCol(Color col) {
		this->setFillColor(col);
	}
	void ball_move(int p) {
		switch (p)
		{
		case 1:
			this->move(Vector2f(0, -speed));
			break;
		case 2:
			this->move(Vector2f(0, speed));
			break;
		case 3:
			this->move(Vector2f(speed,0));
			break;
		case 4:
			this->move(Vector2f(-speed,0));
			break;
		default:
			break;
		}
	}
};


int main()
{
	RenderWindow win(VideoMode(800, 500), "OOP CIRCLE");
	Ball* mass_b = new Ball[4];
	mass_b[0] = Ball(80, Vector2f(100, 100),Color::Green);
	mass_b[1] = Ball(80, Vector2f(280, 100));
	mass_b[2] = Ball(80, Vector2f(100, 280));
	mass_b[3] = Ball(80, Vector2f(350, 350));
	while (win.isOpen()) {
		Event ev;
		win.clear();
		while (win.pollEvent(ev)) {
			switch (ev.type)
			{
			case Event::Closed:
				win.close();
				break;
			default:
				break;
			}
		}
		if (Keyboard::isKeyPressed(Keyboard::Up)) {
			for (int i = 0; i < 4; i++) {
				mass_b[i].ball_move(1);
			}
		}
		if (Keyboard::isKeyPressed(Keyboard::Y)) {
			for (int i = 0; i < 4; i++) {
				mass_b[i].setCol(Color::Yellow);
			}
		}

		for (int i = 0; i < 4; i++) {
			win.draw(mass_b[i]);
		}
		//win.draw(b1);
		//win.draw(b2);
		//win.draw(b3);
		//win.draw(b4);
		win.display();

	}


	return EXIT_SUCCESS;
}


