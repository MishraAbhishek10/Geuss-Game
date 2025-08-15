#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

class GuessGame {
private:
    int computerChoice;

public:
    GuessGame() {
        srand(time(0));
        computerChoice = rand() % 100;  // Generate a random number between 0 and 99
    }

    bool isNumberCorrect(int userGuess) {
        return userGuess == computerChoice;
    }

    int getComputerChoice() {
        return computerChoice;
    }

    void setComputerChoice(int choice) {
        computerChoice = choice;
    }
};

int main() {
    int userGuess;
    int attempt = 0;

    GuessGame obj;

    // Game loop
    do {
        cout << "Enter your guess: ";
        cin >> userGuess;
        attempt++;


        if (userGuess > obj.getComputerChoice()) {
            cout << "Hint: Your choice is greater than the computer's choice." << endl;
        } else if (userGuess < obj.getComputerChoice()) {
            cout << "Hint: Your choice is lesser than the computer's choice." << endl;
        }

    } while (!obj.isNumberCorrect(userGuess));

    cout << "Your attempts: " << attempt << endl;

    return 0;
}

