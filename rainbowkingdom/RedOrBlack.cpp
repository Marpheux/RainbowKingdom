#include "Other.h"

void redBlack(User& User) {
	cout << "\t\tWelcome to Red or Black" << endl
		<< "\nThis is a simple minigame where you bet for red or black" << endl
		<< "If you win you will earn 5 orbs, if you lose you will lose 1 orb\n" << endl;

	system("Pause");

	string playAgain;

	while (playAgain != "N")
	{
		string choice;
		cout << "\nPlace your bet, red or black: ";
		cin >> choice;
		int counter = 0;

		while (choice != "red" && choice != "black"){
			cout << "That was invalid input please enter your choice correctly!" << endl;
			cout << "\nPlace your bet, red or black: ";
			cin.clear();
			cin.ignore();
			cin >> choice;
			//Checks for user input to see if it's clear 
		}

		int colour = RNG(2);

		if (colour == 1 && choice == "red"){
			cout << "\nCongratulations you made the right choice and red wins!" << endl;
			cout << "You won 3 orbs!" << endl;
			User.updateScore(3);
		}
		else if (colour == 2 && choice == "black"){
			cout << "\nCongratulations you made the right choice and black wins!" << endl;
			cout << "You won 3 orbs!" << endl;
			User.updateScore(3);
		}
		else {
			cout << "\nUnfortunately you guessed incorrectly losing 1 orb" << endl;
			User.updateScore(-2);
		}
		cout << "\nDo you want to play again? (Y/N): ";
		cin >> playAgain;
		playAgain = stringError(playAgain);
	}
}