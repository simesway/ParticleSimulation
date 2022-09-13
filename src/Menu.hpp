#ifndef MENU_WINDOW
#define MENU_WINDOW

#include <SFML/Graphics.hpp>
#include <string>
#include "MenuElements.hpp"
#include "Color.hpp"
#include "State.hpp"

class MenuWindow{
private:
	sf::RenderTexture texture;
	sf::Sprite sprite;
	sf::Vector2f position{0,0};
	Color color;

	std::vector<Slide> slides;

public:
	MenuWindow(int width, int height);

	void setup(float gValues[4][4], float &distance);

	void setPosition(int, int);

	void draw(sf::RenderTarget &);

	void handleEvent(const sf::Event &);

private:
	void drawBoxes(sf::RenderTarget &);

	sf::Vector2f convertMousePosition(int, int);
};

#endif
