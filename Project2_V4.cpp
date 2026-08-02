#include <iostream>
#include <iomanip>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;


// VARIABLES ************************************
void title();
char rules();

char menu();

void getNam(string &name);

int die1;
int die2;
int roll();

bool play();

// MAIN *****************************************

int main(){
    srand(static_cast<unsigned int>(time(0)));
    char choice;

    do
    {
        choice = menu(); // Display main menu

        switch(choice)
        {
            case 'P':
            case 'p':
            // play the game
            play();
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
char rules()
{
    char choice;

    do
    {
        cout << "\nHOW TO PLAY\n";
        cout << "-----------\n";
        cout << "You and the computer take turns rolling two dice.\n";
        cout << "Rolling 2 through 6 adds points to your round score.\n";
        cout << "Choose R to roll again or H to hold your points.\n";
        cout << "Holding adds your round points to your total score.\n";
        cout << "If either die is a 1, your turn ends.\n";
        cout << "The first player to reach 100 points wins!\n\n";

        cout << "[M] Main Menu"
         << "\t[P] Play\n";

         cin >> choice;
        
         if(choice == 'P' || choice == 'p')
            play();

    } while (choice != 'm' && choice != 'M');

    return choice;
}
// DICE ROLL
int roll(){
    return rand() % 6 + 1; 
}

// PLAY GAME FUNCTION
bool play()
{
    string name;
    int winscr = 100;
    getNam(name);
    cout << "\nWelcome, " << name << "!\n";
    return true;
}

void getNam(string &name)
{
    cout <<"What is your name?\n";
    cin >> name;
}

