#include "Button.h"
#include <iostream>

//constructor
Button::Button(sf::RenderWindow *window, sf::Vector2f size, sf::Color normalColor, sf::Vector2f location) {
	this->window = window;
	isClicked = false;
	buildRectangle(size, normalColor, location);
}


bool Button::getState() {
	return isClicked;
}

void Button::draw()
{
	window->draw(*buttonRectangle);
}

void Button::setLabel(sf::String label, sf::Color labelColor)
{

}

void Button::setLabel(sf::String)
{
}

sf::Vector2f Button::getButtonLocation()
{
	return this->buttonLoc;
}

bool Button::isButtonHovered()
{
	sf::Mouse mouse;
	sf::Vector2i mousePos = mouse.getPosition(*window);

	bool xCordinateTruthCondition = mousePos.x > buttonLoc.x && mousePos.x < (buttonLoc.x + buttonSize.x);
	bool yCoordinateTruthCondition = mousePos.y > buttonLoc.y && mousePos.y < (buttonLoc.y + buttonSize.y);


	if (xCordinateTruthCondition && yCoordinateTruthCondition) {
			return true;
	}
	return false;
}


bool Button::isButtonClicked()
{
	sf::Mouse mouse;
	sf::Vector2i mousePos = mouse.getPosition(*window);

	bool xCordinateTruthCondition = mousePos.x > buttonLoc.x && mousePos.x < (buttonLoc.x + buttonSize.x);
	bool yCoordinateTruthCondition = mousePos.y > buttonLoc.y && mousePos.y < (buttonLoc.y + buttonSize.y);

	if (xCordinateTruthCondition && yCoordinateTruthCondition) {
			if (mouse.isButtonPressed(sf::Mouse::Left)) {
				this->isClicked = true;
				return true;
			}
	}
	return false;
}

void Button::setColorOnHover(sf::Color color)
{
}


void Button::setColorOnClick(sf::Color color)
{
	this->buttonRectangle->setFillColor(color);
}

void Button::buildRectangle(sf::Vector2f size, sf::Color normalColor, sf::Vector2f location)
{
	this->buttonLoc = location;
	this->buttonSize = size;

	this->buttonRectangle = new sf::RectangleShape(size);
	buttonRectangle->setFillColor(normalColor);
	buttonRectangle->setPosition(location);
}
