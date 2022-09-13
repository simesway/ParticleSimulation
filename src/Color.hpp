#ifndef COLOR
#define COLOR

#include <SFML/Graphics.hpp>

struct Color{
	sf::Color red{0xe1,0x18,0x45};
	sf::Color blue{0x00,0x57,0xe9};
	sf::Color green{0x87,0xe9,0x11};
	sf::Color yellow{0xf2,0xca,0x19};
	sf::Color background{0x0f,0x0f,0x0f};
	
	std::vector<sf::Color> vec;

	Color(){
		vec.push_back(red);
		vec.push_back(blue);
		vec.push_back(green);
		vec.push_back(yellow);
	}
};

#endif
