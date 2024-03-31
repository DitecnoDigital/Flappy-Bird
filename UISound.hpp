#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <fstream>

class UISound : public  sf::Drawable{
	private:
		sf::SoundBuffer pointB;
		sf::SoundBuffer wingB;
		sf::SoundBuffer hitB;
		sf::Sound point;
		sf::Sound wing;
		sf::Sound hit;
		sf::Music music;
		sf::Font font;
		sf::Text maxScoreT;
		sf::Text scoreT;
		int maxScore;
		int score;
		bool initiated,gameOver;
		sf::Texture gameOverT;
		sf::Sprite gameOverS;
		sf::Texture initT;
		sf::Sprite initS;
	public:
		UISound();
		void SetScore(int);
		void Initiated(bool);
		void GameOver();
		void Wing();
		virtual void draw(sf::RenderTarget&,sf::RenderStates) const;			
};
