#include "Bird.hpp"

Bird::Bird(int x, int y){
	initiated=false;
	live=true;
	state=0;
	timerState=10;
	states.resize(3);
	if(!states[0].loadFromFile("resources/sprites/birdupflap.png")){
		std::cout<<"Error al cargar la textura resources/sprites/birdupflap.png"<<'\n';
	}
	if(!states[1].loadFromFile("resources/sprites/birdmidflap.png")){
		std::cout<<"Error al cargar la textura resources/sprites/birdmidflap.png"<<'\n';
	}
	if(!states[2].loadFromFile("resources/sprites/birddownflap.png")){
		std::cout<<"Error al cargar la textura resources/sprites/birddownflap.png"<<'\n';
	}
	sprite.setTexture(states[state]);
	sprite.setOrigin(states[state].getSize().x/2,states[state].getSize().y/2);
	sprite.setPosition(x,y);
	sprite.setScale(2,2);
	move=0;
	
}

void Bird::Update(){
	
	if(!live){
		if(sprite.getPosition().y<700-136){
			sprite.move(0,12);
			sprite.setRotation(sprite.getRotation()+10);
		}
		return;
	}
	
	timerState--;
	if(timerState==0){
		state++;
		state%=(int)states.size();
		sprite.setTexture(states[state]);
		sprite.setOrigin(states[state].getSize().x/2,states[state].getSize().y/2);
		timerState=10;
	}
	
	if(!initiated) return;
	
	sprite.move(0,move);
	move+=0.5f;
	
	if(move>8&&move<15) sprite.setRotation(sprite.getRotation()+4);
	
}

void Bird::Jump(){
	move=-8;
	sprite.setRotation(-15);
}

sf::Vector2f Bird::GetPosition(){
	return sprite.getPosition();
}

bool Bird::GetLive(){
	return live;
}

void Bird::Death(){
	live=false;
}

void Bird::Initiated(){
	initiated=true;
}

void Bird::draw(sf::RenderTarget &rt, sf::RenderStates rs) const{
	rt.draw(sprite,rs);
}




