#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/System/String.hpp>
class Button {
public:
	Button(sf::Vector2f size, sf::Color normalColor, sf::Color clickedColor, std::string words, sf::Vector2f location);
	void Draw(sf::RenderWindow& window);
	void checkClicked(sf::Vector2f mousePos);
	void setClicked(bool);
	void setText(std::string);
	bool getState();
private:
	sf::RectangleShape rectangle;
	sf::Text text;
	sf::Color normalColor;
	sf::Color clickedColor;
	bool isClicked;
};


