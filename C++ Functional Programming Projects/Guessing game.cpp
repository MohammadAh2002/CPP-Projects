/*

    Write a Small Guessing Game.
    
    Requirements:
    � Ask the player to pick a number in their head between 1 and 100.
    � The computer will guess the player's number in each round. The player provides feedback:
        - Enter l if the number is larger than the computer's guess.
        - Enter s if the number is smaller than the computer's guess.
        - Enter c if the computer's guess is correct.
    
    � The computer tries to guess the number within 7 attempts.
    � If the computer doesn't guess the number in 7 tries, the player wins the round.

*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>

using namespace std;

struct roundinfo {

    int min = 1, max = 100, rounds_played = 0, randompick = 0;
    char pick;
    bool answer = false;
};

int RandomNumber(int From, int To) {

    int randNum = rand() % (To - From + 1) + From;
    return randNum;

}

void print_rules() {

    cout << "choce a number is your head between 1-100\n";
    cout << "i will guss the number in less than 7 trys\n";
    cout << "if not you will win\n";
    cout << "(l)arger or (s)maller than the one shown.\n";
    cout << "Enter 'c' (for 'correct') if the number shown is yours.\n";

}

void check_guess(roundinfo& round) {

    switch (round.pick)
    {

    case 'l':
    case 'L':
        round.min = round.randompick;
        break;
    case 'S':
    case 's':
        round.max = round.randompick;
        break;
    case 'c':
    case 'C':
        round.answer = true;
        break;
    }
}

void print_result(roundinfo& round) {

    cout << "the number you picked is: " << round.randompick << endl;
    cout << "i gussed it after: " << round.rounds_played << " trys\n";

}

void play_game() {

    roundinfo round;

    print_rules();

    do {

        round.randompick = RandomNumber(round.min, round.max);

        cout << "the number you picked is: " << round.randompick;
        cout << " Right? " << endl;
        cin >> round.pick;

        check_guess(round);

        round.rounds_played++;

    } while (!round.answer);

    print_result(round);
}

int main()
{
    srand((unsigned)time(NULL));

    play_game();

    return 0;

}