#include <iostream>
#include <SFML/Graphics.hpp>
#include <time.h>
#include "Obstacle.hpp"

class Parallax : public sf::Drawable{
	private:
		int last;
		int score;
		bool initiated;
		sf::Texture obsT;
		sf::Texture baseT;
		std::vector<sf::Sprite> bases;
		std::vector<Obstacle> obstacles;
	public:
		Parallax();
		void Update();
		bool Collision(sf::IntRect);
		void Initiated();
		int Score();
		virtual void draw(sf::RenderTarget&, sf::RenderStates) const;
		
};
