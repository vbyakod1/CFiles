/*****************************************************************************/
//
//  Author:        Vineet Byakod
//
//  Description:   This file provides the monthly cost of a house given the selling price, annual rate of interest, and number of years for the loan. 
//
/*****************************************************************************/

#include <iostream>
#include <cmath>
#include <iomanip>
#include <fstream>

#define TAX_RATE 0.0125
#define UTILITIES_COST 300.00
#define INSURANCE_COST 550.00

void get_mortgage_input_data(double& selling_price, double& interest_rate, int& payoff_years);
void calc_monthly_costs(double selling_price, double interest_rate, int payoff_years, double& down_paymt, double& loan_amount, double& monthly_mortgage, double& tax_amount, double& total_monthly_cost);
void file_output_data(double selling_price, double down_paymt, double loan_amount, double interest_rate, int payoff_years, double monthly_mortgage, double total_monthly_cost);
/*****************************************************************************/
//                                                                     main()
/*****************************************************************************/
/*
********************
        Variables:
********************

double selling_price; House selling price
double interest_rate; Annual Interest rate on the loan
double down_paymt; Amount of down payment
double loan_amount; Loan to be borrowed from the bank
double monthly_mortgage; Monthly mortgage payment calculated from
                         the compound interest formula
double tax_amount; Monthly property tax payment
double total_monthly_cost; Total monthly cost, sum of mortgage, utilities,
                           property tax and insurance

int payoff_years; No. of years to be taken to pay off the loan,
                 to be converted to monthly periods to be used
                 in the compound interest formula

*************************
   Invoked Functions:
*************************

1. "input_data" inputs mortgage data from the user
    a) house selling price
    b) loan interest rate charged by the bank
    c) number of years the user wants to take to pay off the loan

2. "calc_monthly_costs" calculates the Monthly House Cost and gives:
    a) down payment
    b) loan amount
    c) monthly mortgage payment
    d) monthly property tax payment
    e) monthly insurance premium payment
    f) total monthly cost - sum of mortgage, utilities, tax and insurance

3. "output_data_to_file" writes output data to a text file

/*****************************************************************************/

int main() {
    double selling_price, interest_rate, down_paymt, loan_amount, monthly_mortgage, tax_amount, total_monthly_cost;
    int payoff_years;

    get_mortgage_input_data(selling_price, interest_rate, payoff_years);
    calc_monthly_costs(selling_price, interest_rate, payoff_years, down_paymt, loan_amount, monthly_mortgage, tax_amount, total_monthly_cost);
    file_output_data(selling_price, down_paymt, loan_amount, interest_rate, payoff_years, monthly_mortgage, total_monthly_cost);

    return 0;
}
/*****************************************************************************/

// Function: get_mortgage_input_data
// Description: This function gets the mortgage input data from the user.
// Inputs: N/A
// Outputs: selling_price - The selling price of the house
//          interest_rate - The annual interest rate on the loan
//          payoff_years - The number of years for the loan
void get_mortgage_input_data(double& selling_price, double& interest_rate, int& payoff_years) {
    std::cout << "Enter the selling price: ";
    std::cin >> selling_price;
    std::cout << "Enter the interest rate (in percentage): ";
    std::cin >> interest_rate;
    std::cout << "Enter the number of years for the loan: ";
    std::cin >> payoff_years;
}
/*****************************************************************************/

// Function: calc_monthly_costs
// Description: This function calculates the monthly costs of the mortgage.
// Inputs: selling_price - The selling price of the house
//         interest_rate - The annual interest rate on the loan
//         payoff_years - The number of years for the loan
// Outputs: down_paymt - The down payment amount
//          loan_amount - The loan amount to be borrowed from the bank
//          monthly_mortgage - The monthly mortgage payment
//          tax_amount - The monthly property tax payment
//          total_monthly_cost - The total monthly cost, sum of mortgage,
//                               utilities, property tax, and insurance
void calc_monthly_costs(double selling_price, double interest_rate, int payoff_years, double& down_paymt, double& loan_amount, double& monthly_mortgage, double& tax_amount, double& total_monthly_cost) {
    const double DOWN_PAYMENT_PERCENT = 0.20;

    down_paymt = selling_price * DOWN_PAYMENT_PERCENT;
    loan_amount = selling_price - down_paymt;

    double i = interest_rate / 1200;
    int n = payoff_years * 12;

    monthly_mortgage = (loan_amount * i * pow(1 + i, n)) / (pow(1 + i, n) - 1);
    tax_amount = selling_price * TAX_RATE / 12;

    double monthly_insurance = INSURANCE_COST / 12;
    total_monthly_cost = monthly_mortgage + UTILITIES_COST + tax_amount + monthly_insurance;
}
/*****************************************************************************/

// Function: file_output_data
// Description: This function writes the calculated mortgage data to a text file.
// Inputs: selling_price - The selling price of the house
//         down_paymt - The down payment amount
//         loan_amount - The loan amount to be borrowed from the bank
//         interest_rate - The annual interest rate on the loan
//         payoff_years - The number of years for the loan
//         monthly_mortgage - The monthly mortgage payment
//         total_monthly_cost - The total monthly cost, sum of mortgage,
//                              utilities, property tax, and insurance
// Outputs: N/A
void file_output_data(double selling_price, double down_paymt, double loan_amount, double interest_rate, int payoff_years, double monthly_mortgage, double total_monthly_cost) {
    std::ofstream outputFile("monthly_cost_of_house.txt");

    outputFile << std::fixed << std::setprecision(2);
    outputFile << "********************************************************************\n";
    outputFile << "                        MONTHLY COST OF HOUSE\n";
    outputFile << "********************************************************************\n\n";
    outputFile << "SELLING PRICE\t\t\t$ " << selling_price << "\n";
    outputFile << "DOWN PAYMENT\t\t\t$ " << down_paymt << "\n";
    outputFile << "AMOUNT OF LOAN\t\t\t$ " << loan_amount << "\n";
    outputFile << "INTEREST RATE\t" << interest_rate << "%\n";
    outputFile << "TAX RATE\t" << TAX_RATE * 100 << "%\n";
    outputFile << "DURATION OF LOAN (YEARS)\t" << payoff_years << " yrs\n\n";
    outputFile << "**************************\n";
    outputFile << "MONTHLY PAYMENT\n";
    outputFile << "**************************\n";
    outputFile << "MORTGAGE PAYMENT\t\t$ " << monthly_mortgage << "\n";
    outputFile << "UTILITIES\t\t\t$ " << UTILITIES_COST << "\n";
    outputFile << "PROPERTY TAXES\t\t$ " << (selling_price * TAX_RATE) / 12 << "\n";
    outputFile << "INSURANCE\t\t\t$ " << INSURANCE_COST / 12 << "\n";
    outputFile << "----------------\n";
    outputFile << "$ " << total_monthly_cost << "\n";

    outputFile.close();
}









