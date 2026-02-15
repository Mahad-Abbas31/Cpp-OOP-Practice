#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

// ___ Class
class Die {
private:
    int value;

public:
    Die() {
        value = 1;
    }

    // ___ RollMethod/Function
    void roll() {
        value = (rand() % 6) + 1;
    }

    int getValue() {
        return value;
    }
};

// ___ Main
int main() {
    srand(time(0));

    Die dice;
    char choice;
    int totalPoints = 0;

    cout << "-> Welcome to the Fishing Game!\n";

    // ___ GameLoop
    do {
        cout << "\nDo you want to fish? (y/n): ";
        cin >> choice;

        if (choice == 'y' || choice == 'Y') {
            dice.roll();
            int roll = dice.getValue();

            cout << "You rolled: " << roll << endl;

            // ___ SwitchOptions
            switch (roll) {
                case 1:
                    cout << "You caught a Huge Fish! (+10 points)\n";
                    totalPoints += 10;
                    break;
                case 2:
                    cout << "You caught an Old Shoe! (+2 points)\n";
                    totalPoints += 2;
                    break;
                case 3:
                    cout << "You caught a Little Fish! (+5 points)\n";
                    totalPoints += 5;
                    break;
                case 4:
                    cout << "You caught a Crab! (+7 points)\n";
                    totalPoints += 7;
                    break;
                case 5:
                    cout << "You caught Seaweed! (+3 points)\n";
                    totalPoints += 3;
                    break;
                case 6:
                    cout << "You caught a Golden Fish! (+15 points)\n";
                    totalPoints += 15;
                    break;
            }
        }

    } while (choice == 'y' || choice == 'Y');

    // ___ FinalResult
    cout << "\nFishing session ended!";
    cout << "\nTotal Fishing Points: " << totalPoints << endl;

    if (totalPoints >= 40)
        cout << "Outstanding Fisherman!\n";
    else if (totalPoints >= 20)
        cout << "Good Job!\n";
    else
        cout << "Better luck next time!\n";

    return 0;
}