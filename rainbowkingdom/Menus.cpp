#include "Other.h"

const int MAXCHOICE = 9;

void Welcome() {
	cout << "\t ____________________________________________________________" << endl;
	cout << "\t|                                                            |" << endl;
	cout << "\t|           --O--     The Rainbow Kingdom     --O--          |" << endl;
	cout << "\t|____________________________________________________________|" << endl;
	cout << endl;
}

void Menu(vector<Pet>& AI, User& User, Pet& Pet) 
{
	int choice = MAXCHOICE;

	while (choice != 0)
	{
		cout<< "\nPick an option from the main menu\n" << endl 
			<< "0 - Save and quit" << endl 
			<< "1 - View your orbs" << endl 
			<< "2 - Change your username" << endl 
			<< "3 - The other side of the rainbow (Games) " << endl 
			<< "4 - Visit your Guardian" << endl 
			<< "5 - Visit the prism (shop) " << endl;
		cout << "\nChoice: ";
		cin >> choice;
		int counter = 0;

		choice = checkError(choice);

		if (choice == 1) 
		{
			cout << "\nYou have " << User.getScore() << " orbs\n" << endl;
			system("pause");
			//Press enter to pause a system command, only commenting once.
		}
		else if (choice == 2) 
		{
			cout << "\nYour current username is: " << User.getName() << endl;
			string name;
			cout << "Please enter your new username: ";
			cin >> name;
			User.setName(name);
			//Sets username according to user input
			system("pause");
		}
		else if (choice == 3) 
		{
			gameMenu(AI, User, Pet);
			//Runs game menu
		}
		else if (choice == 4) 
		{
			if (User.getPet() == "Y"){
				petMenu(User, Pet);
				//Runs pet menu
			}
			else
			{
				cout << "\nYou do not have a guardian you can buy one at the Prism\n" << endl;
				system("pause");
			}
			
		}
		else if (choice == 5) {
			if (User.getScore() > 100 && User.getPet() != "Y")
			{
				cout << "Welcome to the Prism where you can buy the finest guardians in the land!" << endl;
				string pChoice;
				cout << "\nDo you wish to buy a guardian, it will cost 100 orbs? (Y or N): ";
				cin >> pChoice;

				if (pChoice == "Y")
				{
					User.givePet();
					ifstream pFile("pets.txt");
					Pet.newPet();
					pFile.close();
					User.updateScore(-100);
				}
				//Creates new pet if the user decides to buy one
				else
				{
					cout << "\nSee you later! hopefully you buy a guardian next time!\n" << endl;
					system("pause");
				}
			}
			else if (User.getPet() == "Y")
			{
				cout << "You already have a guardian, you can only have one guardian at a time!\n" << endl;
				system("pause");
			}
			else
			{
				cout << "Sorry you do not have enough orbs to buy a guardian right now" << endl << "Come back when you have 100!\n" << endl;
				system("pause");
			}
		}
		else if (choice == 1997)
		{
			int num;
			cout << "Number of orbs: ";
			cin >> num;
			User.updateScore(num);
			cout << endl;
			system("pause");
			//Cheat function to add points to the user, used for testing.
		}
		else if (choice == 0)
		{
			cout << "\nSee you next time! We hope you enjoyed your visit to the Kingdom" << endl << endl;
		}
		else
		{
			cout << "\nThat is not a valid choice from the menu." <<
				endl <<  "Please pick another option and try again" << endl;
		}
	}	
}

void gameMenu(vector<Pet>& AI, User& User, Pet& Pet) {
	const int MAXHITS = 9;
	const int MAXCOLOUR = 9;
	string colour[MAXCOLOUR];
	string hits[MAXHITS] = { { " " }, { " " }, { " " }, { " " }, { " " }, { " " }, { " " }, { " " }, { " " }, };
	string userhits[MAXHITS] = { { " " }, { " " }, { " " }, { " " }, { " " }, { " " }, { " " }, { " " }, { " " }, };

	int choice = MAXCHOICE;

	while (choice != 0)
	{
		cout << "\nPick an option from the game menu\n" << endl
			<< "0 - Quit" << endl
			<< "1 - Fight in the colluseum! " << endl
			<< "2 - The Rainbow Machine " << endl
			<< "3 - Red or Black" << endl 
			<< "4 - Whack" << endl;

		cout << "\nChoice: ";
		cin >> choice;
		cout << endl;
		
		choice = checkError(choice);
		//Checks for user error via function

		if (choice == 1)
		{
			if (User.getPet() == "Y"){
				fight(AI, User, Pet);
			}
			else
			{
				cout << "You do not have a guardian so you can not play this mode yet, buy a guardian at the Prism!\n" << endl;
				system("pause");
			}
		}
		else if (choice == 2)
		{
			rainbowMachine(User, colour);
			if (User.getPet() == "Y"){
				Pet.PassTime(); //Runs pass time function meaning user must look after pet if they want condition to automatically recover
			}
		}
		else if (choice == 3)
		{
			redBlack(User);
			if (User.getPet() == "Y"){
				Pet.PassTime();
			}
		}
		else if (choice == 4)
		{
			whack(User, hits, userhits);
			if (User.getPet() == "Y"){
				Pet.PassTime();
			}
		}
		else if (choice == 0)
		{
			cout << "See you later " << User.getName() << endl;
		}
		else
		{
			cout << "That is not a valid choice from the menu." <<
				endl << "Please pick another option and try again" << endl;
		}
	}
}

void petMenu (User& User, Pet& Pet) {
	int choice = MAXCHOICE;

	int counter = 0;

	while (choice != 0)
	{
		cout << "\nWhat would you like to do with your guardian today?\n" << endl
			<< "0 - Quit" << endl
			<< "1 - Feed your guardian" << endl
			<< "2 - Visit the doctors" << endl
			<< "3 - Rename your guardian" << endl
			<< "4 - Check your guardian's stats" << endl 
			<< "5 - Visit the armoury"<< endl;
		cout << "\nChoice: ";
		cin >> choice;
		cout << endl;

		choice = checkError(choice);
		
		if (choice == 1)
		{
			int num;
			cout << "How much would you like to feed your guardian? " << endl <<
				"One tin costs an orb and restores 2 hunger to your guardian" << endl <<
				"\nEnter the number of tins you wish to buy: ";
			cin >> num;
			Pet.feedPet(num*2);
			User.updateScore(-num);
		}
		else if (choice == 2)
		{
			cout << "Welcome to the Dark Blue Doctors!" << endl; 
			string Heal;
			cout << "Do you want to heal your guardian 50 health, we can operate for only 12 orbs (Y/N): ";
			cin >> Heal;
			if (Heal == "Y")
			{
				cout << "\nYour guardian is now healed, we have taken your precious orbs to fund the machine." << endl;
				Pet.updateCondition(-50);
				User.updateScore(-12);
				//Updates condition
			}
			else if (Heal == "N")
			{
				cout << "We hope our service was of use to you today, please come back again!" << endl;
			}
			else
			{
				cout << "That was not a valid input, we take it considering the yibberish you just told us you don't wish to heal your guardian!" << endl;
			}
		}
		else if (choice == 3)
		{
			cout << "Your guardian's name is currently: " << Pet.getName() << endl;
			string name;
			cout << "Please enter their new name:" ;
			cin >> name;
			Pet.setName(name);
		}
		else if (choice == 4)
		{
			printStats(Pet);

		} 
		else if (choice == 5)
		{
			armouryMenu(User, Pet);
		}
		else if (choice == 0)
		{
			cout << Pet.getName() << ": See you later " << User.getName() << endl;
		}
		else 
		{
			cout << "\nThat is not a valid choice from the menu." <<
				endl << "Please pick another option and try again" << endl;
		}
	}
}

void armouryMenu(User& User, Pet& Pet){
	cout << "Welcome to the armoury, you can buy armour for your guardian here giving them better stats" << endl;

	int choice = MAXCHOICE;
	
	while (choice != 0)
	{
		cout << "\nWhat would you like to buy your guardian today?\n" << endl
			<< "0 - Quit" << endl
			<< "1 - Buy a helmet" << endl
			<< "2 - Buy armour" << endl
			<< "3 - Buy a sword" << endl
			<< "4 - Buy a shield" << endl
			<< "5 - Check your current items" << endl;

		cout << "\nEnter your choice below:";
		cin >> choice;

		choice = checkError(choice);

		if (choice == 1)
		{
			if (Pet.getItem(0) == "empty")
			{
				cout << "\nYou chose to purchase a helmet!"<< endl 
					<< "They cost 100 orbs and increases your guardian's health by 20" << endl;
				cout << "Do you want to buy one? (Y/N): ";
				string hChoice;
				cin >> hChoice;
				if (hChoice == "Y" && User.getScore() >= 100){
					cout << "\nYou now own a helmet" << endl;
					Pet.giveItem(0);
					Pet.itemModfiers(0, 20, 0);
					//adds modifiers to users pet stats
				}
				else if (hChoice == "Y" && User.getScore() < 100){
					cout << "You do not have enough orbs! Come back when you have more" << endl;
				}
				//Checks for user orbs to see if they can buy an item
				else {
					cout << "Ok maybe you'll buy one in the future, see you again!\n" << endl;
					system("pause");
				}
			}
			else
			{
				cout << "\nYou have already purchased this item, you cannot buy more than one of any item.\n" << endl;
				system("pause");
			}
		}
		if (choice == 2)
		{
			if (Pet.getItem(1) == "empty")
			{
				cout << "\nYou chose to purchase some body armour" << endl 
					<< "It costs 300 orbs and increases your guardian's health by 30" << endl;
				cout << "Do you want to buy one? (Y/N): ";
				string hChoice;
				cin >> hChoice;
				if (hChoice == "Y" && User.getScore() >= 300){
					cout << "\nYou now own some body armour!\n" << endl;
					Pet.giveItem(1);
					Pet.itemModfiers(1, 30, 0);
					system("pause");
				}
				else if (hChoice == "Y" && User.getScore() < 300){
					cout << "You do not have enough orbs! Come back when you have more\n" << endl;
					system("pause");
				}
				else {
					cout << "Ok maybe you'll buy one in the future, see you again!\n" << endl;
					system("pause");
				}
			}
			else
			{
				cout << "\nYou have already purchased this item, you cannot buy more than one of any item." << endl;
			}
		}
		if (choice == 3)
		{
			if (Pet.getItem(2) == "empty")
			{
				cout << "\nYou chose to purchase a sword" << endl 
					<< "It costs 150 orbs and increases your guardian's strength by 30" << endl;
				cout << "Do you want to buy one? (Y/N): ";
				string hChoice;
				cin >> hChoice;
				if (hChoice == "Y" && User.getScore() >= 150)
				{
					cout << "\nYou now own a sword!\n" << endl;
					Pet.giveItem(2);
					Pet.itemModfiers(2, 0, 30);
					system("pause");
				}
				else if (hChoice == "Y" && User.getScore() < 150)
				{
					cout << "You do not have enough orbs! Come back when you have more\n" << endl;
					system("pause");
				}
				else 
				{
					cout << "Ok maybe you'll buy one in the future, see you again!\n" << endl;
					system("pause");
				}
			}
			else
			{
				cout << "\nYou have already purchased this item, you cannot buy more than one of any item." << endl;
			}
		}
		if (choice == 4)
		{
			if (Pet.getItem(3) == "empty")
			{
				cout << "\nYou chose to purchase a shield"<< endl
					<<" It costs 50 orbs and increases your guardian's strength by 5 and health by 5" << endl;
				cout << "Do you want to buy one? (Y/N): ";
				string hChoice;
				cin >> hChoice;
				if (hChoice == "Y" && User.getScore() >= 50)
				{
					cout << "\nYou now own a shield!\n" << endl;
					Pet.giveItem(3);
					Pet.itemModfiers(3, 5, 5);
					system("pause");
				}
				else if (hChoice == "Y" && User.getScore() < 50)
				{
					cout << "You do not have enough orbs! Come back when you have more\n" << endl;
					system("pause");
				}
				else 
				{
					cout << "Ok maybe you'll buy one in the future, see you again!\n" << endl;
					system("pause");
				}
			}
			else
			{
				cout << "\nYou have already purchased this item, you cannot buy more than one of any item.\n" << endl;
				system("pause");
			}
		}
		if (choice == 5){
			printItems(Pet);
			//Prints pet items
		}
	}
}

