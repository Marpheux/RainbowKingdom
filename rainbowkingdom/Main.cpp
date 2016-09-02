#include "User.h"
#include "Pet.h"
#include "Other.h"

using namespace std;

int main()
{
	User User_1;
	Pet Pet_1;
	//Create objects

	vector<Pet> AIPet;
	loadAI(AIPet);
	//Create and load vector
		
	Welcome();
			
	ifstream uFile("user.txt");
	if (!uFile) {
		uFile.close();
		User_1.newUser();
		ifstream uFile("user.txt");
	}
	//Check for user files

	User_1.loadUser(uFile);
	//Load user

	if (User_1.getPet() == "Y") {
		ifstream pFile("pets.txt");
		Pet_1.loadPet(pFile);
		pFile.close();
		ifstream iFile("Items.txt");
		Pet_1.loadItems(iFile);
		iFile.close();
	}
	//Load pet and items
	
	cout << "\nWelcome " << User_1.getName() << endl;
	Menu(AIPet, User_1, Pet_1);
	//Run menu passing in objects

	ofstream outFile("user.txt");
	User_1.saveUser(outFile);
	outFile.close();
	//Save user

	if (User_1.getPet() == "Y") {
		ofstream outFile("pets.txt");
		Pet_1.savePet(outFile);
		outFile.close();
		ofstream itemFile("Items.txt");
		Pet_1.saveItems(itemFile);
		itemFile.close();
	}
	//Save pet

	return 0;
}