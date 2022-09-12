#include <SFML/Graphics.hpp>
#include <iostream>
#include <math.h>
#include "BubbleSort.h"
#include "QuickSort.h"
#include "BST.h"
#include "Button.h"


int main()
{
	int screenHeight = 800;
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

	Button* button = new Button(&window,sf::Vector2f(60, 60),sf::Color::Yellow, sf::Vector2f(200, 200));

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
		button->draw();
		bubbleSort->Draw(window);

		//uncomment code below to see button hover action
		//sf::Mouse mouse;


		if (button->isButtonClicked()) {
			std::cout << "Button Clicked" << std::endl;
			button->setColorOnClick(sf::Color::Red);
		}

		/*while (button->isButtonHovered()) {
			std::cout << "Button Hovered!!!" << std::endl;
		}*/

		window.display();
		//--------------------------------
	}

	return 0;
}



//for (int i = 0; i < bars.size() - 1; i++)
//{
//	for (int j = 0; j < bars.size() - i - 1; j++)
//	{
//		if (bars[j].getSize().y > bars[j + 1].getSize().y)
//		{
//			float tempPos = bars[j].getPosition().x;
//			bars[j].setPosition(bars[j + 1].getPosition().x, bars[j].getPosition().y);
//			bars[j + 1].setPosition(tempPos, bars[j + 1].getPosition().y);

//			auto temp = bars[j];
//			bars[j] = bars[j + 1];
//			bars[j + 1] = temp;

//			tempPos = texts[j].getPosition().x;
//			texts[j].setPosition(texts[j + 1].getPosition().x, texts[j].getPosition().y);
//			texts[j + 1].setPosition(tempPos, texts[j + 1].getPosition().y);

//			auto tempText = texts[j];
//			texts[j] = texts[j + 1];
//			texts[j + 1] = tempText;
//		}
//	}
//}