/*****************************************************************************/
//
//  Author:        Vineet Byakod
//
//  Description:   This program calculates and outputs the monthly payment
//                 schedule for a credit card debt, considering that no
//                 additional charges are made to the account and only the
//                 minimum payment is paid each month. The output stops when
//                 the balance is fully paid, and the remaining balance is 0.
//
/*****************************************************************************/


#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

void read_input_data(double &balance, double &interest_rate, double &min_payment_percent);
void output_table_heading(double balance, double interest_rate, double min_payment_percent, ofstream &output_file);
void output_monthly_data(int month, double balance, double interest_paid, double min_payment, double sum_interest_paid, ofstream &output_file);
/*****************************************************************************/
//                                                                     main()
/*****************************************************************************/
/*
********************
        Variables:
********************
double balance; Initial credit card balance
double interest_rate; Annual interest rate on the credit card
double min_payment_percent; Minimum payment percentage required
int month; Number of months elapsed
double sum_interest_paid; Sum of interest paid over the months

*************************
   Invoked Functions:
*************************

1."read_input_data" reads input data from a file:
    a) credit card balance
    b) annual interest rate
    c) minimum payment percentage

2. "output_table_heading" writes the table heading in the output file:
    a) initial balance
    b) annual interest rate
    c) minimum payment percentage

3. "output_monthly_data" writes the monthly data in the output file for each month:
    a) month number
    b) remaining balance
    c) interest paid that month
    d) minimum payment for that month
    e) sum of interest paid so far

*****************************************************************************/

int main() {
    double balance, interest_rate, min_payment_percent;
    read_input_data(balance, interest_rate, min_payment_percent);

    ofstream output_file("output.txt");
    if (!output_file) {
        cerr << "Error: Unable to open output file." << endl;
        return 1;
    }

    output_table_heading(balance, interest_rate, min_payment_percent, output_file);

    int month = 0;
    double sum_interest_paid = 0.0;
    while (balance > 0.0 && month < 60) {
        month++;
        // Calculate interest for the month and add it to the balance
        double interest_paid = balance * (interest_rate / 100.0) / 12.0;
        balance += interest_paid;
        // Calculate the minimum payment due for the month
        double min_payment = balance * (min_payment_percent / 100.0);
        // Apply the $15.00 threshold for the minimum payment
        if (min_payment < 15.0) {
            min_payment = 15.0;
        }
        // If the remaining balance is less than the minimum payment, set the minimum payment to the remaining balance
        if (balance - min_payment < 0) {
        min_payment = balance;
        }
        // Update the balance after applying the minimum payment
        balance -= min_payment;
        // Update the total of interest paid up to date
        sum_interest_paid += interest_paid;


        output_monthly_data(month, balance, interest_paid, min_payment, sum_interest_paid, output_file);
    }

    output_file.close();
    return 0;
}

// Function: read_input_data
// Reads input data from a file and assigns the values to the variables.
// Parameters:
//   - double &balance: reference to the initial credit card balance
//   - double &interest_rate: reference to the annual interest rate
//   - double &min_payment_percent: reference to the minimum payment percentage

void read_input_data(double &balance, double &interest_rate, double &min_payment_percent) {
    ifstream input_file("lab6.txt");
    if (!input_file) {
        cerr << "Error: Unable to open input file." << endl;
        exit(1);
    }

    input_file >> balance >> interest_rate >> min_payment_percent;
    input_file.close();
}

// Function: output_table_heading
// Writes the table heading in the output file.
// Parameters:
//   - double balance: initial credit card balance
//   - double interest_rate: annual interest rate
//   - double min_payment_percent: minimum payment percentage
//   - ofstream &output_file: reference to the output file stream

void output_table_heading(double balance, double interest_rate, double min_payment_percent, ofstream &output_file) {
    output_file << "Balance Owing: $" << fixed << setprecision(2) << balance << endl;
    output_file << "APR as % " << fixed << setprecision(2) << interest_rate << endl;
    output_file << "Percent for minimum payment as % " << fixed << setprecision(2) << min_payment_percent << endl;
    output_file << "------------------------------------------------------" << endl;
    output_file << left << setw(7) << "Month" << setw(14) << "Balance" << setw(22) << "Interest this month" << setw(17) << "Minimum" << "Sum of interest paid" << endl;
}

// Function: output_monthly_data
// Writes the monthly data in the output file for each month.
// Parameters:
//   - int month: month number
//   - double balance: remaining balance
//   - double interest_paid: interest paid that month
//   - double min_payment: minimum payment for that month
//   - double sum_interest_paid: sum of interest paid so far
//   - ofstream &output_file: reference to the output file stream

void output_monthly_data(int month, double balance, double interest_paid, double min_payment, double sum_interest_paid, ofstream &output_file) {
    output_file << left << setw(7) << month
                << setw(14) << fixed << setprecision(2) << balance
                << setw(22) << interest_paid
                << setw(17) << min_payment
                << sum_interest_paid << endl;
}
