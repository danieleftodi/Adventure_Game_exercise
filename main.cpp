#include <iostream>
#include <vector>
#include <string>
#include <stdbool.h>

using namespace std;

int main() {

	string places[10] = { "Camp", "Merchant", "Forest", "Market", "Dungeon",
						  "Lake", "Mountain", ""};
	bool explore = true;
	int playerHP = 100;
	string name;
	cout << "Hello and welcome to Movant RPG!\nPlease enter your name: ";
	cin >> name;
    cout << "Hello " << name << ", let the adventure begin!" << endl;
    cout << "You start att the camp." << endl;
	return 0;
}