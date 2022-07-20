#include <SFML/Graphics.hpp>
#include <iostream>
#include <math.h>

template <typename T>
float Distance(const sf::Vector2<T>& v1, const sf::Vector2<T>& v2)
{
	return sqrt(pow(v2.x - v1.x, 2) + pow(v2.y - v1.y, 2) * 1.0);
}

template <typename T>
sf::Vector2<T> normalize(const sf::Vector2<T>& source)
{
	float length = sqrt((source.x * source.x) + (source.y * source.y));
	if (length != 0)
		return sf::Vector2<T>(source.x / length, source.y / length);
	else
		return source;
}

void MoveTowards(sf::RectangleShape& rect1, const sf::Vector2<float> endPos, const float maxDist)
{
	auto startPos = rect1.getPosition();
	if (startPos == endPos) return;
	auto newPos = startPos + normalize(endPos - startPos) * maxDist;
	rect1.setPosition(newPos);
}

int main()
{
	int screenHeight = 800;
	int width = 800;
	float counter = 0;
	float counter1 = 0;
	bool canMove = false;
	sf::RenderWindow window(sf::VideoMode(width, screenHeight), "SFML works!");
	sf::Clock clock;

	sf::Font font;
	font.loadFromFile("../Resources/Roboto.ttf");

	std::vector<sf::RectangleShape> bars;
	std::vector<sf::Text> texts;
	float barsLength[] = { 10, 100, 200, 300, 120, 140, 160, 170, 110, 50 };
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
	sf::Vector2<float> newPosition = bars[0].getPosition();
	sf::Vector2<float> newPosition1 = bars[0].getPosition();

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

	int i = 0;
	int j = 0;
	int currentIndex = 0;
	while (window.isOpen())
	{
		const auto deltaTime = clock.restart().asSeconds();
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		//Sorting
		if (counter > 0.5f && i < bars.size() - 1)
		{
			for (auto& bar : bars)
				bar.setFillColor(sf::Color::Black);
			bars[j].setFillColor(sf::Color::Blue);
			bars[j + 1].setFillColor(sf::Color::Blue);
			if (counter > 1.f)
			{

				//Swapping
				if (!canMove)
				{
					if (bars[j].getSize().y > bars[j + 1].getSize().y)
					{
						float tempPos = bars[j].getPosition().x;
						newPosition = { bars[j + 1].getPosition().x, bars[j].getPosition().y };
						newPosition1 = { tempPos, bars[j + 1].getPosition().y };
						currentIndex = j;
						canMove = true;

						tempPos = texts[j].getPosition().x;
						texts[j].setPosition(texts[j + 1].getPosition().x, texts[j].getPosition().y);
						texts[j + 1].setPosition(tempPos, texts[j + 1].getPosition().y);
					}
					else {
						j++;
					}
				}
				std::cout << "Bar Pos: " << bars[j].getPosition().x << " New: " << newPosition.x << std::endl;
				if (Distance(bars[j].getPosition(), newPosition) < 5.f)
				{
					std::cout << "i: " << i << " j: " << j << std::endl;
					if (bars[j].getSize().y > bars[j + 1].getSize().y)
					{
						auto temp = bars[j];
						bars[j] = bars[j + 1];
						bars[j + 1] = temp;

						//Swap Text
						auto tempText = texts[j];
						texts[j] = texts[j + 1];
						texts[j + 1] = tempText;
					}
					canMove = false;
					j++;
				}
				if (j >= bars.size() - i - 1)
				{
					i++;
					j = 0;
					newPosition = bars[0].getPosition();
				}
				counter = 0;
			}
		}
		counter += deltaTime;
		if (canMove)
		{
			MoveTowards(bars[currentIndex], newPosition, 100.f * deltaTime);
			MoveTowards(bars[currentIndex + 1], newPosition1, 100.f * deltaTime);
		}


		//Drawing
		window.clear(sf::Color::White);
		for (int i = 0; i < bars.size(); i++)
		{
			window.draw(bars[i]);
			window.draw(texts[i]);
		}
		window.display();
	}

	return 0;
}