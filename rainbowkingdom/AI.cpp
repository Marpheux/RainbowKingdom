#include "Other.h"

void loadAI(vector<Pet>& newAI) {
	string name;
	int condition;
	int strength;
	//Creates variables

	ifstream AIFile("AI.txt");

	int AILoaded = 10;

	for (int i = 0; i < AILoaded; i++)
	{
		AIFile >> name >> condition >> strength;
		Pet AIPet(name, condition, strength);
		newAI.push_back(AIPet);
	}
	//Load AI and push in them into vector
	AIFile.close();
}

void printAI(const vector<Pet>& AI) {
	int size = AI.size();

	for (int i = 0; i < size; i++)
	{
		cout << "AI Name: " << AI[i].getName() << endl;
		cout << "AI Condition: " << AI[i].getCondition() << endl;
		cout << "Strength: " << AI[i].getStrength() << endl;
		cout << endl;
	}
	//Print AI array used for testing
}

void fight(vector<Pet> AI, User& User, Pet& Pet) {
	//Uses pets level to decide on the types of AI it may play
	int random = RNG(Pet.getLevel());

	cout << "Welcome to the colourful colluseum!" << endl
		<< "Today our two contestants, " << Pet.getName() << " and " << AI[random].getName() << " will battle it out!" << endl
		<< "May the best critter win!" << endl;

	int counter = 1;
	bool turn10 = false;

	while (Pet.getCondition() > 0 && AI[random].getCondition() > 0)
	{
		cout << "\nPress enter to play! ";
		cin.ignore();

		int AIHit = calculateAIHit(AI, random);
		Sleep(100);
		//Sleeps to change the modifier of the RNG function, gettickcount works by miliseconds.
		int PHit = calculateHit(Pet);

		cout << "\nTurn " << counter << endl;

		cout << "\nYour pet has " << Pet.getCondition() << " health left" << endl;
		cout << "The enemy has " << AI[random].getCondition() << " health left" << endl;
		cout << endl;
		
		if (counter >= 10) {

			if (turn10 == false){
				cout << "\nYou and the enemy weaken from the length of the battle" << endl
					<< "Hits now do triple damage" << endl;
				turn10 = true;
				//makes true so text only prints one round.
			}

			cout << Pet.getName() << " just hit for " << (PHit * 3) << " damage!" << endl;
			cout << AI[random].getName() << " just hit for " << (AIHit * 3) << " damage on your guardian!" << endl;
			
			AI[random].updateCondition(PHit * 3);
			Pet.updateCondition(AIHit * 3);
			//Times hit values by 3 
		}
		else 
		{
			cout << Pet.getName() << " just hit for " << (PHit) << " damage!" << endl;
			cout << AI[random].getName() << " just hit for " << (AIHit) << " damage on your guardian!" << endl;

			AI[random].updateCondition(PHit);
			Pet.updateCondition(AIHit);
			//Update pet health based on random hit
		}
		counter++;
	}

	if (Pet.getCondition() <= 0) {
		cout << "\nAw shucks, it appears that your pet got knocked out!" << endl;
		cout << "The medics managed to put you back together but your guardian will need looking after for some time before he's ready to fight again!" << endl;
		Pet.setCondition(50);
		//Loser text
	}
	else
	{
		cout << "\nCongratulations, you have defeated the enemy!" << endl;
		cout << "The game masters have rewarded you with a crate of treasures and 20 orbs!" << endl;

		cout << "\nPress enter to open the crate! " << endl;
		cin.ignore();
		//Winner text

		int crate = RNG(4);
		//Random chance for user to level up below

		if (crate == 4)
		{
			cout << "\nYou found a mystical item within the box, as your guardian picks up the item he feels a wave of power fill through him" <<endl;
			Pet.updateLevel();
			Pet.updateStrength(10);
			cout << "The box also contained 50 extra orbs!" << endl;
		}
		else
		{
			cout << "\nUnfortunately the crate contained treasures of no worth, better luck next time" << endl;
		}
		Pet.setCondition(100);
		Pet.PassTime();
	}
}

int calculateAIHit(vector<Pet>& AI, int random) {
	int random1 = RNG(10);
	int hit = (AI[random].getStrength() / random1);
	return hit;
	//Calculates AI hit by using a random number, divides the strength by a random modifier of 10
}

int calculateHit(Pet& Pet) {
	int random1 = RNG(10);
	int hit = (Pet.getStrength() / random1);
	return hit;
	//Calculates user hit
}

int RNG(int max) {
	int random;

	srand(GetTickCount()); //gettickcount works by counting miliseconds since system start, used to make random seed off miliseconds.
	random = 1 + (rand() % max);
		
	return random;
	//Random function generatres random number based of miliseconds
}
