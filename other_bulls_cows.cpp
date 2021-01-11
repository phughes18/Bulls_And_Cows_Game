// CS-1600 L01 Vincent Mierlak
// Peter Hughes
// 04/26/19
// Final Project (Bulls and Cows Game)

// HEADER FILES

#include <iostream>
#include <vector>
#include <ctime>
#include <random>


// FUNCTION DECLARATIONS

// Randomly fills computer's array with four numbers and prevents any duplicate numbers in the sequence.
// PARAMETERS: comp_values[] - randomized computer integer array of values
//             size - integer number of values in random computer array (four)
// POSTCONDITION: the computer array is filled with four different random values between one and nine.

void fill_array(int comp_values[], int size);


// Prompts player to enter their four number guess and creates a player array.
// PARAMETERS: player_guess[] - integer array of values entered by player guessing computer array
//             size - integer number of values in player array (four)
// POSTCONDITION: an array is created containing the player's four number guess of the computer array.

void player_values(int player_guess[], int size);


// Checks for current number of bulls in player array by comparing with computer array.
// PARAMETERS: comp_values[] - randomized computer constant integer array of values
//             player_guess[] - constant integer array of values entered by player guessing computer array
//             &bulls - integer number of matching values in the correct position of player array
//                      relative to computer array
// POSTCONDITION: the computer determines the number of matching values in the correct position (bulls)
//                between the player array and the computer array.

void check_bulls(const int comp_values[], const int player_guess[], int &bulls);


// Checks for current number of cows in player array by comparing with computer array.
// PARAMETERS: comp_values[] - randomized computer constant integer array of values
//             player_guess[] - constant integer array of values entered by player guessing computer array
//             &cows - integer number of matching values in the incorrect position of player array
//                     relative to computer array
// POSTCONDITION: the computer determines the number of matching values in the incorrect position
//                between the player array and the computer array.

void check_cows(const int comp_values[], const int player_guess[], int &cows);


// Records the best score / worst score, game number and total guesses of each session
// PARAMETERS: &game_number - integer number of games played in each session
//             &best_score - least integer number of guesses played in an individual game
//             &worst_score - most integer number of guesses played in an individual game
//             &total_guesses - total integer number of guesses in all session games combined
//             &attempt_counter - integer number of guesses in an individual game
// POSTCONDITION: the computer tracks and records the current best score, worst score, total guesses and
//                number of games that have been completed during the session.

void score_tracker(int &game_number, int &best_score, int &worst_score, int &total_guesses, int &attempt_counter);


// Displays statistics about the game session such as number of games, best score, worst score and
// the average number of guesses each game
// PARAMETERS: game_number - integer number of games played in a session
//             best_score - least integer number of guesses played in an individual game
//             worst_score - most integer number of guesses played in an individual game
//             total_guesses - total integer number of guesses in all session games combined
// POSTCONDITION: the computer displays the number of games, best score, worst score, total guesses and
//                average number of guesses per game of the entire session.

void game_stats(int game_number, int best_score, int worst_score, int total_guesses);


// Grants player the option to play again or end their session.
// PARAMETERS: input - character input option for whether to begin a new session or stop playing
// POSTCONDITION: player chooses whether to continue their current session or end playing.

bool play_option(char input);



// MAIN FUNCTION

int main()
{
    // Initializes variables for the score tracker function
 
    using namespace std;
    char input = 'y';
    int game_number = 0;
    int best_score = 0;
    int worst_score = 0;
    int total_guesses = 0;
   

    // do-while loop for either continuing the session with another game or ending the session

    do
    {
        int bulls = 0;
        int cows = 0;
        int attempt_counter = 0;

        constexpr int TOTALNUMS = 4;
        int comp_values[TOTALNUMS];
        int player_guess[TOTALNUMS];

        fill_array(comp_values, TOTALNUMS);
        
        // while loop to continue the game until the player has guessed the correct values

        while (bulls < 4)
        {
            bulls = 0;
            cows = 0;
            
            // Functions that prompt player to enter a guess and then determines the number
            // of cows and bulls in their guess

            player_values(player_guess, TOTALNUMS);
            check_bulls(comp_values, player_guess, bulls);
            check_cows(comp_values, player_guess, cows);

            cout << "Number of Bulls: " << bulls << endl;
            cout << "Number of Cows: " << cows << endl;
            
            attempt_counter += 1;
        }
        
        // Function to track game session data

        score_tracker(game_number, best_score, worst_score, total_guesses, attempt_counter);
        
     } while ( play_option(input) );
    
    // Output function for game session statistics

    game_stats(game_number, best_score, worst_score, total_guesses);

    return 0;
}


// FUNCTION DEFINITIONS


// Fills array with four random numbers and prevents repetition by comparing each number
// with the others and recreating the sequence if there are any duplicates

void fill_array(int comp_values[], int size)
{
    using namespace std;
    bool non_duplicates;

    default_random_engine randeng(time(0) * time(0));
    uniform_int_distribution<unsigned> unifdest(0, 9);
    
    // do-while loop to continue generating random numbers until the computer
    // has reached a sequence of four non-duplicate numbers. Function uses for
    // for-loop to check for duplicate numbers in the random computer array

    do
    {
        non_duplicates = false;

        for ( int i = 0; i < size; ++i )
        {  
            comp_values[i] = unifdest(randeng);
        }
        
        for ( int i = 0; i < size; ++i )
        {
            for ( int j = 0; j < size; ++j )
            {
                if ( ( comp_values[i] == comp_values[j] ) && ( i != j) )
                    non_duplicates = true;
            }
        }

    } while ( non_duplicates );

    return;
}
 


// Function that creates player array of guesses for four values and displays the entered array to the player

void player_values(int player_guess[], int size)
{
    using namespace std;

    cout << "Enter four unique values for your guess: ";

    for (int i = 0; i < size; ++i)
    {
        cin >> player_guess[i];
    }

    cout << endl;

    cout << "The values you entered are: ";
    
    for (int i = 0; i < size; ++i)
    {
        cout << player_guess[i] << " ";
    }

    return;
}



// Function that reads through the four values of both arrays and records matching values in the 
// same position of seperate arrays as "bulls"

void check_bulls(const int comp_values[], const int player_guess[], int &bulls)
{
    using namespace std;

    for (int i = 0; i < 4; ++i)
    {
        if (comp_values[i] == player_guess[i])
            bulls += 1;
    }

    cout << endl;
    return;
}



// Function that reads through the values of both arrays and records matching values in different
// positions of seperate arrays as "cows"

void check_cows(const int comp_values[], const int player_guess[], int &cows)
{
   using namespace std;

   for ( int i = 0; i < 4; ++i )
   {
       for ( int j = 0; j < 4; ++j )
       {
           if ( ( comp_values[i] == player_guess[j] ) && ( i != j ) )
               cows += 1;
       }
   }

   cout << endl;
   return;
}



// Function that updates the number of total guesses, games, best score 
// and worst score of the session

void score_tracker(int &game_number, int &best_score, int &worst_score, int &total_guesses, int &attempt_counter)
{
    using namespace std;

    total_guesses += attempt_counter;

    if (game_number == 0)
        best_score = attempt_counter;
    else if (attempt_counter < best_score)
        best_score = attempt_counter;

    if (attempt_counter > worst_score)
        worst_score = attempt_counter;

    game_number += 1;
    cout << "Total guess(es): " << attempt_counter << "." << endl;
}



// Function that displays the number of games, number of guesses per game, total guesses, best score and
// worst score of the entire session for the player

void game_stats(int game_number, int best_score, int worst_score, int total_guesses)
{
    using namespace std;

    double avg_guess;
    avg_guess = static_cast<double>(total_guesses) / game_number;

    cout << "You played " << game_number << " game(s) in this session." << endl;
    cout << "Your best score was " << best_score << " guess(es)." << endl;
    cout << "Your worst score was " << worst_score << " guess(es)." << endl;
    cout << "Your average number of guess(es) per game was " << avg_guess << "." << endl;
    cout << "Thanks for playing!" << endl;

    return;
}



// Function that gives the player the option to continue their session with another game
// or to end their session and receive game statistics

bool play_option(char input)
{
    using namespace std;

    cout << "Would you like to play again? (y/n)" << endl;
    cin >> input;

    if (input == 'y')
        return true;
    else
        return false;
}

