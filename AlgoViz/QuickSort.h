#pragma once
#include <iostream>
#include "SFML/Graphics.hpp"
class QuickSort
{
private:
	std::vector<sf::RectangleShape> bars;
	std::vector<sf::Text> texts;
	bool canMove = false;
	float counter = 0;
public:
	QuickSort(std::vector<sf::RectangleShape>& bars, std::vector<sf::Text>& texts);
	int Partition(int start, int end);
	void QS(int start, int end);
	void Draw(sf::RenderWindow& window);
	void Sort(float deltaTime);
	void Swap(sf::Transformable* a, sf::Transformable* b);
};

