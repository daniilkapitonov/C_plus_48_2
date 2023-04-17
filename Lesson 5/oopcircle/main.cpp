
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <cmath>
#include <ctime>
#include <cstdlib>
using namespace sf;

class Ball : public CircleShape {
public:
	double speed = 0.06;
	bool check;
	Color base_col;
	Ball (){}
	Ball(int d, Vector2f pos, Color col = Color::Red):CircleShape(d){
		this->setFillColor(col);
		this->setOrigin(Vector2f(this->getRadius(), this->getRadius()));
		this->setPosition(pos);
		this->check = false;
		this->base_col = col;
	}
	void setCol(Color col) {
		this->setFillColor(col);
		this->check = true;
	}
	void cancel_sel() {
		this->setFillColor(this->base_col);
		this->check = false;
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
	const int n = 10;
	RenderWindow win(VideoMode(1500, 900), "OOP CIRCLE");
	Ball* mass_b = new Ball[n];
	for (int i = 0; i < n; i++) {
		mass_b[i] = Ball(60, Vector2f(rand() % 1500 + 1, rand() % 900 + 1), Color::Blue);
	}

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
		if (Keyboard::isKeyPressed(Keyboard::Num1)) {
			mass_b[0].setCol(Color::White);
		}
		if (Keyboard::isKeyPressed(Keyboard::Num2)) {
			mass_b[1].setCol(Color::White);
		}
		if (Keyboard::isKeyPressed(Keyboard::Num3)) {
			mass_b[2].setCol(Color::White);
		}
		if (Keyboard::isKeyPressed(Keyboard::Num4)) {
			mass_b[3].setCol(Color::White);
		}
		if (Keyboard::isKeyPressed(Keyboard::Num5)) {
			mass_b[4].setCol(Color::White);
		}
		if (Keyboard::isKeyPressed(Keyboard::Num6)) {
			mass_b[5].setCol(Color::White);
		}
		if (Keyboard::isKeyPressed(Keyboard::Num7)) {
			mass_b[6].setCol(Color::White);
		}
		if (Keyboard::isKeyPressed(Keyboard::Num8)) {
			mass_b[7].setCol(Color::White);
		}
		if (Keyboard::isKeyPressed(Keyboard::Num9)) {
			mass_b[8].setCol(Color::White);
		}
		if (Keyboard::isKeyPressed(Keyboard::Num0)) {
			mass_b[9].setCol(Color::White);
		}
		if (Keyboard::isKeyPressed(Keyboard::E)) {
			for (int i = 0; i < n; i++) {
				if (mass_b[i].check) {
					mass_b[i].cancel_sel();
				}
			}
		}
		if (Keyboard::isKeyPressed(Keyboard::Up)) {
			for (int i = 0; i < n; i++) {
				if (mass_b[i].check) {
					mass_b[i].ball_move(1);
				}
			}
		}
		if (Keyboard::isKeyPressed(Keyboard::Down)) {
			for (int i = 0; i < n; i++) {
				if (mass_b[i].check) {
					mass_b[i].ball_move(2);
				}
			}
		}
		if (Keyboard::isKeyPressed(Keyboard::Left)) {
			for (int i = 0; i < n; i++) {
				if (mass_b[i].check) {
					mass_b[i].ball_move(4);
				}
			}
		}
		if (Keyboard::isKeyPressed(Keyboard::Right)) {
			for (int i = 0; i < n; i++) {
				if (mass_b[i].check) {
					mass_b[i].ball_move(3);
				}
			}
		}

		for (int i = 0; i < n; i++) {
			win.draw(mass_b[i]);
		}


		win.display();

	}


	return EXIT_SUCCESS;
}


