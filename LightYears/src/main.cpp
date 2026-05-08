#include <iostream>
#include <SFML/Graphics.hpp>

int main() {
	std::cout << "Hello World" << std::endl;

	sf::RenderWindow renderWindow{ sf::VideoMode({200, 200}), "My Window" };
	return 0;
}