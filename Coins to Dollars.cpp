// Name: Vineet Byakod
// Description: A program to determine the dollar amount of coins in a change purse.

#include <iostream>
using namespace std;

int main() {
    // initialize the parameters
    int quarters, dimes, nickels, pennies;
    float total;
    // First part of the output
    cout << "/*" << endl;
    cout << "Solution provided by Vineet Byakod.";
    cout << endl;
    // Prompt the user for the number of each type of coin
    cout << "Please enter the number of quarters: ";
    cin >> quarters;

    cout << "Please enter the number of dimes: ";
    cin >> dimes;

    cout << "Please enter the number of nickels: ";
    cin >> nickels;

    cout << "Please enter the number of pennies: ";
    cin >> pennies;
    // Calculate the total amount of money in dollars and cents
    total = quarters * 0.25 + dimes * 0.10 + nickels * 0.05 + pennies * 0.01;

    // Last part of the output where the the total value is calculated after user has entered values
    cout << "Thank you.\n";
    cout << endl;
    cout << "The total value of " << quarters << " quarters, " << dimes << " dimes, " << nickels << " nickles and " << pennies << " pennies is $" << total << "." << endl;
    cout << "*/";
    return 0;
    }
