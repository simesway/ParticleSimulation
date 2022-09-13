#ifndef PARTICLE_SYSTEM_HPP
#define PARTICLE_SYSTEM_HPP

#include "ParticleSet.hpp"
#include "Color.hpp"

class ParticleSystem{
public:
	std::vector<ParticleSet> sets;
	int pWidth;
	int pHeight;
  
	float gValues[4][4];

	float effectDistance = 100;

private:
	sf::RenderTexture texture;
	sf::Sprite sprite;
	sf::Vector2f position{0,0};
	Color color;

public:
	ParticleSystem(int width, int height);

	void setPosition(int, int);

	void setup();

	void reset();

	void reset(int i);

	void OnOff(int i);

	void randomizeG(float min, float max);

	void setZero();

	void calculate(ParticleSet &, const ParticleSet &, float g, float distance);

	void update();

	void draw(sf::RenderTarget &target, bool start, bool clear);
};

#endif
