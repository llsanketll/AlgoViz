#include "Button.h"
#include <iostream>

Button::Button(sf::Vector2f size, sf::Color normalColor, sf::Color clickedColor, std::string words, sf::Vector2f location) {
	isClicked = false;
	rectangle.setSize(size);
	rectangle.setPosition(location);
	rectangle.setFillColor(normalColor);
	this->normalColor = normalColor;
	this->clickedColor = clickedColor;
	sf::Font font;
	font.loadFromFile("../Resources/Roboto.ttf");
	text.setFont(font);
	text.setString(words);
	text.setCharacterSize(24);
	text.setPosition(location);
	text.setFillColor(sf::Color::Black);
}

void Button::checkClicked(sf::Vector2f mousePos) {
	if (mousePos.x > rectangle.getPosition().x && mousePos.x < (rectangle.getPosition().x + rectangle.getSize().x)) {
		if (mousePos.y > rectangle.getPosition().y && mousePos.y < (rectangle.getPosition().y + rectangle.getSize().y)) {
			setClicked(!isClicked);
		}
	}
}
void Button::setClicked(bool which) {
	isClicked = which;
	if (isClicked) {
		rectangle.setFillColor(normalColor);
		return;
	}
	rectangle.setFillColor(clickedColor);
}
void Button::setText(std::string words) {
	text.setString(words);
}
bool Button::getState() {
	return isClicked;
}

void Button::Draw(sf::RenderWindow& window)
{
	window.draw(rectangle);
	//window.draw(text);
}
