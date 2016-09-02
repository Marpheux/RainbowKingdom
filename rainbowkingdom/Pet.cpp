#include "Pet.h"


Pet::Pet(){
	petHunger = 0;
	petCondition = 100;
	petStrength = 10;
	petLevel = 1;
}

Pet::Pet(string name, int hunger, int condition, int strength, int level){
	petName = name;
	petHunger = hunger;
	petCondition = condition;
	petStrength = strength;
	petLevel = level;
}

Pet::Pet(string name, int condition, int strength) {
	petName = name;
	petCondition = condition;
	petStrength = strength;
}

Pet::~Pet() {
}

string Pet::getName() const {
	return petName;
}

int Pet::getHunger() const {
	return petHunger;
}

int Pet::getCondition() const {
	return petCondition;
}

int Pet::getStrength() const{
	return petStrength;
}

int Pet::getLevel() const{
	return petLevel;
}

string Pet::getItem(int num) const{
	return petItems[num];
}

void Pet::PassTime() {
	petHunger += 2;
	if (petHunger <= 25 && petCondition < 100)
	{
		petCondition += 5;
	}
}

void Pet::setName(string name) {
	petName = name;
}

void Pet::feedPet(int food) {
	if (food > 5) 
	{
		food = 5;
	}
	if (petHunger > 0){
		petHunger -= food;
	}
}

void Pet::updateStrength(int number) {
	petStrength += number;
}

void Pet::updateLevel() {
	
	if (petLevel > 10) {
		petLevel = 10;
		cout << "\n You have levelled your guardian to the max level" << endl;
	}
	else
	{
		cout << "\nCongratulations you have levelled your pet up to the next level!" << endl;
		petLevel += 1;
	}
}

void Pet::updateCondition(int number) {
	petCondition -= number;
}

void Pet::setCondition(int number) {
	petCondition = number;
}

void Pet::giveItem(int number) {
	petItems[number] = "bought";
}

void Pet::itemModfiers(int num, int health, int strength) {
	if (petItems[num] == "bought"){
		petCondition += health;
		petStrength += strength;
	}
}

void Pet::loadPet(ifstream& petFile) {
	petFile >> petName >> petHunger >> petCondition >> petStrength >> petLevel;
}

void Pet::savePet(ofstream& petFile) {
	petFile << petName << "\t" << petHunger << "\t" << petCondition <<"\t" << petStrength << "\t" << petLevel;
}

void Pet::newPet() {
	cout << "\nCongratulations on buying the new guardian!" << endl;

	ofstream outFile("pets.txt");

	string name;
	cout << "\nWe now need to name your guardian" << endl << "Name for guardian: ";
	cin >> name;
	cout << endl;
	setName(name);

	savePet(outFile);
	outFile.close();
}

void Pet::loadItems(ifstream& itemFile){
	string item;
	for (int i = 0; i < MAXITEMS; i++){
		itemFile >> item;
		petItems.push_back(item);
	}
}

void Pet::saveItems(ofstream& itemFile){
	for (int i = 0; i < MAXITEMS; i++) {
		itemFile << petItems[i] << endl;
	}
}

void printItems(Pet& Pet) {
	cout << "\nHere are " << Pet.getName() << "'s items" << endl;
	cout << "\nHelmet: " << Pet.getItem(0) << endl;
	cout << "Armour: " << Pet.getItem(1) << endl;
	cout << "Sword: " << Pet.getItem(2) << endl;
	cout << "Shield " << Pet.getItem(3) << endl;
}

void printStats(Pet& Pet) {
	cout << "\nHere are " << Pet.getName() << "'s stats" << endl;
	cout << "\nHunger: " << Pet.getHunger() << endl;
	cout << "Health: " << Pet.getCondition() << endl;
	cout << "Strength: " << Pet.getStrength() << endl;
	cout << "Level: " << Pet.getLevel() << endl;
}