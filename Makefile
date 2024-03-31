all:
	g++ main.cpp Bird.cpp Obstacle.cpp Parallax.cpp UISound.cpp -lsfml-graphics -lsfml-system -lsfml-window -lsfml-audio -o Game
