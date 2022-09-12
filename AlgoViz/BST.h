#pragma once
#include <SFML/Graphics.hpp>
#include <Windows.h>
#include <iostream>

struct tree
{
	int data;
	tree* left;
	tree* right;
	tree* parent;
};


class BST
{
private:
	sf::RenderWindow& window;
	sf::CircleShape shape;
	sf::RectangleShape line;
	sf::RectangleShape line2;
	sf::Font font;
	sf::Font font3;
	sf::Text text;
	std::string temp_string;
	sf::Font font1;
	sf::Text text3;
	float x_axis, y_axis;
	int f = 0;
	bool katch;
	tree* root = NULL;
	tree* node;
	int delet;
	int search;


	tree* insert_node(tree* root, tree* node)
	{
		if (root == NULL)
		{
			root = node;
		}

		else
		{
			if (node->data < root->data)
			{
				root->left = insert_node(root->left, node);
			}

			else if (node->data > root->data)
			{
				root->right = insert_node(root->right, node);
			}
		}
		return root;
	}

	tree* minvalue(tree* temp)

	{

		tree* temp1 = temp;

		while (temp1 != NULL)

		{

			temp1 = temp1->left;
		}

		return temp1;
	}

	tree* nodedel(tree* ptr1, int data)

	{

		if (ptr1 == NULL)

		{

			return ptr1;
		}

		if (data < ptr1->data)

		{

			ptr1->left = nodedel(ptr1->left, data);
		}

		else if (data > ptr1->data)

		{

			ptr1->right = nodedel(ptr1->right, data);
		}

		else

		{

			if (ptr1->left == NULL)

			{

				tree* temp = ptr1->right;

				free(ptr1);

				return temp;
			}

			else if (ptr1->right == NULL)

			{

				tree* temp = ptr1->left;

				free(ptr1);

				return temp;
			}

			tree* ptr2 = minvalue(ptr1->right);

			ptr1->data = ptr2->data;

			ptr1->right = nodedel(ptr1->right, ptr2->data);
		}

		return ptr1;
	}

	bool ispresent(tree* ptr, int key)

	{

		if (ptr != NULL)

		{

			if (ptr->data == key)

			{

				f = 1;

				return true;
			}

			else

			{

				return ispresent(ptr->left, key) || ispresent(ptr->right, key);
			}
		}

		return false;
	}

	void showinorder(int level = 1, tree* Root = NULL, bool katch = false)

	{

		y_axis = 0;

		int i;

		if (Root != NULL)

		{

			//////////

			int a, b, c, sum = 0;

			a = Root->data;

			b = a;

			if (f == 1)

			{

				katch = true;
			}

			while (a > 0)

			{

				c = a % 10;

				sum = sum + c * c * c;

				a = a / 10;
			}

			int n, num, rev = 0;

			n = Root->data;

			num = n;

			while (n > 0)

			{

				a = n % 10;

				rev = (rev * 10) + a;

				n = n / 10;
			}

			showinorder(level + 1, Root->left, false);

			//////////////

			for (i = 0; i < level && Root != root; i++)

			{

				y_axis = y_axis + 50;
			}

			shape.setRadius(20);

			if (sum == b)

			{

				shape.setFillColor(sf::Color::Red);
			}

			else if (num == rev)

			{

				shape.setFillColor(sf::Color::Blue);
			}

			/////////       for left

			line.setSize(sf::Vector2f(80, 4));

			line.setFillColor(sf::Color::White);

			shape.setPosition(sf::Vector2f(x_axis, y_axis));

			line.setPosition(shape.getPosition().x + shape.getRadius() / 2 + 20, shape.getPosition().y + shape.getRadius() + 10);

			line.setRotation(135);

			////////// for right line

			line2.setSize(sf::Vector2f(80, 4));

			line2.setFillColor(sf::Color::White);

			line2.setPosition(shape.getPosition().x + shape.getRadius() / 2 + 20, shape.getPosition().y + shape.getRadius() + 10);

			line2.setRotation(45);

			// for text

			///////////////////////////////////////////////

			text.setFillColor(sf::Color::Yellow);

			text.setCharacterSize(20);

			temp_string = std::to_string(Root->data);

			text.setString(temp_string);

			text.setPosition(x_axis + 8, y_axis + 8);

			x_axis = x_axis + 50;

			window.draw(shape);

			window.draw(text);

			window.draw(line);

			window.draw(line2);

			if (f == 1)

			{

				text3.setFont(font3);

				text3.setString(" Value is Found");

				text3.setCharacterSize(100);

				text3.setPosition(10, 150);

				text3.setFillColor(sf::Color::Blue);

				window.draw(text3);

				f = 0;
			}

			showinorder(level + 1, Root->right, true);
		}
	}
public:
	BST(std::vector<sf::RectangleShape>& bars, std::vector<sf::Text>& texts, sf::RenderWindow& window);
	void Draw(sf::RenderWindow& window);
};
