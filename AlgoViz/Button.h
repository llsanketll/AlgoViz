#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/System/String.hpp>
class Button {
private:
	sf::Font *buttonFont;

	sf::RenderWindow *window;
	sf::Vector2f buttonLoc;
	sf::Vector2f buttonSize;
	sf::RectangleShape* buttonRectangle;
	sf::Color normalColor;
	sf::Color clickedColor;

	sf::Text *text;
	
	bool isClicked;

public:
	Button(sf::RenderWindow *window);
	Button(sf::RenderWindow *window, sf::Vector2f size, sf::Color normalColor, sf::Vector2f location);
	bool getState();
	void draw();

	bool isButtonHovered();
	bool isButtonClicked();

	void setColorOnHover(sf::Color color);
	void setColorOnClick(sf::Color color);

	sf::Vector2f getButtonLocation();

	void setText(const std::string &text,const sf::Font& font, const sf::Color& textColor, const int32_t& textSize);

private:
	void buildButtonRect(sf::Vector2f size, sf::Color normalColor, sf::Vector2f location);
	void buildButtonWithText();
};

