#include "Button.h"
#include <iostream>

Button::Button(sf::RenderWindow *window)
{
	this->window = window;
	this->buttonFont = new sf::Font();
	buttonFont->loadFromFile("arial.ttf");

	this->buttonSize = sf::Vector2f(30,30);
	this->buttonLoc = sf::Vector2f(0, 0);

	buildButtonRect(this->buttonSize, sf::Color::White, this->buttonLoc);
}

//constructor
Button::Button(sf::RenderWindow *window, sf::Vector2f size, sf::Color normalColor, sf::Vector2f location) {
	this->window = window;
	isClicked = false;
	buildButtonRect(size, normalColor, location);
}



bool Button::getState() {
	return isClicked;
}

void Button::draw()
{
	window->draw(*buttonRectangle);
	window->draw(*text);
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

void Button::buildButtonRect(sf::Vector2f size, sf::Color normalColor, sf::Vector2f location)
{
	this->buttonLoc = location;
	this->buttonSize = size;
	this->normalColor = normalColor;

	this->buttonRectangle = new sf::RectangleShape(size);
	buttonRectangle->setFillColor(normalColor);
	buttonRectangle->setPosition(location);
}


void Button::setText(const std::string& text, const sf::Font& font,const sf::Color& textColor, const int32_t& textSize)
{
	sf::String buttonText(text);
	this->text = new sf::Text(buttonText, font);
	this->text->setFillColor(textColor);
	this->text->setCharacterSize(textSize);
	buildButtonWithText();
}

void Button::buildButtonWithText()
{
	float textPosX = this->buttonLoc.x + (this->buttonSize.x / 2) - (this->buttonSize.x / 4);
	float textPosY = this->buttonLoc.y + (this->buttonSize.y / 2) - (this->buttonSize.y / 4);

	this->text->setPosition(textPosX, textPosY);

	float buttonLength = this->text->getCharacterSize() * this->text->getString().getSize();

	float newSizeX = buttonLength;
	float newSizeY = this->buttonSize.y;

	sf::Vector2f newSize(newSizeX, newSizeY);
	buildButtonRect(newSize, this->normalColor, this->buttonLoc);
}