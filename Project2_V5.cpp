#include <iostream>
#include <iomanip>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;


// VARIABLES ************************************
void title(); // display title
char rules(); // display rules

char menu(); // display main menu

void getNam(string &name); // get input from user for name
void showDie(int die);
void scores(string name, int pTOtal, int cTotal);

int roll(); // roll dice
int sumDie(int die1, int die2);

bool play(); // play game
bool pTurn(int &pTotal, int &pRound, int cTotal, string name); // player turn
bool cTurn(int &cTotal, int &cRound); // computer turn

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
    cout << "=========================================\n\n\n";
    cout << "         GAME OF PIG\n\n\n\n";
    cout << "=========================================\n\n";
}
// MENU
char menu()
{
    title();
    char choice;
    cout << "[P] Play\t";
    cout << "[R] Rules\t";
    cout << "[Q] Quit\n\n";
    cin >> choice;

    return choice;
}
// RULES 
char rules()
{
    char choice;

    do
    {
        cout << "\nRULES OF PIG\n";
        cout << "-----------\n";
        cout << "You and the computer take turns rolling two dice.\n";
        cout << "Rolling 2 through 6 adds points to your round score.\n";
        cout << "Choose R to roll again or H to hold your points.\n";
        cout << "Holding adds your round points to your total score.\n";
        cout << "If either die is a 1, your turn ends.\n";
        cout << "The first player to reach 100 points wins!\n\n";

        cout << "[M] Main Menu"
         << "\t[P] Play\n\n";

         cin >> choice;
        
         if(choice == 'P' || choice == 'p')
            play();

    } while (choice != 'm' && choice != 'M');

    return choice;
}

// GET PLAYER NAME 
void getNam(string &name)
{
    cout <<"What is your name?\n\n";
    cin >> name;
}


// DICE ROLL
int roll(){
    return rand() % 6 + 1; 
}

// PLAY GAME FUNCTION
bool play()
{
    string name;
    int win = 100; // Winning score
    int die1; // first dice
    int die2; // second dice
    int pTotal = 0; // players total score
    int cTotal = 0; // computer total score
    int pRound = 0; // points earned during current turn
    int cRound = 0; // points earned during computer turn

    getNam(name); // calls name function for user input and displays name 
    cout << "\nWelcome, " << name << "!\n";
    // Count down before beginning the game.
    cout << "\nGame starting in...\n";
    for (int cnt = 3; cnt >= 1; cnt--){
        cout << cnt << "...\n";
    }
    // Run game loop for as long as nobody has won
    while (pTotal < win && cTotal < win){

    

        if (!pTurn(pTotal, pRound, cTotal, name))
        {
            return false;
        }
    }

    if (pTotal >= win){
    cout << "\nCongratulations, " << name << "! You win!\n";
    }
    else{
    cout << "\nThe computer wins!\n";
    }


    return true;
}

void showDie(int die){
                    switch (die)
                    {
                        // Display the matching die face for the generated value.
                        case 1:
                            cout << "+-------+\n";
                            cout << "|       |\n";
                            cout << "|   *   |  You rolled a one!\n";
                            cout << "|       |\n";
                            cout << "+-------+\n";
                            break;

                        case 2:
                            cout << "+-------+\n";
                            cout << "| *     |\n";
                            cout << "|       |  You rolled a two!\n";
                            cout << "|     * |\n";
                            cout << "+-------+\n";
                            break;

                        case 3:
                            cout << "+-------+\n";
                            cout << "| *     |\n";
                            cout << "|   *   |  You rolled a three!\n";
                            cout << "|     * |\n";
                            cout << "+-------+\n";
                            break;

                        case 4:
                            cout << "+-------+\n";
                            cout << "| *   * |\n";
                            cout << "|       |  You rolled a four!\n";
                            cout << "| *   * |\n";
                            cout << "+-------+\n";
                            break;

                        case 5:
                            cout << "+-------+\n";
                            cout << "| *   * |\n";
                            cout << "|   *   |  You rolled a five!\n";
                            cout << "| *   * |\n";
                            cout << "+-------+\n";
                            break;

                        case 6:
                            cout << "+-------+\n";
                            cout << "| *   * |\n";
                            cout << "| *   * |  You rolled a six!\n";
                            cout << "| *   * |\n";
                            cout << "+-------+\n";
                            break;
                    }

}
bool pTurn(int &pTotal, int &pRound, int cTotal, string name)
{
    char choice;
    int die1;
    int die2;
    bool turn = true;

    if (turn)
    {
        scores(name, pTotal, cTotal);
    }

    while (turn)
    {
        cout << "\n[R] Roll\n";
        cout << "[H] Hold and bank " << pRound << " points\n";
        cout << "[Q] Quit\n";

        cin >> choice;
        while (choice != 'R' && choice != 'r' && choice != 'H' && choice != 'h' &&
            choice != 'Q' && choice != 'q')
        {
        cout << "\nInvalid input! Enter R, H, or Q.\n";
        cin >> choice;
        }

        // Quit game
        if (choice == 'Q' || choice == 'q')
        {
            cout << "\nYou quit the game.\n";
            return false;
        }

        // Hold points
        else if (choice == 'H' || choice == 'h')
        {
            pTotal += pRound;
            pRound = 0;
            turn = false;
        }

        // Roll both dice
        else if (choice == 'R' || choice == 'r')
        {
            die1 = roll();
            die2 = roll();

            cout << "\nDie 1\n";
            showDie(die1);

            cout << "\nDie 2\n";
            showDie(die2);

            // Rolling a 1 on either die ends the turn
            if (die1 == 1 || die2 == 1)
            {
                cout << "\nYou rolled a 1 and pigged out!\n";

                pRound = 0;
                turn = false;
            }
            else
            {
                pRound += sumDie(die1, die2);

                cout << "\nRound score: "
                     << pRound << endl;
            }
        }

        // Invalid input
        else
        {
            cout << "\nInvalid input! Please enter R, H, or Q.\n";
        }
    }

    return true;
}
int sumDie(int die1, int die2)
{
    return die1 + die2;
}
void scores(string name, int pTotal, int cTotal)
{
    cout << "\n-------------------------\n";
    cout << name << "'s Turn!\n";
    cout << "-------------------------\n\n";

    cout << left << setw(25)
         << "Computer total:" << cTotal << endl;

    cout << left << setw(25)
         << (name + "'s total:") << pTotal << endl;

    int gap = abs(pTotal - cTotal);

    if (gap == 0)
    {
        cout << "\nThe game is tied!\n";
    }
    else
    {
        string lead = (pTotal > cTotal) ? name : "Computer";

        cout << lead
             << " leads by "
             << gap
             << " points!\n";
    }
}
bool cTurn(int &cTotal, int &cRound)
{
    cout << "\nComputer's turn...\n";
    return true;
}