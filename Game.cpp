#include <SFML/Graphics.hpp>

#include "const.h"
#include "Game.h"

Game::Game(): window(sf::VideoMode(N*ts,M*ts),"Xonix Game!"), 
player(100.f,100.f), window_borders(sf::Vector2f(WINDOW_WIDTH-35, WINDOW_HEIGHT-35))
{
	window.setFramerateLimit(60);
	window_borders.setPosition(20,20);
	window_borders.setOutlineColor(sf::Color::Yellow);
	window_borders.setFillColor(sf::Color::Black);
	window_borders.setOutlineThickness(35);
}

void Game::play(){
	while (window.isOpen()) {
		check_event();
		update();
		draw();
		
	}
}
void Game::check_event(){

	sf::Event event;
	while (window.pollEvent(event)) {
		if (event.type == sf::Event::Closed) {

			window.close();
		}
	}
}
void Game::update(){
	player.update();
}
void Game::draw(){
	window.clear();
	window.draw(window_borders);
	player.draw(window);
	window.display();
	

}

