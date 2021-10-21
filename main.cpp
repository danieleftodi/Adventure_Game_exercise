#include <iostream>
#include <string>
#include <cstdbool>
#include <algorithm>
#include <vector>
using namespace std;

//global variables


int main() {
	//local variables (global for main function)
	string playerName;
	bool mainProgram{true};
	bool playerNameLoop{true};
	bool gameInformation{true};
	vector <string> characterInventory;
	int playerHP{50};
	int skeletonHP{25};


	while(gameInformation)
	{
	//local variablies
		string userInput;

		system("cls");
		cout << "________  ._____.         ___.   .__           ________\n";
		cout << "\\______ \\ |__\\_ |__ _____ \\_ |__ |  |   ____   \\_____  \\\n";
		cout << " |    |  \\|  || __ \\__   \\ | __ \\|  |  /  _ \\   /  ____/\n";
		cout << " |    `   \\  || \\_\\ \\/ __ \\| \\_\\ \\  |_(  <_> ) /       \\ \n";
		cout << "/_______  /__||___  (____  /___  /____/\\____/  \\_______ \\\n";
		cout << "        \\/        \\/     \\/    \\/                      \\/\n";
		cout << "\t\tAuther Adam\n\n\n";

		cout << "Game Information:\n";
		cout << "This is a school project of mine, dont judge it to hard :)\n";
		cout << "The game is designed to not be case sensitive\n";
		cout << "All your input can be either small or large characters\n";
		cout << "Or a combination of both\n";
		cout << "\nAlso please play the game in external console\n";
		cout << "Otherwise my system clear screen wont work :)";
		cout << endl << endl;
		
		system("pause");
		gameInformation = false;
	}
	while(playerNameLoop)
    		{
				//local variables
				char tryAgain;

				system("cls");
	   			cout << "Enter your Character name: ";
	   			cin >> playerName;

	   			cout << "You inputted " << playerName << endl;

	   			cout << "Is this name Correct?(Y/N): ";
	   			cin >> tryAgain;

				tryAgain = (toupper(tryAgain));
	   			if (tryAgain == 'Y')
		  		playerNameLoop = false;

	   			else if (tryAgain == 'N')
		  		{
				  playerNameLoop = true;
				  system("cls");
				}
	   			else
	   			{	
		 		cout << "Your input " << tryAgain << " is not valid.\n";
		  		cout << "This program will assume that you want to continue.\n";
		  		playerNameLoop = true;
	   			}
    		}
	//The game
	while(mainProgram)
	{
		//local variables
		string userInput;
		
		system("cls");
		cout << "Dibablo 2\n";
		    

		cout << "Choose one of the following:\n\nAdventure\nArena\nInventory\n\nQuit\n";

		
		//user intput and transform to uppercase 		maby change to a function!!
		cout << endl;
		cout << playerName << " input: ";
		cin >> userInput;
		transform(userInput.begin(), userInput.end(), userInput.begin(), ::toupper);

		if(userInput == "ADVENTURE")
		{
			//local variables
			bool bloodsmoor = true;

			while(bloodsmoor)
			{
				//local variables
				string userInput;

				system("cls");
				cout << "Welcome to Blood Smoor\n";
				cout << "Choose one of the following location:\n\n";
				cout << "Chest\n\nExit\n";

				//user intput and transform to uppercase 		maby redo to a function!!
				cout << endl;
				cout << playerName << " input: ";
				cin >> userInput;
				transform(userInput.begin(), userInput.end(), userInput.begin(), ::toupper);

				if(userInput == "CHEST")
				{
					//local variables
					string userInput;

					system("cls");
		 			cout << "You have found a chest!\n";
					cout << "Content:\n\nBlack Cape\n\nKeep Content? (Yes/No)\n";

					//user intput and transform to uppercase 		maby redo to a function!!
					cout << endl;
					cout << playerName << " input: ";
					cin >> userInput;
					transform(userInput.begin(), userInput.end(), userInput.begin(), ::toupper);

					if(userInput == "YES")
					{
						cout << "\nAdded Black Cape to inventory\n";
						characterInventory.push_back("Black Cape");
						system("pause");
					}

					else if(userInput == "NO")
					{
						cout << "Throwing away Black Cape";
						system("pause");
					}

					else
					{
						cout << userInput << "Is not valid\n";
						cout << "You just threw away the cape\n";
						system("pause");
					}
				}

				else if (userInput == "EXIT")
				{
					bloodsmoor = false;
				}
				
				else
				{
					cout << userInput << " Is not a valid input!\n";
					cout << "Try Again!\n";
					system("pause");
				}
			}
		}
		else if(userInput == "ARENA")
		{
			//local variables
			bool battleProgram = true;

			while(battleProgram)
			{
				//local variables
				string userInput;

				system("cls");
				cout << "Welcome to Arena\nChoose monster to fight:\n\n";
				cout << "Skeleton\n\n\nExit";
				
				//user intput and transform to uppercase 		maby redo to a function!!
				cout << endl;
				cout << playerName << " input: ";
				cin >> userInput;
				transform(userInput.begin(), userInput.end(), userInput.begin(), ::toupper);
				
				if(userInput == "SKELETON")
				{
					//local variables
					bool skelleton = true;

					while(skelleton)
					{
						cout << "A skeleton attacks!";
						skelleton = false;
					}
				}
				else if(userInput == "EXIT")
				{
					battleProgram = false;
				}

			}
		}
		else if (userInput == "INVENTORY")
		{	
			system("cls");
			cout << "Welcome to your inventory!\n";
			cout << "This is what you own:\n\n";

			for (int i = 0; i < characterInventory.size(); i++)
			{
				cout << characterInventory[i] << endl;
			}
			cout << endl;
			system("pause");
		}
		else if (userInput == "QUIT")
		mainProgram = false;

		//invalid input
		else
		{
			cout << userInput << " Is not valid\n";
			cout << "Try Again\n";
			system("pause");
		}
	}
	return 0;
}