
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <iostream>
using namespace sf;
using namespace std;

class Planet : public CircleShape {
public:
	Vector2f pos;
	float orbitraduis;
	float angVel;
	float curAng;
	friend class Engine;
	Planet(Vector2f pos, float orbitraduis, float radius, float angVel, string fname) {
		this->orbitraduis = orbitraduis;
		this->pos = pos;
		this->angVel = angVel;
		this->setRadius(radius);
		this->setPosition(pos);
		this->setOrigin(this->getRadius(), this->getRadius());
		this->curAng = 0;
	}
	void setAngulaerVel(float angVel) {
		this->angVel = angVel;
	}
	
};

class SolarSystem {
public:
	friend class Engine;
	vector<Planet> planets;

	SolarSystem() = default;
	SolarSystem(vector<Planet> planets) {
		this->planets = planets;
	}
	void add_planet(Planet planet) {
		this->planets.push_back(planet);
	}
	~SolarSystem() {
		this->planets.clear();
	}
};

class Engine {
public:
	const float gameZoom = 1.02f;
	Clock dCl;
	Time dt;
	ContextSettings sett;
	RenderWindow* window;
	View* view;
	Event event;
	SolarSystem Sun;
	Engine(unsigned width, unsigned height, string win_name) {
		this->view = new View(FloatRect(0, 0, width * 2, height * 2));
		this->window = new RenderWindow(VideoMode(width, height), win_name, Style::Default, sett);
		this->view->setCenter(width / 2, height / 2);
		this->view->zoom(-100);
		this->window->setView(*this->view);
	}
	void setSolarSys(SolarSystem sol) {
		this->Sun = sol;
	}

	~Engine() {
		delete this->window;
		delete this->view;
	}

	void run() {
		while (this->window->isOpen()) {
			Event event;
			while (this->window->pollEvent(event)) {
				switch (event.type)
				{
				case Event::MouseWheelMoved:
					if (event.mouseWheel.delta == 1) {
						this->view->zoom(1.0f / this->gameZoom);
						this->window->setView(*this->view);
					}
					if (event.mouseWheel.delta == -1) {
						this->view->zoom(this->gameZoom);
						this->window->setView(*this->view);
					}
					break;
				case Event::Closed:
					this->window->close();
					break;
				default:
					break;
				}
			}
			if (Keyboard::isKeyPressed(Keyboard::Escape)) {
				this->window->close();
			}
			if (Keyboard::isKeyPressed(Keyboard::W)) {
				this->view->move(0, 100);
				this->window->setView(*this->view);
			}
			if (Keyboard::isKeyPressed(Keyboard::A)) {
				this->view->move(100, 0);
				this->window->setView(*this->view);
			}
			if (Keyboard::isKeyPressed(Keyboard::S)) {
				this->view->move(0, -100);
				this->window->setView(*this->view);
			}
			if (Keyboard::isKeyPressed(Keyboard::D)) {
				this->view->move(-100, 0);
				this->window->setView(*this->view);
			}
		
			this->window->clear();
			for (int i = 0; i < this->Sun.planets.size(); i++) {
				this->Sun.planets[i].curAng += this->Sun.planets[i].angVel * dt.asSeconds();
				cout << this->Sun.planets[i].curAng <<" "<< dt.asSeconds() << endl;

				this->Sun.planets[i].setPosition(
					this->Sun.planets[i].pos.x + this->Sun.planets[i].orbitraduis * cos(this->Sun.planets[i].curAng),
					this->Sun.planets[i].pos.y + this->Sun.planets[i].orbitraduis * sin(this->Sun.planets[i].curAng)
				);
				this->window->draw(this->Sun.planets[i]);
			}
			this->window->display();
			dt = dCl.restart();
		}
	}
};

#define SUN 1000.0;
#define MERCURY 100;
#define VENUS 150;
#define EARTH 300;
#define MARS 270;
#define JUPITER 700;
#define SATURN 700;
#define URANUS 900;
#define NEPTUNE 900;




int main()
{
	const unsigned size_w = 1920;
	const unsigned size_h = 1080;

	const unsigned cen_w = size_w/2;
	const unsigned cen_h = size_h/2;

	Engine* engine = new Engine(size_w, size_h, "SolarSys_C++");
	SolarSystem Sun_sys;

	Planet sun(Vector2f(cen_w, cen_h), 0.0, 1000.0 , 0.0, "def");
	Planet mercury(Vector2f(cen_w, cen_h), 1700.0, 100, 2.5, "def");
	Planet venus(Vector2f(cen_w, cen_h), 10600.0, 150, 1.25, "def");
	Planet earth(Vector2f(cen_w, cen_h), 15500, 300, 0.7, "def");
	Planet mars(Vector2f(cen_w, cen_h), 22500, 270, 1, "def");
	Planet jupiter(Vector2f(cen_w, cen_h), 25500, 700, 0.5, "def");
	Planet saturn(Vector2f(cen_w, cen_h),30500, 700, 0.7, "def");
	Planet uranus(Vector2f(cen_w, cen_h), 40500,
		900, 0.3, "def");
	Planet neptune(Vector2f(cen_w, cen_h), 47000,
		900, 0.2, "def");
	Sun_sys.add_planet(sun);
	Sun_sys.add_planet(mercury);
	Sun_sys.add_planet(venus);
	Sun_sys.add_planet(earth);
	Sun_sys.add_planet(mars);
	Sun_sys.add_planet(jupiter);
	Sun_sys.add_planet(saturn);
	Sun_sys.add_planet(uranus);
	Sun_sys.add_planet(neptune);
	engine->setSolarSys(Sun_sys);
	engine->run();



	
	return EXIT_SUCCESS;
}


