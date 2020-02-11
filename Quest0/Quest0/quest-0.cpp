#include <iostream>
#include <string>
#include <random>
#include <ctype.h>
#include <iomanip>

using namespace std;

void fillLetters (char, string);
int chooseRandomCountry ();
void pauseConsole ();
void printGameBoard (string);
char processUserInput ();
void clearConsole ();
bool isGameDone (string);
void printGameOver (string guess);
bool isGameSuccessful (string currentGuess);
void printNumberOfTries ();

const int numCountries = 30;
int padding = 3;

const int maxNumberGuesses = 4;
int currentGuessNumber = 0;
string currentGuessString = "";
string correctCountry = "";

string countries [] = {
    "senegal",
    "serbia",
    "seychelles",
    "singapore",
    "slovakia",
    "slovenia",
    "somalia",
    "spain",
    "sudan",
    "suriname",
    "swaziland",
    "sweden",
    "switzerland",
    "syria",
    "taiwan",
"tajikistan",
"tanzania",
"thailand",
"togo",
"tonga",
"tunisia",
"turkey",
"turkmenistan",
"tuvalu",
"uganda",
"ukraine",
"uruguay",
"uzbekistan",
"vanuatu",
"venezuela",
};

int main() {
    clearConsole();

    correctCountry = countries[chooseRandomCountry()];

    currentGuessString = std::string(correctCountry.length(), '*');
    string compareGuessString = currentGuessString;

    while (isGameDone(currentGuessString) == false) {
        printGameBoard(currentGuessString);
        printNumberOfTries();
        char userGuess = processUserInput();
        fillLetters(userGuess, correctCountry);
        if (currentGuessString != compareGuessString) {
            compareGuessString = currentGuessString;
        }
        else {
            currentGuessNumber++;
        }
        clearConsole();
    }

    printGameOver(currentGuessString);
}

bool isGameDone(string currentGuess) {
    if (currentGuessNumber > maxNumberGuesses || currentGuessString == correctCountry) {
        return true;
    }
    else {
        return false;
    }
}

bool isGameSuccessful(string currentGuess) {
    if (currentGuessNumber == 0) {
        return true;
    }
    else {
        return false;
    }
}

void printGameOver(string currentGuess) {
    if (currentGuess == correctCountry) {
        printGameBoard(currentGuess);
        cout << "CONGRATS";
    }
    else {
        printGameBoard(currentGuess);
        cout << "YOU FAILED";
    }
}

void printGameBoard(string guess) {
    cout << "+" << setfill('-') << setw(guess.length() + 5) << "+" << endl;
    cout << "|" << setfill(' ') << setw(3);
    for (int i{ 0 }; i < guess.length(); i++) {
        cout << guess[i];
    }
    cout << setfill(' ') << setw(3) << "|" << endl;
    cout << "|" << setfill(' ') << setw(3);
    for (int j{ 0 }; j < guess.length(); j++) {
        cout << "-";
    }
    cout << setfill(' ') << setw(3) << "|" << endl;
    cout << "+" << setfill('-') << setw(guess.length() + 5) << "+" << endl;
}

void printNumberOfTries() {
    cout << "NUMBER OF TRIES: " << currentGuessNumber << endl;
}

char processUserInput () {
    cout << "Enter a Guess! :";
    char userGuess;
    cin >> userGuess;
    return userGuess;
}

void fillLetters (char guessChar, string secretWord) {
    int secretWordLength = secretWord.length();
    for (int k = 0; k < secretWordLength; k++) {
        if (guessChar == secretWord[k]) {
            secretWord[k] = guessChar;
            currentGuessString[k] = secretWord[k];
        }
    }
}

void pauseConsole () {
    std::string temp;
    std::cout << "Enter to continue... ";
    std::getline(std::cin, temp);
}

void clearConsole () {
    #if defined(WIN32) || defined(_WIN32) || defined(__WIN32) && !defined(__CYGWIN__)
    	system("cls");
    #else
        system("clear");
    #endif
}

int chooseRandomCountry () {
    random_device seed;
    default_random_engine engine(seed());
    uniform_int_distribution<int> dist(0, numCountries-1);

    return dist(engine);
}