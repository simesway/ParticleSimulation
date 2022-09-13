#include "Menu.hpp"
#include "UtilityFunctions.hpp"

MenuWindow::MenuWindow(int width, int height){
	texture.create(width,height);
}

void MenuWindow::setup(float gValues[4][4], float &distance){
	int space = 10;
	for(int i=0; i<4; ++i){
		for(int j=0; j<4; ++j){
			slides.push_back(Slide(40, space, gValues[i][j], -5, 5));
			space += 40;
		}
	}
	space += 20;
	slides.push_back(Slide(40, space, distance, 0, 1000));
}

void MenuWindow::setPosition(int x, int y){
	position = sf::Vector2f(x,y);
	sprite.setPosition(position);
}

void MenuWindow::draw(sf::RenderTarget &target){
	texture.clear(color.background);
	for(int i=0; i<slides.size(); ++i){
		slides[i].draw(texture);
	}
	drawBoxes(texture);
	texture.display();
	sprite.setTexture(texture.getTexture());
	target.draw(sprite);
}

void MenuWindow::handleEvent(const sf::Event& event){
	switch(event.type){
		case sf::Event::MouseButtonPressed:
		{
			auto mouse = convertMousePosition(event.mouseButton.x, event.mouseButton.y);

			for(int i=0; i<slides.size(); ++i){
				if(slides[i].contains(mouse))
					slides[i].onMousePressed(event, mouse);
			}
			break;
		}

		case sf::Event::MouseButtonReleased:
		{
			auto mouse = convertMousePosition(event.mouseButton.x, event.mouseButton.y);

			for(int i=0; i<slides.size(); ++i)
				slides[i].onMouseReleased(mouse);
			break;
		}

		case sf::Event::MouseMoved:
		{
			auto mouse = convertMousePosition(event.mouseMove.x, event.mouseMove.y);

			for(int i=0; i<slides.size(); ++i)
				slides[i].onMouseMoved(mouse);
			break;
		}

	}
}

sf::Vector2f MenuWindow::convertMousePosition(int x, int y){
	return sf::Vector2f(x,y) - position;
}

void MenuWindow::drawBoxes(sf::RenderTarget &target){
	int space = 9;
	sf::RectangleShape box1(sf::Vector2f(12,12));
	sf::RectangleShape box2(sf::Vector2f(12,12));
	for(int i=0; i<4; ++i){
		for(int j=0; j<4; ++j){
			box1.setPosition(0,space);
			box2.setPosition(20,space);
			box1.setFillColor(color.vec[i]);
			box2.setFillColor(color.vec[j]);
			target.draw(box1);
			target.draw(box2);
			space += 40;
		}
	}
}
