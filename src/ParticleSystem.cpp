#include "ParticleSystem.hpp"

ParticleSystem::ParticleSystem(int width, int height): pWidth(width), pHeight(height){
	texture.create(pWidth, pHeight);
	randomizeG(-3,3);
}

void ParticleSystem::setPosition(int x, int y){
	position = sf::Vector2f(x,y);
	sprite.setPosition(position);
}

void ParticleSystem::setup(){
	sets.clear();

	sets.push_back(ParticleSet(color.red,200, pWidth, pHeight));
	sets.push_back(ParticleSet(color.blue,200, pWidth, pHeight));
	sets.push_back(ParticleSet(color.green,200, pWidth, pHeight));
	sets.push_back(ParticleSet(color.yellow,200, pWidth, pHeight));

	for(int i=0; i<sets.size(); i++){
		sets[i].setBorder(0,0, pWidth, pHeight);
	}
}

void ParticleSystem::reset(){
	texture.clear(color.background);
	for(int i=0; i<sets.size(); ++i)
		sets[i].reset();
}

void ParticleSystem::reset(int i){
	sets[i].reset();
}

void ParticleSystem::OnOff(int i){
	sets[i].active = sets[i].active ? false : true;
	reset(i);
}

void ParticleSystem::randomizeG(float min=-5, float max=5){
	int delta = max - min;
	for(int i=0; i<4; ++i){
		for(int j=0; j<4; ++j){
			gValues[i][j] = min + (std::rand() / (RAND_MAX / (max - min)));
		}
	}
}

void ParticleSystem::setZero(){
	for(int i=0; i<4; ++i){
		for(int j=0; j<4; ++j){
			gValues[i][j] = 0;
		}
	}
}

void ParticleSystem::calculate(ParticleSet &set1, const ParticleSet &set2, float g, float distance){
	g *= -1;
	if(!set1.active || !set2.active || (g == 0))
		return;
	
	for(int i = 0; i < set1.particles.size(); i++){
		float fx = 0;
		float fy = 0;
		for(int j = 0; j < set2.particles.size(); j++){
			auto &a = set1.particles[i];
			auto &b = set2.particles[j];
			float dx = a.x - b.x;
			float dy = a.y - b.y;
			float d = std::sqrt(dx*dx + dy*dy);
			if(d>0 && d<distance){
				float F = g * 1/d;
				fx += (F * dx);
				fy += (F * dy);
			}
		}

		auto &point = set1.particles[i];
		int r = set1.pRadius;
		point.vx = (point.vx + fx)*0.5;
		point.vy = (point.vy + fy)*0.5;
		
		if((point.x + point.vx < set1.localBorder.xmin+r) || 
		   (point.x + point.vx > set1.localBorder.xmax-r)) 
			point.vx *= -1;
		if((point.y + point.vy < set1.localBorder.ymin+r) ||
		   (point.y + point.vy > set1.localBorder.ymax-r)) 
			point.vy *= -1;

		point.x += point.vx;
		point.y += point.vy;
	}
}

void ParticleSystem::update(){
	for(int i=0; i<sets.size(); i++){
		for(int j=0; j<sets.size(); j++){
			calculate(sets[i], sets[j], gValues[i][j], effectDistance);
		}
	}
}

void ParticleSystem::draw(sf::RenderTarget &target, bool start, bool clear = true){
	sf::RectangleShape rect(sf::Vector2f(pWidth,pHeight));
	rect.setFillColor(sf::Color(0x0f,0x0f,0x0f,16));
	if(clear) texture.clear(color.background);
	else if(!clear || start)texture.draw(rect);

	for(int i=0; i<sets.size(); i++){
		if(sets[i].active)
			sets[i].draw(texture);
	}

	texture.display();
	sprite.setTexture(texture.getTexture());
	target.draw(sprite);
}
