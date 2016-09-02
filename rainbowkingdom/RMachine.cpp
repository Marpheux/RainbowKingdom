#include "Other.h"

void rainbowMachine(User& user, string *colour) {
	cout << "\t\tWelcome to the Rainbow Machine" << endl;
	cout << "\nIn this game the rainbow machine will generate colours" << endl;
	cout << "If you get 3 of the same colour in a row you win the COLOURPOT" << endl;
	cout << "If you get 3 of red, green, or blue you win 5 orbs!" << endl;
	cout << "\nGood Luck!\n" << endl;

	system("Pause");

	string playAgain;

	while (playAgain != "N"){
		printMachine(colour);
		calculateWin(user, colour);
		cout << "\nDo you want to play again? (Y/N): ";
		cin >> playAgain;
		playAgain = stringError(playAgain);
	}

	cout << "\nSee you later!" << endl;
}

void printMachine(string *colour) {
	char under = '_';
	char space = ' ';
	
	string colours[7] {{"  Red  "}, { " Orange" }, { " Yellow" }, { " Green " }, { " Blue  " }, { " Indigo" }, { " Violet" }};


	for (int i = 0; i < 9; i++)
	{
			int random = RNG(6);
			colour[i] = colours[random];
			Sleep(100);
	}
	int num = 7;

	//Prints the board, changes size according to word printed

cout << "\t\t  __" << string(num, under) << "_____"<< string(num, under) <<"_____"<< string(num, under) <<"____ " << endl;
cout << "\t\t |  " << string(num, space) << "     " << "Rainbow"         <<"     "<< string(num, space) <<"    |" << endl;
cout << "\t\t |  " << string(num, space) << "     " << "Machine"         <<"     "<< string(num, space) <<"    |" << endl;
cout << "\t\t |__" << string(num, under) << "_____"<< string(num, under) <<"_____"<< string(num, under) <<"____|" << endl;
cout << "\t\t |  " << colour[0] << "  |   " << colour[3] << "   |  " << colour[6] << "  |" << endl;
cout << "\t\t |  " << colour[1] << "  |   " << colour[4] << "   |  " << colour[7] << "  |" << endl;
cout << "\t\t |  " << colour[2] << "  |   " << colour[5] << "   |  " << colour[8] << "  |" << endl;
cout << "\t\t |__" << string(num, under) << "__|___"<< string(num, under) <<"___|__"<< string(num, under) <<"__|" << endl;
cout << endl;
}

void calculateWin(User& User ,string *colour){
	int red = 0; int green = 0; int blue = 0;
	if (colour[0] == colour[3] && colour[3] == colour[6])
	{
		printWin(User);
	}
	else if (colour[1] == colour[4] && colour[4] == colour[7])
	{
		printWin(User);
	}
	else if (colour[2] == colour[5] && colour[5] == colour[8])
	{
		printWin(User);
	}
	else if (colour[0] == colour[1] && colour[1] == colour[2])
	{
		printWin(User);
	}
	else if (colour[3] == colour[4] && colour[4] == colour[5])
	{
		printWin(User);
	}
	else if (colour[6] == colour[7] && colour[7] == colour[8])
	{
		printWin(User);
	}
	else
	{
		cout << "Unfortunately you lost!" << endl;
		for (int i =0 ; i < 9; i++)
		{
			if (colour[i] == "  Red  "){
				red++;
			}		
			else if (colour[i] == " Green ") {
				green++;
			}
			else if (colour[i] == " Blue  ") {
				blue++; 
			}
		}
		if (red >= 3 ||  green >= 3 || blue >= 3)
		{
			cout << "\nYou won the RGB card getting more than 3 of any of red green and blue" << endl;
			cout << "We'll give you 5 orbs for winning the RGB card!" << endl;
			User.updateScore(3);
			//Checks for winner and updates score
		}
		else
		{
			User.updateScore(1);
			cout << "You lost an orb, better luck next time!" << endl;
		}
	}
}

void printWin(User& User) {
	cout << "\nCongratulations you won the COLOURPOT!" << endl;
	cout << "That's worth a total of 50 orbs!" << endl;
	User.updateScore(50);
}
