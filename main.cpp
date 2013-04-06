/*
 * main.cpp
 *
 *  Created on: Dec 8, 2012
 *      Author: Sean
 */

#include <SFML/Graphics.hpp>
#include <iostream>
#include <sstream>

int main()
{
	sf::RenderWindow win;
	win.create(sf::VideoMode(800, 600, 32), "SFML Gamepad Test");
	win.setFramerateLimit(60);
	sf::Event event;

	bool connected = sf::Joystick::isConnected(0);

	bool exit = false;
	bool hasX, hasY, hasZ, hasR, hasU, hasV = false;

	sf::Font font;
	font.loadFromFile("arial.ttf");
	sf::Text left("", font, 30);
	sf::Text right("", font, 30);
	right.setPosition(400, 0);

	while (!exit) {
		win.pollEvent(event);
		if (event.type == sf::Event::Closed) {
		   exit = true;
		}

		win.clear(sf::Color(0, 0, 0));

		if (sf::Joystick::isConnected(0)) {
			if (!connected) {
				std::cout << "Joystick 0 connected!" << std::endl;
				int buttonCount = sf::Joystick::getButtonCount(0);
				std::cout << "Joystick 0 has '" << buttonCount << "' buttons" << std::endl;
				connected = true;

				hasX = sf::Joystick::hasAxis(0, sf::Joystick::X);
				hasY = sf::Joystick::hasAxis(0, sf::Joystick::Y);
				hasZ = sf::Joystick::hasAxis(0, sf::Joystick::Z);
				hasR = sf::Joystick::hasAxis(0, sf::Joystick::R);
				hasU = sf::Joystick::hasAxis(0, sf::Joystick::U);
				hasV = sf::Joystick::hasAxis(0, sf::Joystick::V);
			}

			float x = hasX ? sf::Joystick::getAxisPosition(0, sf::Joystick::X) : 0.0f;
			float y = hasY ? sf::Joystick::getAxisPosition(0, sf::Joystick::Y) : 0.0f;
			float z = hasZ ? sf::Joystick::getAxisPosition(0, sf::Joystick::Z) : 0.0f;
			float r = hasR ? sf::Joystick::getAxisPosition(0, sf::Joystick::R) : 0.0f;
			float u = hasU ? sf::Joystick::getAxisPosition(0, sf::Joystick::U) : 0.0f;
			float v = hasV ? sf::Joystick::getAxisPosition(0, sf::Joystick::V) : 0.0f;

			std::ostringstream stream;
			stream << "Axis X: " << x << "\nAxis Y: " << y << "\nAxis Z: " << z;
			left.setString(stream.str());
			stream.seekp(0);
			stream << "Axis R: " << r << "\nAxis U: " << u << "\nAxis V: " << v;
			right.setString(stream.str());
			stream.seekp(0);

		} else {
			if (connected) {
				std::cout << "Joystick 0 disconnected :(" << std::endl;
				connected = false;
				hasX = hasY = hasZ = hasR = hasU = hasV = false;
			}
		}

		win.draw(left);
		win.draw(right);
		win.display();
	}

   win.close();
   return 0;
}


