#include "User.h"

User::User() {
	userName = "Guest";
	userScore = 10;
	hasPet = "N";
}

User::User(string name, int score, string pet) {
	userName = name;
	userScore = score;
	hasPet = pet;
}

User::~User() {
}

string User::getName() const {
	return userName;
}

int User::getScore() const {
	return userScore;
}

string User::getPet() const {
	return hasPet;
}

void User::updateScore(int Points) {
	userScore += Points;
	if (userScore < 0) {
		cout << "\nYou went in to negative points, so we gave you 5 free orbs!" << endl;
		userScore = 5;
	}
}

void User::setName(string Name) {
	userName = Name;
}

void User::loadUser(ifstream& userFile) {
	userFile >> userName >> userScore >> hasPet;
}

void User::saveUser(ofstream& userFile) {
	userFile << userName << "\t" << userScore << "\t" << hasPet;
}

void User::givePet() {
	hasPet = "Y";
}

void User::newUser() {
	cout << "As you've never played before we need to create a username for you!" << endl;

	ofstream outFile("user.txt");

	string name;
	cout << "Your username: ";
	cin >> name;
	setName(name);

	saveUser(outFile);
	outFile.close();
}
