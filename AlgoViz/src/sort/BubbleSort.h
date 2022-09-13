#pragma once
#include <iostream>
#include "SFML/Graphics.hpp"

class BubbleSort {
private:
	std::vector<sf::RectangleShape> bars;
	std::vector<sf::Text> texts;
	bool canMove = false;
	float counter = 0;
	int i = 0, j = 0, currentIndex = 0;

	sf::Vector2<float> newPosition;
	sf::Vector2<float> newPosition1;
	sf::Vector2<float> newTextPosition;
	sf::Vector2<float> newTextPosition1;

public:
	BubbleSort(std::vector<sf::RectangleShape> bars, std::vector<sf::Text> texts);
	void Sort(float deltaTime);
	void Draw(sf::RenderWindow& window);
};
