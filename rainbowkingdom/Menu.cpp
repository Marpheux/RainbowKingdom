#include "Menu.h"
using namespace std;

void Welcome()
{
	User User_1;

	cout << "Welcome to the Rainbow Kingdom" << endl;
	cout << endl << "Username: " << User_1.getName() << endl <<
		"Orbs: " << User_1.getScore() << endl;
	
}

void MainMenu()
{
	int Choice = 9;

	while (Choice != 0)
	{
		cout << "Pick an option from the menu to travel the kingdom" << endl << "0 - Quit" << endl << "1 - View your orbs" << endl << "2 - Visit the Prism (Shop)" << endl << "3 - The other side of the rainbow (Games) " << endl << "4 - Visit your Guardian" << endl;
		cin >> Choice;

		if 
	}
}