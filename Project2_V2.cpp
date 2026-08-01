#include <iostream>
#include <iomanip>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

// PHASE 1: REORGANIZE THE EXISTING GAME
// [ ] Add function prototypes above main.
// [ ] Move the rules into displayRules().
// [ ] Move the die artwork into displayDie().
// [ ] Move random rolling into rollDie().
// [ ] Move score output into displayScores().
// [ ] Move input validation into menu functions.
// [ ] Move the computer's strategy into its own function.
// [ ] Keep all variables local; DO NOT use global variables.

// I NEED TO GET A MENU. 
// cout << "\nMAIN MENU\n";
//  cout << "---------\n";
//   cout << "[P] Play Game\n";
//   cout << "[R] Read Rules\n";
//    cout << "[Q] Quit\n";

// VARIABLES ************************************
void title();
char menu();
void rules();

int mode();
int ndice();
int goal(int score = 100);

int roll();
bool play(int mode, int winscr, int nDice);

// MAIN *****************************************

int main(){
    srand(static_cast<unsigned int>(time(0)));
    int winscr;
    char choice;

    do
    {
        choice = menu(); // Display main menu

        switch(choice)
        {
            case 'P':
            case 'p':
            // play the game
                break;

            case 'R':
            case 'r':
            //display rules
                rules();
                break;

            case 'Q':
            case 'q':
                cout << "Thanks for playing!\n";
                // quit game
                break;
            
            default:
                cout << "Invalid choice!\n";

        }

    } while(choice !='Q' && choice != 'q');

    return 0;
}

// Function Defintions 




//TITLE
void title()
{
    cout << "\t=========================" << endl;
	cout << endl;
	cout << "\t\tGAME OF PIG" << endl;
	cout << endl;
	cout << "\t=========================\n" << endl;
	
}


// MENU
char menu()
{
    title();
    char choice;
    cout << "[P] Play Game\t";
    cout << "[R] Read Rules\t";
    cout << "[Q] Quit\n";
    cout << "\nEnter your choice: \n";
    cin >> choice;

    return choice;
}
// RULES 
void rules()
{
    char choice;

    do
    {
        cout << "\nHOW TO PLAY\n";
        cout << "-----------\n";
        cout << "You and the computer take turns rolling one die.\n";
        cout << "Rolling 2 through 6 adds points to your round score.\n";
        cout << "Choose R to roll again or H to hold your points.\n";
        cout << "Holding adds your round points to your total score.\n";
        cout << "Rolling a 1 loses your round points and ends your turn.\n";
        cout << "The first player to reach the desired amount of points wins!\n\n";

        cout << "[M] Return to Main Menu"
         << "\t[P] Play Game\n";

         cin >> choice;

    } while (choice != 'P' && choice != 'p' && choice != 'm' && choice != 'M');
         
}
// DICE ROLL
int roll(){
    return rand() % 6 + 1; 
}
// GAME LENGTH
int goal(int score)
{
    int choice;
    int newscr;

    cout << "\nCHOOSE GAME LENGTH\n";
    cout << "------------------\n";
    cout << "[1] Quick Game - 50 points\n";
    cout << "[2] Standard Game - "
         << score << " points\n";
    cout << "[3] Long Game - 150 points\n";

    do 
    {
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1:
                newscr = 50;
                break;

            case 2:
                newscr = score;
                break;
            
            case 3:
                newscr = 150;
                break;

            default:
                cout << "Invalid input! Enter 1, 2, or 3.\n";
        }
} while (choice < 1 || choice > 3);

    return newscr;
}

