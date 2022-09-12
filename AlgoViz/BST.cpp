#include "BST.h"
using namespace std;


BST::BST(std::vector<sf::RectangleShape>& bars, std::vector<sf::Text>& texts, sf::RenderWindow& win) : window(win)
{
	x_axis = window.getSize().x / 2, y_axis = 0;
	katch = false;

	node = new tree;

	text.setFont(font);
	text.setFillColor(sf::Color::Black);
	if (!font.loadFromFile("impact.ttf"))
		cout << "Failed to load text ." << endl;

}

void BST::Draw(sf::RenderWindow& window)
{
	system("cls");
	x_axis = window.getSize().x / 2;
	showinorder();

	window.display();

	int choice;
	node = new tree;
	cout << "enter 1 to insert : " << endl;
	cout << "enter 2 to delete : " << endl;
	cout << "enter 3 to search : " << endl;
	cin >> choice;
	cin.ignore();
	if (choice == 1)
	{
		cout << "enter item to insert : ";
		cin >> node->data;
		node->left = NULL;
		node->right = NULL;
		root = insert_node(root, node);
	}

	else if (choice == 2)
	{
		cout << "enter item to delete : ";
		cin >> delet;
		nodedel(root, delet);
	}

	else if (choice == 3)
	{
		cout << "enter item to search : ";
		cin >> search;
		katch = ispresent(root, search);
		if (katch == true)
		{
			cout << "Element found . " << endl;
		}

		system("pause");
	}
	sf::Event event;
	system("pause");
}
