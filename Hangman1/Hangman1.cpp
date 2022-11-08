
#include "pch.h"
#include <iostream>

using namespace std;
const string word[] = { "c","of","hay","dorm","frame","hearts","pizzazz","accuracy","strengths","bookkeeper" };

int main() {
    //Variables
    int stop = 0;
    int selectWord = 0;
    int counter = 0;
    int proceed = 1;
    int numberOfGuesses = 0;
    char userGuess = 1;
    string userName = "Player";
    string challengeWord = "";
    string incorrectGuesses = "";
    string progressWord = "";
    string progressWordCheck = "";
    string wordGuessed = "";

    //Welcomes user and gets name
    cout << "Hello Player! Welcome to Hangman.\nPlease enter your name: ";
    cin >> userName;
    cout << "Welcome " << userName << ", let's get started!" << endl;

    while (proceed == 1) {
       
        //Resets variables
        counter = 0;
        stop = 0;
        incorrectGuesses = "";
        progressWord = "";
        numberOfGuesses = 0;

        //Randomly selects word
        selectWord = rand() % 10;
        challengeWord = word[selectWord];

        //Creates blank word, shows number of character
        while (counter <= selectWord) {
            progressWord = progressWord + '_';
            ++counter;
        }
        progressWordCheck = progressWord;

        //Gets user guesses
        cout << "Here is your word: " << progressWord << endl;
        cout << "It has " << selectWord + 1 << " letters." << endl;
        cout << "Ok, what is your guess? ";
        cin >> userGuess;
        ++numberOfGuesses;
        cout << endl;

        while (stop == 0) {

            //Checks challengeWord for guessed letter. If correct replaces underline with character.
            counter = 0;
            while (counter <= selectWord) {
                if (userGuess == challengeWord.at(counter)) {
                    progressWord.at(counter) = challengeWord.at(counter);
                }
                ++counter;
            }

            //If userGuess is incorrect, inputs into incorrectGuesses
            //Else sets progressWordCheck equal to progressWord
            //In both cases outputs progressWord
            if (progressWordCheck == progressWord) {
                incorrectGuesses = incorrectGuesses + " " + userGuess + " ";
                cout << "Oops! That was incorrect. Try again!" << endl << endl;
            }
            else {
                progressWordCheck = progressWord;
                cout << progressWord << endl;
                cout << "Wow, good job! Keep it up!" << endl << endl;
            }

            //Checks if word has been fully guessed and stops loop accordingly
            if (progressWord == challengeWord) {
                stop = 1;
            }
            else {
                //Continues asking player input
                cout << "Here is what you've got so far: " << progressWord << endl;
                cout << "And here is what you've got wrong: " << incorrectGuesses << endl;
                cout << "That was guess number " << numberOfGuesses << endl << endl;
                cout << "Next guess? ";
                cin >> userGuess;
                ++numberOfGuesses;
            }
        }

        cout << "Great job! You got the word in " << numberOfGuesses << " guesses!" << endl;

        cout << "Would you like to proceed?\nEnter 1 to continue, 0 to stop: ";
        cin >> proceed;
    }

    cout << "Wow thanks for playing! That was awesome, " << userName << "!";

    return 0;
}
