#include "QuickSort.h"

QuickSort::QuickSort(std::vector<sf::RectangleShape>& bars, std::vector<sf::Text>& texts) {
	this->bars = bars;
	this->texts = texts;
}

void QuickSort::Swap(sf::Transformable* a, sf::Transformable* b)
{
	float tempPos = a->getPosition().x;
	a->setPosition({ b->getPosition().x, a->getPosition().y });
	b->setPosition({ tempPos, b->getPosition().y });
	auto temp = *a;
	*a = *b;
	*b = temp;
}

int QuickSort::Partition(int start, int end)
{
	auto pivot = bars[end];
	int partitionIndex = start - 1;
	for (int i = start; i < end; i++)
	{
		if (bars[i].getSize().y < pivot.getSize().y)
		{
			//Swap(&bars[i], &bars[partitionIndex]);
			//Swap(&texts[i], &texts[partitionIndex]);

			partitionIndex++;
			float tempPos = bars[i].getPosition().x;
			bars[i].setPosition({ bars[partitionIndex].getPosition().x, bars[i].getPosition().y });
			bars[partitionIndex].setPosition({ tempPos, bars[partitionIndex].getPosition().y });

			auto temp = bars[i];
			bars[i] = bars[partitionIndex];
			bars[partitionIndex] = temp;
		}
	}
	return partitionIndex + 1;
}
void QuickSort::QS(int start, int end)
{
	if (start >= end) return;
	int pIndex = Partition(start, end);
	QS(start, pIndex - 1);
	QS(pIndex + 1, end);
}

void QuickSort::Sort(float deltaTime)
{
	QS(0, bars.size() - 1);
}

void QuickSort::Draw(sf::RenderWindow& window)
{
	for (int i = 0; i < bars.size(); i++)
	{
		window.draw(bars[i]);
		window.draw(texts[i]);
	}
}
