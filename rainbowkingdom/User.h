#pragma once
#ifndef USER_H
#define USER_H

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class User
{
public:
	//Default constructor
	User();

	//Overload constructor
	User(string, int, string);

	//Destructor
	~User();

	//Accessor Functions
	string getName() const;
		//Returns name of user
	int getScore() const;
		//Returns score of user
	string getPet() const;
		//Tells program if the user has pet or not

	//Mutator Functions

	void updateScore(int);
		//Allows score to be updated for each game (negative or plus)
	void setName(string);
		//Sets the username of user
	void givePet();
		//Changes users pet value
	void newUser();
		//Creates a new user if they have never played before
	void loadUser(ifstream& userFile);
		//Loads user information
	void saveUser(ofstream& userFile);
		//Saves user information

private:
	string userName;
	int userScore;
	string hasPet;
};

#endif

