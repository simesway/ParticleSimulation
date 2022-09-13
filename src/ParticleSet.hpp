#ifndef PARTICLE_SET_HPP
#define PARTICLE_SET_HPP

#include <vector>
#include <SFML/Graphics.hpp>
#include <cstdlib>
#include <cmath>

struct Border{
	int xmin = 0;
	int ymin = 0;
	int xmax = 1000;
	int ymax = 1000;
};

class Particle{
public:
	float  x = 0;
	float  y = 0;
	float vx = 0;
	float vy = 0;

	Particle(int x, int y);
};

class ParticleSet{
public:
	sf::Color color;
	int number;
	bool active = true;

	std::vector<Particle> particles;
	std::vector<Particle> particlesDefault;

	Border localBorder;

	int pRadius = 3;

private:

	bool border = false;
	Border originBorder;
	bool origin = false;
	bool originIsBorder = true;

public:
	ParticleSet(const sf::Color &col, int num, int width, int height);

	void isActive(const bool &);

	void setOrigin(int, int, int, int);

	void setBorder(int, int, int, int);

	void OriginIsBorder(const bool &);

	void removeParticles(const int &num);

	void addParticles(int num, const int &);

	void clear();

	void reset();

	void draw(sf::RenderTarget &);

	void drawPoints(sf::RenderTarget &);
};

#endif 
