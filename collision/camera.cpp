#include "camera.hpp"

camera::camera(blok & Unicorn):
		Unicorn(Unicorn)
{
	
}


void camera::follow(sf::RenderWindow &window) {
	sf::View playerCam(sf::FloatRect(0, 0, (Unicorn.GetSize().x) * 4, (Unicorn.GetSize().y) * 4));
	sf::Vector2f a = Unicorn.GetMiddle();
	sf::Vector2f b(a.x, a.y);
	playerCam.setCenter(b);
	window.setView(playerCam);
}