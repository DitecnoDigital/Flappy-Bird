#include <iostream>
#include <SFML/Graphics.hpp>

class Bird : public sf::Drawable {
	private:
		bool initiated;
		bool live;
		int state;
		int timerState;
		std::vector<sf::Texture> states;
		sf::Sprite sprite;
		float move;
	public:
		Bird(int,int);
		void Update();
		void Jump();
		void Death();
		bool GetLive();
		sf::Vector2f GetPosition();
		void Initiated();
		virtual void draw(sf::RenderTarget &,sf::RenderStates) const;
};
