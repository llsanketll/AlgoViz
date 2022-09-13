#include <SFML/Graphics.hpp>
#include <iostream>
#include <math.h>
#include "BubbleSort.h"
#include "QuickSort.h"
#include "BST.h"
#include "Button.h"


int main()
{
	int screenHeight = 600;
	int screenWidth = 800;
	float counter = 0;
	float counter1 = 0;
	bool canMove = false;
	sf::RenderWindow window(sf::VideoMode(screenWidth, screenHeight), "SFML works!");
	sf::Clock clock;

	sf::Font font;
	font.loadFromFile("../Resources/Roboto.ttf");

	std::vector<sf::RectangleShape> bars;
	std::vector<sf::Text> texts;
	float barsLength[] = { 20, 10, 100, 200, 300, 120, 140, 160, 320, 170, 110, 50, 140, 250, 200, 69 };
	for (int i = 0; i < sizeof(barsLength) / sizeof(barsLength[0]) - 1; i++)
	{
		//sf::RectangleShape bar({ 10.f, (float)(rand() % 500 + 20) });
		sf::RectangleShape bar({ 10.f, barsLength[i] });
		bar.setFillColor(sf::Color::Black);
		bar.setPosition({ 50.f * i + 10.f, screenHeight - bar.getSize().y });;
		sf::Text text;
		text.setFont(font);
		std::string value = std::to_string(bar.getSize().y);
		text.setString(value.substr(0, value.find(".") + 0));
		text.setPosition({ 50.f * i + 10.f, bar.getPosition().y - 20.f });
		text.setFillColor(sf::Color::Black);
		text.setCharacterSize(10);
		texts.push_back(text);
		bars.push_back(bar);
	}
	BubbleSort* bubbleSort = new BubbleSort(bars, texts);
	QuickSort* quickSort = new QuickSort(bars, texts);
	BST* bst = new BST(bars, texts, window);

	Button* button = new Button(&window,sf::Vector2f(30, 30),sf::Color::Yellow, sf::Vector2f(200, 200));

	sf::RectangleShape rectangle(sf::Vector2f(10, 10));


	while (window.isOpen())
	{
		const auto deltaTime = clock.restart().asSeconds();
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		////----------Sorting--------------
		bubbleSort->Sort(deltaTime);
		//----------Drawing---------------
		window.clear(sf::Color::White);

		sf::Font font;
		font.loadFromFile("arial.ttf");
		
		button->setText("I am a button",font ,sf::Color::Black, 15);
		button->draw();
		bubbleSort->Draw(window);



		if (button->isButtonClicked()) {
			std::cout << "Button Clicked" << std::endl;
			button->setColorOnClick(sf::Color::Red);
		}

		window.display();
		//--------------------------------
	}

	return 0;
}