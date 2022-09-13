#include "BubbleSort.h"

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

void MoveTowards(sf::Transformable& obj, const sf::Vector2<float> endPos, const float maxDist)
{
	auto startPos = obj.getPosition();
	if (startPos == endPos) return;
	auto newPos = startPos + normalize(endPos - startPos) * maxDist;
	obj.setPosition(newPos);
}

void BubbleSort::Draw(sf::RenderWindow& window)
{
	for (int i = 0; i < bars.size(); i++)
	{
		window.draw(bars[i]);
		window.draw(texts[i]);
	}
}

BubbleSort::BubbleSort(std::vector<sf::RectangleShape> bars, std::vector<sf::Text> texts)
{
	this->bars = bars;
	this->texts = texts;
	newPosition = bars[0].getPosition();
	newPosition1 = bars[0].getPosition();
	newTextPosition = texts[0].getPosition();
	newTextPosition1 = texts[0].getPosition();
}


void BubbleSort::Sort(float deltaTime) {
	if (counter > 0.03f && i < bars.size() - 1)
	{
		for (int k = 0; k < bars.size() - i; k++)
			bars[k].setFillColor(sf::Color::Black);
		bars[j].setFillColor(sf::Color::Blue);
		bars[j + 1].setFillColor(sf::Color::Blue);
		if (counter > 0.1f)
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
					newTextPosition = { texts[j + 1].getPosition().x, texts[j].getPosition().y };
					newTextPosition1 = { tempPos, texts[j + 1].getPosition().y };
				}
				else {
					j++;
				}
			}
			if (Distance(bars[j].getPosition(), newPosition) < 5.f)
			{
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
				bars[j].setFillColor(sf::Color::Green);
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
		MoveTowards(texts[currentIndex], newTextPosition, 100.f * deltaTime);
		MoveTowards(texts[currentIndex + 1], newTextPosition1, 100.f * deltaTime);
	}
}