#ifndef MAIN_WINDOW
#define MAIN_WINDOW

#include <SFML/Graphics.hpp>
#include "Menu.hpp"
#include "ParticleSystem.hpp"
#include "MenuElements.hpp"
#include "State.hpp"
#include "Color.hpp"

class MainWindow{
private:
	sf::RenderWindow window;
	std::string name = "particle simulation";

	int width = 1500;
	int height = 1000;

	ParticleSystem pSystem{960,960};

	MenuWindow menu{500,1000};


public:
	MainWindow();		

	void open();

private:
	void draw();

	void loopEvents();

private:
	sf::RenderTexture texture;
	sf::Sprite sprite;

	int bWidth, bw_max;
	int bHeight, bh_max;

	Color color;
	State state;
};

#endif 
