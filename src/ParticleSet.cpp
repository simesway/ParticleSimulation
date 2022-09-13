#include "ParticleSet.hpp"

Particle::Particle(int x, int y) : x(x), y(y){}

ParticleSet::ParticleSet(const sf::Color &col, int num, int width, int height):
	color(col), number(num){
	localBorder.xmin = 0;
	localBorder.xmax = 0;
	localBorder.xmax = width;
	localBorder.ymax = height;
	for(int i=0; i<num; i++){
			Particle newParticle(std::rand() % localBorder.xmax, 
								 std::rand() % localBorder.ymax);
			particlesDefault.push_back(newParticle);
	}
	particles = particlesDefault;
}

void ParticleSet::setOrigin(int x, const int y, int width, int height){
	originBorder.xmin = x;
	originBorder.ymin = y;
	originBorder.xmax = x + width;
	originBorder.ymax = y + height;

	if(!particlesDefault.empty()){
		particlesDefault.clear();
		addParticles(number, 2000);
	}
	origin = true;
}

void ParticleSet::setBorder(int x, int y,int width, int height){
	localBorder.xmin = x;
	localBorder.ymin = y;
	localBorder.xmax = x + width;
	localBorder.ymax = y + height;

	if(!particlesDefault.empty()){
		particlesDefault.clear();
		addParticles(number, 2000);
	}
	border = true;
	if(!origin)
		OriginIsBorder(true);
}

void ParticleSet::OriginIsBorder(const bool &is){
	if(is){
		originIsBorder = true;
		originBorder = localBorder;
	}
	else
		originIsBorder = false;
}

void ParticleSet::removeParticles(const int &num){
	if(num > number) 
		return;
	particles.erase(particles.end()-num, particles.end());
	particlesDefault.erase(particlesDefault.end()-num, particlesDefault.end());

	number = particlesDefault.size();
}

void ParticleSet::addParticles(int num, const int &maxParticles){
	if(num + number > maxParticles) 
		num = maxParticles - number;

	for(int i=0; i<num; i++){
		Particle newParticle(
				std::rand() % (originBorder.xmax-originBorder.xmin) + originBorder.xmin, 
				std::rand() % (originBorder.ymax-originBorder.ymin) + originBorder.ymin
		);
		particlesDefault.push_back(newParticle);
		particles.push_back(newParticle);
	}
	number = particlesDefault.size();
}

void ParticleSet::clear(){ 
	particles.clear(); 
	particlesDefault.clear();
}

void ParticleSet::reset(){
	particles = particlesDefault;
}

void ParticleSet::draw(sf::RenderTarget &texture){
    sf::CircleShape shape(pRadius,10);
	shape.setOrigin(2,2);
	shape.setFillColor(color);

	for(int i = 0; i < particles.size(); i++){
		shape.setPosition(particles[i].x, particles[i].y);
		texture.draw(shape);
	}

}

void ParticleSet::drawPoints(sf::RenderTarget &target){
	sf::Vertex points[number];
	for(int i=0; i<number; ++i){
		points[i].position.x = particles[i].x;
		points[i].position.y = particles[i].y;
		points[i].color = color;
	}
	target.draw(points, number, sf::Points);
}
