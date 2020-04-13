#include <iostream>
#include <ctime>
#include <fstream>
using namespace std;

int star_exist_or_not(string str) {

    int result = 0;

    for(int i = 0; i < str.length(); i++) {
        if(str[i] == '*') {
            result = -1;
        }
    }

    if(result == 0) { // means no star exist
        return 0;
    } else {
        return -1; // star exist
    }
}

void play_game() {

    // creating wordlist length
    int wordlist_length = 45;

    // creating wordlist
    string words[wordlist_length] = {"America", "Africa", "India", "Bhutan", "China", "Afghanistan", "Albanie", "Andorre", "Belgium", "Bermuda", "Canada", "Egypt", "Estonia", "France", "Finland", "Germany", "Britain", "Greenland", "Iraq", "Ireland", "Japan", "Jordan", "Kenya", "Kuwait", "Malawi", "Malaysia", "Maldives", "Mali", "Mexico", "Monaco", "Nepal", "Niger", "Norway", "Pakistan", "Peru", "Phillipness", "Poland", "Portugal", "Romania", "Spain", "Sudan", "Switzerland", "Ukraine", "Zimbabwe", "Sahara"};


    // getting a random number 0 - 45
    int random = rand() % wordlist_length;

    //getting a random word for game
    string word = words[random];


    // creating number of guesses
    int no_of_guesses = 5;

    
    // greeting user
    string name;
    cout << endl << "In order to continue, please enter your name : ";
    getline(cin, name);
    
    cout << endl << "==================== Hello " << name << ", type in 'hint' to use hints ====================" << endl;


    //generating word in * format
    string star_format(word.length(), '*');
    

    // creating variable to store user input
    // in case if user enters more numbers then u_r will save us
    string user_response;


    // code for hint
    int hint_count = 2;

    // creating a game loop
    while(no_of_guesses != 0) {
        cout << endl << endl << "Word : " << star_format << ", first letter : " << word[0] << endl;
        cout << "Remaining guesses : " << no_of_guesses << endl;
        cout << "Hints left : " << hint_count << endl;;
        cout << "Enter your guess : ";
        cin >> user_response;


        string new_user_response = "";

        // converting hint to lowercase
        for(int i = 0; i < user_response.length(); i++) {
            if(isupper(user_response[i])) {
                new_user_response += tolower(user_response[i]);
            }
        }


        // checking if response is hint
        if(user_response == "hint") {
            if(hint_count > 0) {
                while(true) {
                    int random_for_hint = rand() % word.length();
                    if(star_format[random_for_hint] == '*') {
                        star_format[random_for_hint] = word[random_for_hint];
                        --hint_count;
                        break;
                    }
                }
            } else {
                cout << endl << "You have already used your hint." << endl;
            }
        } else {

            // for checking if a number was added or not
            int added = 0;

            // checking for existance
            for(int i = 0; i < word.length(); i++) {
                if(word[i] == user_response[0]) {
                    if(star_format[i] != user_response[0]) {
                        star_format[i] = user_response[0];
                        added = 1;
                    } else {
                        cout << endl << "Already guessed, please guess another character" << endl;
                        added = 1;
                    }
                }
            }
            if(added == 0) {
                --no_of_guesses;
                added = 0;
            }

        }


        string response_for_play_again;


        // checking if no of guesses are 0 or not
        if(no_of_guesses == 0) {
            cout << endl << "You ran out of lives, Better luck next time!" << endl << endl;
            cout << "Word was : " << word << endl << endl;
            break;

        } else if(star_exist_or_not(star_format) == 0) {
            cout << endl << "Congrats! You have guessed the word right." << endl;
            cout << endl << "Word was : " << word << endl;
            break;
        }


    }
}


int main() {

    //providing a seed for random number
    srand(time(NULL));

    
    
    
    play_game();


    return 0;
}