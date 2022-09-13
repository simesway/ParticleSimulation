#ifndef MENU_ELEMENTS_HPP
#define MENU_ELEMENTS_HPP

#include <SFML/Graphics.hpp>
#include <string>
#include <cmath>
#include <string>
#include "Color.hpp"
#include "State.hpp"
#include "Interval.hpp"


class Slide{
private:
	sf::Vector2f position;
	sf::Vector2f size{390.f,10.f};

	bool isMoving = false;

	Interval<float> v;
	Interval<int> x;

	float &value;

public:
	Slide(int posX, int posY, float &value, float start, float stop);

	void setPosition(int x, int y);

	bool contains(const sf::Vector2f &point);

	void update();

	void draw(sf::RenderTarget &target);

	void onMousePressed(const sf::Event &event, const sf::Vector2f &mouse);

	void onMouseMoved(const sf::Vector2f &mouse);

	void onMouseReleased(const sf::Vector2f &mouse);

private:
	void updateText(sf::RenderTarget &target);

	void updateHandle(float newVal);

	void updateValue(float newX);

	sf::RectangleShape box;
	sf::Vertex progression[4];

	float xval;
	float vzero;
	int xzero;
	
	sf::Font font;
	int cv = 150;
};

class StateMachine{
private:
	
	sf::Vector2f position;
	
public:

};

#endif
