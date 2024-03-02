//Assignment11.cpp, Jackson Bell, 4/17/2023
//Chapter 11, Assn 11 Prb.docx, Program 1
// This program has an assortment of functions
// all called by a switch grouping in main. It 
// can take input for an item and its model, price
// and year, and then display said item(s). it can also
//add up all the prices and display the total value
// of the items. you can also single out one item 
// and replace it if you entered somethonf wrong.
// and you can find a certian item by the model name
// through a search.
#include <iostream>
#include <string>
using namespace std;

//structure for the items array
struct itemInfo
{
	string item, model;
	float price;
	double year;
};

//prototypes
int displayMenu();
int inputItems(itemInfo items[]);
void displayItems(itemInfo items[], int nums);
void findItem(itemInfo items[], int nums);
void changeItem(itemInfo items[], int nums);
void displayTotalValue(itemInfo items[], int nums);

int main()
{
	// array that contains the items
	itemInfo items[10];
	//choice for the switch and
	// num for the amount of items
	int choice, num = 0;

	// display returns a number for choice
	choice = displayMenu();

	//while loop that contains the switch
	//and ends if the user selects 6
	while (choice != 6)
	{
		switch (choice)
		{
		case 1:
			num = inputItems(items);
			break;
		case 2:
			displayItems(items, num);
			break;
		case 3:
			findItem(items, num);
			break;
		case 4:
			changeItem(items, num);
			break;
		case 5:
			displayTotalValue(items, num);
			break;
		default:
			cout << "\nPlease enter a number through 1-6.\n\n";
			break;
		}

		choice = displayMenu();
	}

	cout << "\nThanks for using the program!!" << endl;
}

//this function displays a menu and asks for 
// an input for the program
int displayMenu()
{
	cout << "HOME INVENTORY PROGRAM\n\n";
	cout << "Please choose from the following options:\n\n";
	cout << "1.  Input items\n2.  Display items\n3.  Find item";
	cout << "\n4.  Change item\n5.  Display total value\n6.  Quit\n\n";
	cout << "Input choice: ";
	int choice;
	cin >> choice;
	return choice;
}

//this function takes input for each
// variable in the array elements
int inputItems(itemInfo items[])
{
	int num;
	cout << "\nHow many items? ";
	cin >> num;
	cout << endl;
	for (int c = 0; c < num; c++)
	{
		cout << "Please enter values for item " << ++c << ":\n";
		cout << "Item? ";
		cin >> items[--c].item;
		cout << "Model? ";
		cin >> items[c].model;
		cout << "Price? ";
		cin >> items[c].price;
		cout << "Year? ";
		cin >> items[c].year;
		cout << endl;
	}

	return num;
}

//this function displays the array and each of
// its elements' contents
void displayItems(itemInfo items[], int nums)
{
	for (int c = 0; c < nums; c++)
	{
		cout << "\nITEM " << ++c << ":\n";
		cout << "ITEM - " << items[--c].item << endl;
		cout << "MODEL - " << items[c].model << endl;
		cout << "PRICE - " << items[c].price << endl;
		cout << "YEAR - " << items[c].year << endl << endl;
	}
}

//This function takes input for a model,
// and then finds an item with the same
// model name
void findItem(itemInfo items[], int nums)
{
	string model;
	int mod = 0;
	cout << "\nPlease enter a model: ";
	cin >> model;

	for (int c = 0; c < nums; c++)
	{
		if (model == items[c].model)
		{
			cout << "\nITEM " << ++c << ":\n";
			cout << "ITEM - " << items[--c].item << endl;
			cout << "MODEL - " << items[c].model << endl;
			cout << "PRICE - " << items[c].price << endl;
			cout << "YEAR - " << items[c].year << endl << endl;
			mod = 1;
		}
	}
	if (mod == 0)
		cout << "\nThere is no model named " << model << "." << "\n\n";
}

//this function displays all the items,
//asks the user what item they want
// to replace, and then takes input
// and replaces said item.
void changeItem(itemInfo items[], int nums)
{
	int item;
	displayItems(items, nums);
	cout << "\nWhich item would you like to replace? ";
	cin >> item;
	cout << "\nPlease enter values for item " << item << ":\n";
	cout << "Item? ";
	cin >> items[--item].item;
	cout << "Model? ";
	cin >> items[item].model;
	cout << "Price? ";
	cin >> items[item].price;
	cout << "Year? ";
	cin >> items[item].year;
	cout << endl;
	displayItems(items, nums);

}

//this function takes the prices of all
// the items and then adds them up for
// a total price.
void displayTotalValue(itemInfo items[], int nums)
{
	int value = 0;
	for (int c = 0; c < nums; c++)
		value += items[c].price;

	cout << "\nThe total value of the items is $";
	cout << value << "\n\n";
}