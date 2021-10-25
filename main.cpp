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

//prototyping functions, declarations are at bottom
void clearScreen();
void pauseScreen();
void delayScreen();
string userInput();
void gameInformation();
void playerNameLoop();

class player 
{
	public:
	string playerName;
	int playerHP{50};
	int playerEXP{400};
};

//global variables
player playerOne;
string Input;

int main() 
{
	//local variables
	bool mainProgram{true};
	vector <string> characterInventory;
	srand(time(0));

	//pre game information screen
	gameInformation();

	//enter character name
	playerNameLoop();

	//The main game starts here
	while(mainProgram)
	{
		clearScreen();
		cout << "Dibablo 2\n";
		cout << "Choose one of the following:\n\nAdventure\nArena\nInventory\n\nQuit\n";

		userInput();

		if(Input == "ADVENTURE")
		{
			//local variables
			bool bloodsmoor = true;

			//location bloodsmore
			while(bloodsmoor)
			{
				clearScreen();
				cout << "Welcome to Blood Smoor\n";
				cout << "Choose one of the following location:\n\n";
				cout << "Chest\n\nExit\n";

				userInput();
				
				if(Input == "CHEST")
				{
					clearScreen();
		 			cout << "You have found a chest!\n";
					cout << "Content:\n\nBlack Cape\n\nKeep Content? (Yes/No)\n";

					userInput();

					if(Input == "YES")
					{
						cout << "\nAdded Black Cape to inventory\n";
						characterInventory.push_back("Black Cape");
						pauseScreen();
					}
					else if(Input == "NO")
					{
						cout << "Throwing away Black Cape";
						pauseScreen();
					}
					//invalid input
					else
					{
						cout << userInput << "Is not valid\n";
						cout << "You just threw away the cape\n";
						pauseScreen();
					}
				}
				else if (Input == "EXIT")
				{
					bloodsmoor = false;
				}
				//invalid input
				else
				{
					cout << userInput << " Is not a valid input!\n";
					pauseScreen();
				}
			}
		}

		else if(Input == "ARENA")
		{
			//local variables
			bool battleProgram = true;

			while(battleProgram)
			{
				clearScreen();
				cout << "Welcome to Arena\nChoose monster to fight:\n\n";
				cout << "Skeleton\n\n\nExit";
				
				userInput();
				
				if(Input == "SKELETON")
				{
					//local variables
					int skeletonHP{25};
					int skeletonAttack{0};
					int playerAttack{0};

					clearScreen();
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

						delayScreen();

						if (playerOne.playerHP <= 0 || skeletonHP <= 0)
						break;
					} 

					//gameover
					if ( playerOne.playerHP < skeletonHP)
					{
						clearScreen();
						cout << "\tYou Died! A Skeleton defeted you!\n";
						cout << "  ________                        ________                     \n";
						cout << " /  _____/_____    _____   ____   \\_____  \\___  __ ___________ \n";
						cout << "/   \\  ___\\__  \\  /     \\_/ __ \\   /   |   \\  \\/ // __ \\_  __ \\\n";
						cout << "\\    \\_\\  \\/ __ \\|  Y Y  \\  ___/  /    |    \\   /\\  ___/|  | \\/\n";
						cout << " \\______  (____  /__|_|  /\\___  > \\_______  /\\_/  \\___  >__|   \n";
						cout << "        \\/     \\/      \\/     \\/          \\/          \\/       \n";
						pauseScreen();
						battleProgram = false;
						mainProgram = false;
					}


					else
					{
						cout << playerOne.playerName << " defeated a skeleton! Congratulations\n";
						cout << "You gain 40 Exp!\n";
						playerOne.playerEXP += 40;
						pauseScreen();
					}
				}
				else if(Input == "EXIT")
				{
					battleProgram = false;
				}

			}
		}

		else if (Input == "INVENTORY")
		{	
			clearScreen();
			cout << "Welcome to your inventory and stats!\n";
			cout << "Name: " << playerOne.playerName << endl;
			cout << "Health: " << playerOne.playerHP << endl;
			cout << "Experiance: " << playerOne.playerEXP << endl << endl;
			cout << "This is what you own:\n\n";

			for (int i = 0; i < characterInventory.size(); i++)
			{
				cout << characterInventory[i] << endl;
			}
			cout << endl;
			pauseScreen();
		}

		else if (Input == "QUIT") mainProgram = false;
		
		//invalid input
		else
		{
			cout << userInput << " Is not a valid input!\n";
			pauseScreen();
		}
	}
	return 0;
}
void gameInformation()
{
	clearScreen();
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
	
	pauseScreen();
}
void playerNameLoop()
{
	//local variables
	bool playerNameLoop{true};
	char tryAgain;

	while(playerNameLoop)
	{	
		clearScreen();
		cout << "Enter your Character name: ";
		cin >> playerOne.playerName;

		cout << "You inputted " << playerOne.playerName << endl;

		cout << "Is this name Correct?(Y/N): ";
		cin >> tryAgain;

		tryAgain = (toupper(tryAgain));
		if (tryAgain == 'Y')
		{
			playerNameLoop = false;
		}	
		else if (tryAgain == 'N')
		{
			playerNameLoop = true;
			clearScreen();
		}
		else
		{	
			playerNameLoop = true;
		}
	}
}
string userInput()
{
	cout << endl;
	cout << playerOne.playerName << " input: ";
	cin >> Input;
	transform(Input.begin(), Input.end(), Input.begin(), ::toupper);
	return Input;
}
void clearScreen()
{
	#ifdef _WIN32
		system("cls");
	#else
		system("clear");
	#endif
}
void pauseScreen()	
{
	char cInputPause = '\0';
	#ifdef _WIN32
		system("pause");
	#else
		cout << "Press any key to continue [Followed by Enter]: \n";
		cin >> (cInputPause);
	#endif	
}
void delayScreen()
{
	#ifdef _WIN32
		Sleep(150);
	#else
		sleep(150);
	#endif
}