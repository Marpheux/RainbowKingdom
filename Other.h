#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <Windows.h>

#include "User.h"
#include "Pet.h"

#ifndef OTHER_H
#define OTHER_H

using namespace std;

//Game Prints (Menus.cpp)

void Welcome();
	// Prints Welcome Menu

//Menus (Menus.cpp)

void Menu(vector<Pet>&, User& User, Pet& Pet);
	//Main Menu
void gameMenu(vector<Pet>&, User& User, Pet& Pet);
	//Loads game menu
void petMenu(User& User, Pet& Pet);
	//Loads pet menu
void armouryMenu(User& User, Pet& Pet);
	//loads armoury menu

//AI Functions (AI.cpp)

void loadAI(vector<Pet>&);
	//Loads AI in from file
void printAI(const vector<Pet>&);
	//Prints AI (Used for testing)
void fight(vector<Pet> , User& User, Pet& Pet);
	//Loads the fight game for AI and pet
int calculateAIHit(vector<Pet>&, int);
	//Calculates AI hit
int calculateHit(Pet& Pet);
	//Calculates the pets hit

//Other (Various cpp's)

int RNG(int max);
	//Creates a random number

//Rainbow Machine (RMachine.cpp)

void rainbowMachine(User& User, string *colour);
	//Rainbow machine game, much like fruit machine
void printMachine(string *colour);
	//Prints the screen for the game
void calculateWin(User& User, string *colour);
	//Calculates the users winning and updates the profile

//RedorBlack (RedorBlack.cpp)

void redBlack(User& User);
	//Runs the red or black game

//Whack (Whack.cpp)

void whack(User& User, string *hits, string *userhits);
	//Main whack function, runs prints and other functions
void printGrid(string *hits);
	//Prints the game grid
void calculateHits(string *hits);
	//Calculates the AI hits
void getWhacks(string *userhits, string *hits);
	//Gets the users whacks
int calculateWin(string *userhits, string *hits);
	//Calculates the winning hits
void resetArrays(string *userhits, string*hits);
	//Resets the arrays at the end of a game
void printWin(User& User);
	//Prints win

//User error
int checkError(int uChoice);
	//Checks user error in the menus
string stringError(string Play);
	//Checks user error in games for strings

#endif
