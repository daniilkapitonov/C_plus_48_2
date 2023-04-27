
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <cmath>
#include <ctime>
#include <cstdlib>
using namespace sf;

class Ball : public CircleShape {
public:
	double speed = 0.05;
	Color defcol;
	Ball (){}
	Ball(int d, Vector2f pos, Color col = Color::Red):CircleShape(d){
		this->setFillColor(col);
		this->setOrigin(Vector2f(this->getRadius(), this->getRadius()));
		this->setPosition(pos);
		this->defcol = col;
	}
	void setCol(Color col) {
		this->setFillColor(col);
	}
	void resetCol() {
		this->setCol(this->defcol);
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
	const int n = 2;
	Ball* mass_b = new Ball[n];
	mass_b[0] = Ball(80, Vector2f(100, 100),Color::Green);
	mass_b[1] = Ball(80, Vector2f(280, 100), Color::Red);

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
			mass_b[0].ball_move(1);
		}
		if (Keyboard::isKeyPressed(Keyboard::Down)) {
			mass_b[0].ball_move(2);
		}
		if (Keyboard::isKeyPressed(Keyboard::Right)) {
			mass_b[0].ball_move(3);
		}
		if (Keyboard::isKeyPressed(Keyboard::Left)) {
			mass_b[0].ball_move(4);
		}
		if (Keyboard::isKeyPressed(Keyboard::W)) {
			mass_b[1].ball_move(1);
		}
		if (Keyboard::isKeyPressed(Keyboard::S)) {
			mass_b[1].ball_move(2);
		}
		if (Keyboard::isKeyPressed(Keyboard::D)) {
			mass_b[1].ball_move(3);
		}
		if (Keyboard::isKeyPressed(Keyboard::A)) {
			mass_b[1].ball_move(4);
		}
		int x1_0,x2_0, x1_1, x2_1;
		int y1_0, y2_0, y1_1, y2_1;
		x1_0 = mass_b[0].getPosition().x - mass_b[0].getRadius();
		x2_0 = mass_b[0].getPosition().x + mass_b[0].getRadius();
		y1_0 = mass_b[0].getPosition().y - mass_b[0].getRadius();
		y2_0 = mass_b[0].getPosition().y + mass_b[0].getRadius();

		x1_1 = mass_b[1].getPosition().x - mass_b[1].getRadius();
		x2_1 = mass_b[1].getPosition().x + mass_b[1].getRadius();
		y1_1 = mass_b[1].getPosition().y - mass_b[1].getRadius();
		y2_1 = mass_b[1].getPosition().y + mass_b[1].getRadius();
		
		/*if (not(x1_0 > x2_1 or x2_0 < x1_1) and not(y1_0 > y2_1 or y2_0 < y1_1)) {
			for (int i = 0; i < n; i++) {
				mass_b[i].setCol(Color::Yellow); //Проверка с помощью координат
			}
		}
		else {
			for (int i = 0; i < n; i++) {
				mass_b[i].resetCol();
			}
		}*/

		if (mass_b[0].getGlobalBounds().intersects(mass_b[1].getGlobalBounds())) {
			for (int i = 0; i < n; i++) {
				mass_b[i].setCol(Color::Blue);
			}
		}
		else {
			for (int i = 0; i < n; i++) {
				mass_b[i].resetCol();
			}
		}

		for (int i = 0; i < n; i++) {
			win.draw(mass_b[i]);
		}
		win.display();

	}


	return EXIT_SUCCESS;
}


