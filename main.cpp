#include <iostream>
#include <string>
#include <cstdbool>
#include <algorithm>
using namespace std;

int main() {
	//global variables
	bool mainProgram = true;
	string playerName;

	//local variables
	bool playerNameLoop = true;
	char tryAgain;

	//premenu enter character name
	while (playerNameLoop)
    		{
	   			cout << "Enter your Character name: ";
	   			cin >> playerName;

	   			cout << "You inputted " << playerName << endl;

	   			cout << "Try Again?(Y/N): ";
	   			cin >> tryAgain;

				tryAgain = (toupper(tryAgain));
	   			if (tryAgain == 'Y')
		  		playerNameLoop = true;

	   			else if (tryAgain == 'N')
		  		playerNameLoop = false;

	   			else
	   			{	
		 		cout << "Your input " << tryAgain << " is not valid.\n";
		  		cout << "This program will assume that you want to continue.\n";
		  		playerNameLoop = true;
	   			}
    		}

	while (mainProgram)
	{
		//local variables
		string userInput;
		
		//Welcome and present options
		cout << "Dibablo 2\n";
		    

		cout << "Choose\n\tAdventure\tArena\t Exit\n";

		//user intput and transform to uppercase 		maby redo to a function!!
		cout << playerName << " input: ";
		cin >> userInput;
		transform(userInput.begin(), userInput.end(), userInput.begin(), ::toupper);

		if (userInput == "ADVENTURE")
		{
				cout << "Welcome to Blood Smoor\n";
		}
		else if (userInput == "BATTLE");
		{
			//local variables
			bool battleProgram = true;

			while (battleProgram)
			{
				//local variables
				string userInput;

				cout << "Welcome to Arena\nChoose monster to fight:\n";
				cout << "Skelleton\t\n";
				
				//user intput and transform to uppercase 		maby redo to a function!!
				cout << playerName << " input: ";
				cin >> userInput;
				transform(userInput.begin(), userInput.end(), userInput.begin(), ::toupper);
				
				if (userInput == "SKELLETON");
				{
					//local variables
					bool skelleton = true;
					while (skelleton)
					{
						"A skeleton attacks!";
					}
				}
			}
		}

	}
	return 0;
}