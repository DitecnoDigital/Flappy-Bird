#include <iostream>
#include <SFML/Graphics.hpp>
#include "Bird.hpp"
#include "Parallax.hpp"
#include "UISound.hpp"

int main(){
	
	sf::Texture backT;
	sf::Sprite back;
	
	if(!backT.loadFromFile("resources/sprites/background.png")){
		std::cout<<"Error al cargar la textura resources/sprites/background.png"<<'\n';
	}
	
	back.setTexture(backT);
	back.setPosition(0,-15);
	back.setScale(1.5f,1.5f);
	
	bool initiated;
	bool pressed;
	
	sf::RenderWindow window(sf::VideoMode(400,700),"Flappy Bird");
	window.setFramerateLimit(60);
	
	pressed=false;
	
	UISound uis;
	
	while(window.isOpen()){
		
		Bird *bird  = new Bird(210,350);
		Parallax *parallax = new Parallax();
		initiated=false;
		uis.Initiated(false);
		while(true){
			sf::Event event;
			while(window.pollEvent(event)){
				if(event.type==sf::Event::Closed){
					window.close();
					return 0;
				}
			}
			
			bird->Update();
			
			if(bird->GetLive()){
				parallax->Update();
				if(sf::Mouse::isButtonPressed(sf::Mouse::Left)&&!pressed){
					bird->Jump();
					pressed=true;
					uis.Wing();
					if(!initiated){
						initiated=true;
						bird->Initiated();
						parallax->Initiated();
						uis.Initiated(true);
					}
				}
			}else{
				uis.GameOver();
			}
			
			
			if(!bird->GetLive()&&sf::Mouse::isButtonPressed(sf::Mouse::Left)&&!pressed){
				//Reinicio
				pressed=true;
				break;
			}
			
			sf::IntRect rect(bird->GetPosition().x-23,bird->GetPosition().y-21,44,40);
			
			if(parallax->Collision(rect)){
				bird->Death();
			}
			
			if(bird->GetPosition().y<0||bird->GetPosition().y>700-136){
				bird->Death();
			}
			
			if(!sf::Mouse::isButtonPressed(sf::Mouse::Left)){
				pressed=false;
			}
			
			uis.SetScore(parallax->Score());
			
			window.clear();
			window.draw(back);
			window.draw(*parallax);
			window.draw(*bird);
			window.draw(uis);
			window.display();
		}
		delete bird;
		delete parallax;
	}
	return 0;
}
