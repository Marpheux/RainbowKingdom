#include "Other.h"

const int MAXHITS = 9;
string hits[MAXHITS] = { { " " }, { " " }, { " " }, { " " }, { " " }, { " " }, { " " }, { " " }, { " " }, };
string userhits[MAXHITS];

void whack(User& User, string *hits, string *userhits)
{
	string playAgain;
	cout << "\n\t\tWelcome to Whack!" << endl;
	cout << "\nIn this game you must guess where the computer will hit" << endl;
	cout << "You guess 3 times and earn 2 orbs for every correct guess" << endl;
	cout << "You will lose an orb however if you get no correct guesses!\n" << endl;

	system("Pause");

	while (playAgain != "N")
	{
		printGrid(hits);
		getWhacks(userhits, hits);
		calculateHits(hits);
		system("pause");
		cout << "\t\tEnemy whacks" << endl;
		printGrid(hits);
		int playerHits = calculateWin(userhits, hits);
		cout << "You got " << playerHits << " whacks" << endl;

		if (playerHits != 0)
		{
			cout << "We have gifted you " << (playerHits * 2) << " orbs!" << endl;
			User.updateScore(playerHits * 2);
		}
		else
		{
			cout << "Better luck next time, you have lost 1 orb!" << endl;
			User.updateScore(-1);
		}

		cout << "\nDo you want to play again? (Y/N): ";
		cin >> playAgain;
		playAgain = stringError(playAgain);
		resetArrays(userhits, hits);
	}

	cout << "\nSee you later!" << endl;
}

void printGrid(string *hits)
{
	char under = '_';
	char space = ' ';
	int num = 1;

	cout << "\t\t  " << "_____" << endl;
	cout << "\t\t |" << "Whack" << "|" << endl;
	cout << "\t\t |" << "_____|" << endl;
	cout << "\t\t |" << hits[0] << "|" << hits[1] << "|" << hits[2] <<"|" << endl;
	cout << "\t\t |" << hits[3] << "|" << hits[4] << "|" << hits[5] <<"|" << endl;
	cout << "\t\t |" << hits[6] << "|" << hits[7] << "|" << hits[8] <<"|" << endl;
	cout << "\t\t |_|_|_|"<< endl;
	cout << endl;
}

void calculateHits(string *hits){
	int totalHits = 3;

	for (int i = 0; i < totalHits; i++){
		int random = (RNG(9)-1);
			hits[random] = "x";
			Sleep(100);
	}
}

void getWhacks(string *userhits, string *hits) {
	int totalHits = 3;
	int counter = 1;
	
	for (int i = 0; i < totalHits; i++)
	{
		int choice = 0;
		cout << "Choice " << counter << ": ";
		cin >> choice;
		int counter = 0;

		while (cin.fail() || choice <= 0 || choice > 9 || userhits[choice-1] == "o")
		{
			if (counter == 0){
				cout << "The choice you've entered was invalid! please enter a number (1-9)" << endl;
				cout << "\nChoice: ";
				counter++;
			}
			cin.clear(); //Clears errors
			cin.ignore(); //Ignores current input and discards it (Reset)
			cin >> choice;
		}
		
		userhits[choice - 1] = "o";
		
		printGrid(userhits);
		counter++;
	}
}

int calculateWin(string *userhits, string *hits) {
	int pHits = 0;
	for (int i = 0; i < MAXHITS; i++) {
		if (userhits[i] == "o" && hits[i] == "x")
		{
			pHits++;
		}
	}
	return pHits;
}

void resetArrays(string *userhits, string*hits) {
	for (int i = 0; i < MAXHITS; i++)
	{
		userhits[i] = " ";
		hits[i] = " ";
	}
}