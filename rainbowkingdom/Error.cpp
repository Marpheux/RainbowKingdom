#include "Other.h"

string stringError(string play){
	while (play != "Y" && play != "N")
	{
		cout << "That is invalid input please enter your choice correctly! " << endl;
		cout << "\nDo you want to play again? (Y/N): ";
		cin.clear();
		cin.ignore();
		cin >> play;
	}
	return play;
}

int checkError(int uChoice){
	int counter = 0;
	while (cin.fail())
	{
		if (counter == 0){
			cout << "\nThe choice you've entered was invalid! please enter a valid choice!" << endl;
			cout << "\nChoice: ";
			counter++;
		}
		cin.clear(); //Clears errors
		cin.ignore(); //Ignores current input and discards it (Reset)
		cin >> uChoice;
	}
	return uChoice;
}