#pragma once
#ifndef PET_H
#define PET_H

#include "User.h"
#include <vector>
#include <string>

using namespace std;

const int MAXITEMS = 4;

class Pet
{
public:
	 
	//Default Constructor
	Pet();
	//Overload Constructor
	Pet(string, int, int, int, int);
	//Overload Constructor - AI
	Pet(string, int, int);
	//Destructor
	~Pet();

	//Accessor Functions

	string getName() const;
		//Returns name of pet
	int getHunger() const;
		//Returns hunger of pet
	int getCondition() const;
		//Returns condition of pet as an integer
	int getStrength() const;
		//Returns strength of pet
	int getLevel() const;
		//Returns level of pet
	string getItem(int num) const;
		//Returns item from vector

	//Mutator Functions

	void PassTime();
		//Passes Time for the pet adding to attributes such as hunger etc.
	void setName(string);
		//Sets name of pet
	void feedPet(int);
		//Allows user to feed pet, reducing hunger
	void updateStrength(int);
		//Grants the users pet extra strength
	void updateLevel();
		//Grants the users pet an extra level
	void updateCondition(int);
		//Updates condition based on strength
	void setCondition(int);
		//Sets a number as the condition
	void giveItem(int);
		//Gives an item to the user
	void itemModfiers(int, int, int);
		//Adds modifiers from items

	//File handling functions

	void savePet(ofstream& petFile);
		//Saves the pets details
	void loadPet(ifstream& petFile);
		//Loads the pets details
	void newPet();
		//Creates a new pets details!
	void saveItems(ofstream& itemFile);
		//Saves the pets items
	void loadItems(ifstream& itemFile);
		//Loads the pets items

private:
	string petName;
	int petHunger;
	int petCondition;
	int petStrength;
	int petLevel;
	vector <string> petItems;
};

#endif

void printStats(Pet& Pet);
	//Prints pets stats
void printItems(Pet& Pet);
	//Prints pets items
