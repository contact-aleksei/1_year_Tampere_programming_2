#include <iostream>
#include <string>
#include <algorithm>

using namespace std;


const int MAX_GUESSES = 10;

// Prints empty lines at the beginning of execution
void clean_screen();

// Checks if all the letters include in the list of guessed letters
bool is_word_already_guessed(string secret, string guessed, string guessed_letersright);

// Prints string using '_' in the places of letters not guessed
void print_game_status(string secret, string guessed);


int main() {
    string secret_word = "";
    cout << "Give a word to be guessed: ";
    getline(cin, secret_word);

    clean_screen();

    string guessed_letters = "";
    string guessed_letersright = "";
    int guesses_used = 0;

    while ( not is_word_already_guessed(secret_word, guessed_letters,guessed_letersright)
              and guesses_used < MAX_GUESSES ) {

        cout << endl
             << "Game status: ";
        print_game_status(secret_word, guessed_letters);

        if ( guessed_letters.size() > 0 ) {
            cout << "You have used " << guesses_used
                 << " guesses!"
                 << endl
                 << "You have guessed letters: " << guessed_letters
                 << endl;
        }

        string guess = "";
        cout << "Guess a letter: ";
        getline(cin, guess);

        if ( guess.size() != 1 ) {
            cout << "You failed: give exactly one letter!"
                 << endl;
            continue;

        } else if ( guessed_letters.find(guess) != string::npos ) {

            cout << "You failed: you had already guessed the letter " << guess << "!"
                 << endl;
            continue;
        }

        guessed_letters += guess;

        if ( secret_word.find(guess) == string::npos ) {
            cout << "Guessed letter does not include the word!" << endl;
        }
        else if ( secret_word.find(guess) != string::npos ) {
            guessed_letersright +=guess;

        }






        ++guesses_used;
    }

    if ( not is_word_already_guessed(secret_word, guessed_letters, guessed_letersright) ) {
        cout << endl
             << "Guesses expired!"
             << endl;

    } else {

        cout << endl
             << "Right guess. You used " << guesses_used
             << " guesses!"
             << endl;
    }
return EXIT_SUCCESS;
}

void clean_screen() {
    // Cleaning screen by printing 100 empty lines.
    for ( int i = 0; i < 100; ++i ) {
        cout << endl;
    }
}


bool is_word_already_guessed(string secret_word, string guessed_letters,string guessed_letersright) {
    // Going through all the characters in secret string.

    for (string::size_type index =0; index <= secret_word.size()+1; ++index ) {
           //

        // If such a character in secret string is met that is not in
        // guessed letters, it can be immediately concluded that
        // the whole secret word has not yet guessed.

        sort(secret_word.begin(),secret_word.end());
        sort(guessed_letersright.begin(),guessed_letersright.end());

        secret_word.erase(unique(secret_word.begin(), secret_word.end()), secret_word.end());
       // guessed_letters.erase(unique(guessed_letters.begin(), guessed_letters.end()), guessed_letters.end());



        if  ((secret_word) == (guessed_letersright)) {
            return true;}

       else if ( guessed_letters.find(secret_word.at(index)) == string::npos) {
            //                                  0..5
            return false;}
      //  else if (guessed_letters.find(secret_word.at(index)) == string::npos ) {
                //                                  0..5


              //  return true;

        //}

    }

    // When all the secret string has been gone through, and each character
    // was found from guessed string, it must hold that the whole
    // secret word has been guessed.


    return true;
}


void print_game_status(string secret, string guessed) {
    // The characters of a string can be gone through also with such a for loop
    // that looks like "for x in y" structure in Python.
    // This is an alternative for the for loop with index variable
    // used in previous function.
    for ( char secret_char: secret ) {
        if ( guessed.find(secret_char) == string::npos ) {
            cout << "_";
        } else {
            cout << secret_char;
        }
    }

    cout << endl;
}
