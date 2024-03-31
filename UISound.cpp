#include "UISound.hpp"

UISound::UISound(){
	initiated = false;
	gameOver = false;
	
	if(!font.loadFromFile("resources/font/font.ttf")){
		std::cout<<"Error al cargar la fuente resources/font/font.ttf"<<'\n';
	}
	
	if(!gameOverT.loadFromFile("resources/sprites/gameover.png")){
		std::cout<<"Error al cargar la textura resources/sprites/gameover.png"<<'\n';
	}
	
	if(!initT.loadFromFile("resources/sprites/message.png")){
		std::cout<<"Error al cargar la textura resources/sprites/message.png"<<'\n';
	}
	
	if(!pointB.loadFromFile("resources/sounds/point.ogg")){
		std::cout<<"Error al cargar el sonido resources/sounds/point.ogg"<<'\n';
	}
	
	if(!wingB.loadFromFile("resources/sounds/wing.ogg")){
		std::cout<<"Error al cargar el sonido resources/sounds/wing.ogg"<<'\n';
	}
	
	if(!hitB.loadFromFile("resources/sounds/hit.ogg")){
		std::cout<<"Error al cargar el sonido resources/sounds/hit.ogg"<<'\n';
	}
	
	music.openFromFile("resources/sounds/music.ogg");
	music.setLoop(true);
	music.play();
	
	point.setBuffer(pointB);
	wing.setBuffer(wingB);
	hit.setBuffer(hitB);
	
	score=0;
	scoreT.setFont(font);
	scoreT.setCharacterSize(40);
	scoreT.setString(std::to_string(score));
	scoreT.setOrigin(scoreT.getGlobalBounds().width/2,scoreT.getGlobalBounds().height/2);
	scoreT.setPosition(210,50);
	
	std::ifstream in("score");
	in>>maxScore;
	
	maxScoreT.setFont(font);
	maxScoreT.setCharacterSize(20);
	maxScoreT.setString(std::to_string(maxScore));
	maxScoreT.setOrigin(maxScoreT.getGlobalBounds().width/2,maxScoreT.getGlobalBounds().height/2);	
	maxScoreT.setPosition(210,100);
	
	gameOverS.setTexture(gameOverT);
	gameOverS.setOrigin(gameOverT.getSize().x/2,gameOverT.getSize().y/2);
	gameOverS.setScale(2,2);
	gameOverS.setPosition(210,350);
	
	initS.setTexture(initT);
	initS.setOrigin(initT.getSize().x/2,initT.getSize().y/2);
	initS.setScale(1.5f,1.5f);
	initS.setPosition(210,280);	
}

void UISound::SetScore(int val){
	if(score!=val) point.play();
	score=val;
	scoreT.setString(std::to_string(score));
	scoreT.setOrigin(scoreT.getGlobalBounds().width/2,scoreT.getGlobalBounds().height/2);
}

void UISound::Initiated(bool state){
	initiated=state;
	score=0;
	gameOver=false;
	std::ifstream in("score");
	in>>maxScore;
	maxScoreT.setString(std::to_string(maxScore));
	maxScoreT.setOrigin(maxScoreT.getGlobalBounds().width/2,maxScoreT.getGlobalBounds().height/2);	
	scoreT.setString(std::to_string(score));
	scoreT.setOrigin(scoreT.getGlobalBounds().width/2,scoreT.getGlobalBounds().height/2);
}

void UISound::Wing(){
	wing.play();
}

void UISound::GameOver(){
	if(!gameOver) hit.play();
	if(score>maxScore){
		maxScore=score;
		std::ofstream out("score");
		out<<score;
	}
	gameOver=true;
}

void UISound::draw(sf::RenderTarget &rt, sf::RenderStates rs) const{
	if(!initiated) rt.draw(initS,rs);
	else{
		rt.draw(scoreT,rs);
		rt.draw(maxScoreT,rs);
		if(gameOver) rt.draw(gameOverS,rs);
	}
}
