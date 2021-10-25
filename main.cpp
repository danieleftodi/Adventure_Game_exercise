#include <iostream>
#include <string>
#include <cstdbool>
#include <algorithm>
#include <vector>
#include <time.h>

#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif

using namespace std;

//global variables

class player 
{
	public: 
	string playerName;
	int playerHP{50};
	int playerEXP{400};
};


int main() {
	//local variables (global for main function)
	//string playerName;
	bool mainProgram{true};
	bool gameInformation{true};
	bool playerNameLoop{true};
    char cInputPause = '\0';
	vector <string> characterInventory;
	player playerOne;
	srand(time(0));


	while(gameInformation)
	{
		//local variablies
		string userInput;

		#ifdef _WIN32
        system("cls");
		#else
        system("clear");
		#endif
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
		
		#ifdef _WIN32
        system("pause");
		#else
        cout << "Press any key to continue [Followed by Enter]: \n";
        cin >> (cInputPause);
		#endif

		gameInformation = false;
	}
	while(playerNameLoop)
    		{
				//local variables
				char tryAgain;


				#ifdef _WIN32
                system("cls");
				#else
                system("clear");
				#endif

	   			cout << "Enter your Character name: ";
	   			cin >> playerOne.playerName;

	   			cout << "You inputted " << playerOne.playerName << endl;

	   			cout << "Is this name Correct?(Y/N): ";
	   			cin >> tryAgain;

				tryAgain = (toupper(tryAgain));
	   			if (tryAgain == 'Y') playerNameLoop = false;
		  		
	   			else if (tryAgain == 'N')
		  		{
                    playerNameLoop = true;

					#ifdef _WIN32
                    system("cls");
					#else
                    system("clear");
					#endif
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
		

		#ifdef _WIN32
        system("cls");
		#else
        system("clear");
		#endif
		cout << "Dibablo 2\n";
		    

		cout << "Choose one of the following:\n\nAdventure\nArena\nInventory\n\nQuit\n";

		
		//user intput and transform to uppercase 		maby change to a function!!
		cout << endl;
		cout << playerOne.playerName << " input: ";
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

				#ifdef _WIN32
                system("cls");
				#else
                system("clear");
				#endif
				cout << "Welcome to Blood Smoor\n";
				cout << "Choose one of the following location:\n\n";
				cout << "Chest\n\nExit\n";

				//user intput and transform to uppercase 		maby redo to a function!!
				cout << endl;
				cout << playerOne.playerName << " input: ";
				cin >> userInput;
				transform(userInput.begin(), userInput.end(), userInput.begin(), ::toupper);
				
				if(userInput == "CHEST")
				{
					//local variables
					string userInput;

					#ifdef _WIN32
                    system("cls");
					#else
                    system("clear");
					#endif
		 			cout << "You have found a chest!\n";
					cout << "Content:\n\nBlack Cape\n\nKeep Content? (Yes/No)\n";

					//user intput and transform to uppercase 		maby redo to a function!!
					cout << endl;
					cout << playerOne.playerName << " input: ";
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
					//invalid input
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
				//invalid input
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

				#ifdef _WIN32
                system("cls");
				#else
                system("clear");
				#endif
				cout << "Welcome to Arena\nChoose monster to fight:\n\n";
				cout << "Skeleton\n\n\nExit";
				
				//user intput and transform to uppercase 		maby redo to a function!!
				cout << endl;
				cout << playerOne.playerName << " input: ";
				cin >> userInput;
				transform(userInput.begin(), userInput.end(), userInput.begin(), ::toupper);
				
				if(userInput == "SKELETON")
				{
					//local variables
					int skeletonHP{25};
					int skeletonAttack{0};
					int playerAttack{0};

					#ifdef _WIN32
                    system("cls");
					#else
                    system("clear");
					#endif
					cout << "A wild skeleton attacks\n";

					while (playerOne.playerHP >= 0 && skeletonHP >= 0)
					{
						//player attacks
						playerAttack = rand() % 10 + 1;
						skeletonHP -= playerAttack;

						//skeleton attacks
						skeletonAttack = rand() % 4 + 1;
						playerOne.playerHP -= skeletonAttack;

						cout << playerOne.playerName << " Attacks Skeleton for: " << playerAttack << ". Skeleton has " << skeletonHP << " left. Skeleton attacks " 
						<< playerOne.playerName << " for: " << skeletonAttack << " " << playerOne.playerName << " has " << playerOne.playerHP << " left.\n\n";

						#ifdef _WIN32
                        Sleep(150);
						#else
                        sleep(150);
						#endif
                        

						if (playerOne.playerHP <= 0 || skeletonHP <= 0)
						break;
					} 

					//gameover
					if ( playerOne.playerHP < skeletonHP)
					{
						#ifdef _WIN32
                        system("cls");
						#else
                        system("clear");
						#endif
						cout << "\tYou Died! A Skeleton defeted you!\n";
						cout << "  ________                        ________                     \n";
						cout << " /  _____/_____    _____   ____   \\_____  \\___  __ ___________ \n";
						cout << "/   \\  ___\\__  \\  /     \\_/ __ \\   /   |   \\  \\/ // __ \\_  __ \\\n";
						cout << "\\    \\_\\  \\/ __ \\|  Y Y  \\  ___/  /    |    \\   /\\  ___/|  | \\/\n";
						cout << " \\______  (____  /__|_|  /\\___  > \\_______  /\\_/  \\___  >__|   \n";
						cout << "        \\/     \\/      \\/     \\/          \\/          \\/       \n";
						system("pause");
						battleProgram = false;
						mainProgram = false;
					}


					else
					{
						cout << playerOne.playerName << " defeated a skeleton! Congratulations\n";
						cout << "You gain 40 Exp!\n";
						playerOne.playerEXP += 40;
						system("pause");
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
			#ifdef _WIN32
            system("cls");
			#else
            system("clear");
			#endif
			cout << "Welcome to your inventory and stats!\n";
			cout << "Player Name: " << playerOne.playerName << endl;
			cout << "Player Experiance: " << playerOne.playerEXP << endl << endl;
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
