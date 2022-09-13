#include "MenuElements.hpp"
#include "UtilityFunctions.hpp"

Slide::Slide(int posX, int posY, float &value, float start = 0, float stop = 100):
	position(sf::Vector2f(posX, posY)), value(value)
{

	v.start = start; 
	v.stop  = stop;
	x.start = position.x;
	x.stop  = position.x + size.x;
	if(v.contains(0)) 
		vzero = 0;
	else
		vzero = v.min();
	xzero = intervalMap(vzero, v.start, v.stop,
						 x.start, x.stop);

	box.setSize(size);
	box.setPosition(sf::Vector2f(position.x, position.y));
	box.setFillColor(sf::Color(70,70,70));
	box.setOutlineColor(sf::Color(70,70,70));
	box.setOutlineThickness(1);


	for(int i=0; i<4; ++i){
		progression[i].color = sf::Color(cv,cv,cv);
		progression[i].position.x = xzero;
		progression[i].position.y = position.y;
	}
	progression[1].position.y = position.y + size.y;
	progression[2].position.y = position.y + size.y;
	
	font.loadFromFile("./src/files/times.ttf");
	xval = intervalMap(value, v.start, v.stop, x.start, x.stop);
			
}

void Slide::setPosition(int x, int y){
	position = sf::Vector2f(x,y);
}

void Slide::draw(sf::RenderTarget &target){
	update();
	updateText(target);
	target.draw(box);
	target.draw(progression, 4, sf::Quads);

	sf::RectangleShape handle(sf::Vector2f(2,size.y+6));
	handle.setPosition(xval-1, position.y-3);
	target.draw(handle);
}

bool Slide::contains(const sf::Vector2f &point){
	return box.getGlobalBounds().contains(point);
}

void Slide::onMousePressed(const sf::Event &event, const sf::Vector2f &mouse){
	if(event.mouseButton.button == sf::Mouse::Left){
		isMoving = true;
		updateValue(mouse.x);
	}
	if(event.mouseButton.button == sf::Mouse::Right)
		updateHandle(0);
}


void Slide::onMouseMoved(const sf::Vector2f &mouse){
	if(!isMoving)
		return;
	updateValue(mouse.x);
}

void Slide::onMouseReleased(const sf::Vector2f &mouse){
	if(!isMoving)
		return;
	updateValue(mouse.x);
	isMoving = false;
}

void Slide::updateText(sf::RenderTarget &target){
	sf::Text text;
	text.setFont(font);
	std::string number = float_to_str(value, 2);
	text.setString(number);
	text.setCharacterSize(size.y+7);

	int id = number.find(".");

	text.setOrigin(text.findCharacterPos(id));

	text.setPosition(position.x + size.x + 30, position.y - 6);
	target.draw(text);

}

void Slide::updateHandle(float newVal){
	value = newVal;
	if(newVal > v.max()) 
		xval = x.max();
	else if (newVal < v.min()) 
		xval = x.min();
	else 
		xval = intervalMap(value, v.start, v.stop, x.start, x.stop);
}

void Slide::updateValue(float newX){
	if(newX > x.stop)
		value = v.stop;
	else if (newX < x.min()) 
		value = v.start;
	else 
		value = intervalMap(newX, x.start, x.stop, v.start, v.stop);;
}

void Slide::update(){
	xval = intervalMap(value, v.start, v.stop, x.start, x.stop);
	progression[2].position.x = xval;
	progression[3].position.x = xval;

	float max = (value > vzero) ? v.max() : v.min();
	max = std::abs(max);
}
