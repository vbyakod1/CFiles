/*****************************************************************************/
//
//  Author:        Vineet Byakod
//
//  Description:   This file estimates the West Valley Bookstore's business
//
/*****************************************************************************/

#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>
#include <cstdlib>

using namespace std;

// Global Constants
#define PROFIT_RATE 0.20

// Function Prototypes
int calcCopiesNeeded(int enrollment, char reqSug, char newConti);
double calcProfit(double listPrice, int copiesNeeded);

void outputResult(string isbn, double listPrice, int enrollment, char reqSug, char newConti);

int main()
{
    // Input Section
    string isbn;
    double listPrice;
    int enrollment;
    char reqSug, newConti;
    
    cout << "Enter book number: ";
    getline(cin, isbn);
    
    cout << "Enter price per copy: ";
    cin >> listPrice;
    
    cout << "Enter expected class enrollment: ";
    cin >> enrollment;
    
    cout << "Enter 'R' if required or 'S' if suggested: ";
    cin >> reqSug;
    reqSug = toupper(reqSug);
    
    cout << "Enter 'N' if new or 'C' if not a new text: ";
    cin >> newConti;
    newConti = toupper(newConti);
    
    // Error Checking Section
    if (listPrice <= 0 || enrollment <= 0 || (reqSug != 'R' && reqSug != 'S') || (newConti != 'N' && newConti != 'C')) {
        cerr << "Invalid input. Please check your input and try again." << endl;
        exit(1);
    }
    
    // Calculate Section
    int copiesNeeded = calcCopiesNeeded(enrollment, reqSug, newConti);
    double profit = calcProfit(listPrice, copiesNeeded);
    
    // Output Section
    outputResult(isbn, listPrice, enrollment, reqSug, newConti);
    
    return 0;
}

// Function Definitions
int calcCopiesNeeded(int enrollment, char reqSug, char newConti)
{
    int estBookSales = 0;
    
    if (reqSug == 'R')
    {
        if (newConti == 'N')
        {
            estBookSales = round(0.9 * enrollment);
        }
        else if (newConti == 'C')
        {
            estBookSales = round(0.65 * enrollment);
        }
    }
    else if (reqSug == 'S')
    {
        if (newConti == 'N')
        {
            estBookSales = round(0.4 * enrollment);
        }
        else if (newConti == 'C')
        {
            estBookSales = round(0.2 * enrollment);
        }
    }
    
    return estBookSales;
}

double calcProfit(double listPrice, int copiesNeeded)
{
    double cost = 0.8 * listPrice;
    double revenue = listPrice * copiesNeeded;
    double profit = revenue - cost;
    return profit;
}

void outputResult(string isbn, double listPrice, int enrollment, char reqSug, char newConti)
{
    int copiesNeeded = calcCopiesNeeded(enrollment, reqSug, newConti);
    double profit = calcProfit(listPrice, copiesNeeded);

    cout << "ISBN: " << isbn << endl;
    cout << "Copies Needed: " << setw(2) << setfill(' ') << copiesNeeded << endl;
    cout << fixed << setprecision(2);
    cout << "Profit: $ " << setw(8) << setfill(' ') << profit << endl;
}

