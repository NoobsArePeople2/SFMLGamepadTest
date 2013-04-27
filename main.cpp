/*
 * main.cpp
 *
 *  Created on: Dec 8, 2012
 *      Author: Sean
 */

#include <SFML/Graphics.hpp>
#include <iostream>
#include <sstream>

#include <vector>
#include <string>

#include "JoystickHelper.h"

int main()
{
	sf::RenderWindow win;
	int width = 1024;
	int height = 1024;
	win.create(sf::VideoMode(width, height, 32), "SFML Game Pad Test");
	win.setFramerateLimit(60);
	sf::Event event;

	std::vector<bool> pads(4, false);
	std::vector<std::vector<sf::Text> > gui;

	sf::Font font = sf::Font();
	font.loadFromFile("arial.ttf");

	for (unsigned int i = 0; i < pads.size(); ++i) {
		pads.at(i) = sf::Joystick::isConnected(i);

		int x = i % 2 == 0 ? 0 : 0.25 * width;
		x += i > 1 ? width * 0.5 : 0;
		int y = 0;

		std::vector<sf::Text> readout;

		int fontSize = 18;
		sf::Text left = sf::Text("", font, fontSize);
		left.setPosition(x, y);

		sf::Text right = sf::Text("", font, fontSize);
		right.setPosition(x, y + 100);

		sf::Text buttons = sf::Text("", font, fontSize);
		buttons.setPosition(x, y + 300);

		sf::Text dpad = sf::Text("", font, fontSize);
		dpad.setPosition(x, y + 200);

		readout.push_back(left);
		readout.push_back(right);
		readout.push_back(buttons);
		readout.push_back(dpad);

		gui.push_back(readout);
	}

	bool exit = false;

	while (!exit) {
		win.pollEvent(event);
		if (event.type == sf::Event::Closed) {
			exit = true;
		}

		win.clear(sf::Color(0, 0, 0));

		unsigned int len = pads.size();

		for (unsigned int i = 0; i < len; ++i) {
			bool connected = pads.at(i);
			bool hasX, hasY, hasZ, hasR, hasU, hasV, hasPovX, hasPovY = false;

			if (sf::Joystick::isConnected(i)) {
				if (!connected) {
//					std::cout << "Joystick name: " << sf::Joystick::getProduct(i) << std::endl;
//					std::cout << "Joystick " << i << " connected!" << std::endl;
//					std::cout << "Joystick " << i << " has '" << sf::Joystick::getButtonCount(0) << "' buttons" << std::endl;
					connected = true;

					hasX    = sf::Joystick::hasAxis(i, sf::Joystick::X);
					hasY    = sf::Joystick::hasAxis(i, sf::Joystick::Y);
					hasZ    = sf::Joystick::hasAxis(i, sf::Joystick::Z);
					hasR    = sf::Joystick::hasAxis(i, sf::Joystick::R);
					hasU    = sf::Joystick::hasAxis(i, sf::Joystick::U);
					hasV    = sf::Joystick::hasAxis(i, sf::Joystick::V);
					hasPovX = sf::Joystick::hasAxis(i, sf::Joystick::PovX);
					hasPovY = sf::Joystick::hasAxis(i, sf::Joystick::PovY);

				}

				float x    = hasX    ? sf::Joystick::getAxisPosition(i, sf::Joystick::X)    : -1.0f;
				float y    = hasY    ? sf::Joystick::getAxisPosition(i, sf::Joystick::Y)    : -1.0f;
				float z    = hasZ    ? sf::Joystick::getAxisPosition(i, sf::Joystick::Z)    : -1.0f;
				float r    = hasR    ? sf::Joystick::getAxisPosition(i, sf::Joystick::R)    : -1.0f;
				float u    = hasU    ? sf::Joystick::getAxisPosition(i, sf::Joystick::U)    : -1.0f;
				float v    = hasV    ? sf::Joystick::getAxisPosition(i, sf::Joystick::V)    : -1.0f;
				float povX = hasPovX ? sf::Joystick::getAxisPosition(i, sf::Joystick::PovX) : -1.0f;
				float povY = hasPovY ? sf::Joystick::getAxisPosition(i, sf::Joystick::PovY) : -1.0f;

				std::ostringstream stream;
				//stream << "Name: " << sf::Joystick::getProduct(i) << "\n";
//				stream << "Name: " << sf::Joystick::getName(i) << "\n";
				stream << "Name: " << JoystickHelper::getName(i) << "\n";
				stream << "Axis X: " << x << "\nAxis Y: " << y << "\nAxis Z: " << z;
				gui.at(i).at(0).setString(stream.str());
				stream.str("");
				stream.clear();

				stream << "Axis R: " << r << "\nAxis U: " << u << "\nAxis V: " << v;
				gui.at(i).at(1).setString(stream.str());
				stream.str("");
				stream.clear();

				for (unsigned int j = 0; j < sf::Joystick::getButtonCount(i); ++j) {
					stream << "Button " << j << " " << (sf::Joystick::isButtonPressed(i, j) ? "is pressed" : "not pressed") << "\n";
				}

				gui.at(i).at(2).setString(stream.str());
				stream.str("");
				stream.clear();

				stream << "PovX: " << povX << "\nPovY: " << povY;
				gui.at(i).at(3).setString(stream.str());
				stream.str("");
				stream.clear();

			} else {
				if (connected) {
//					std::cout << "Joystick " << i << " disconnected :(" << std::endl;
					pads.at(i) = false;
					gui.at(i).at(0).setString("");
					gui.at(i).at(1).setString("");
					gui.at(i).at(2).setString("");
					gui.at(i).at(3).setString("");
				}
			}

			win.draw(gui.at(i).at(0));
			win.draw(gui.at(i).at(1));
			win.draw(gui.at(i).at(2));
			win.draw(gui.at(i).at(3));
		}

		win.display();
	}

   win.close();
   return 0;
}



