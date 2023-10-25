/*****************************************************************************/
//
//  Author:        Vineet Byakod
//
//  Description:   This file provides the customer bill/invoice for a Home Theatre company.
//
/*****************************************************************************/

#include <iostream>
#include <iomanip>

using namespace std;

#define TAX_RATE 0.0875

const double TV_PRICE = 500.00;
const double DVD_PRICE = 380.00;
const double REMOTE_PRICE = 35.20;
const double CD_PRICE = 74.50;
const double AV_PRICE = 1500.00;

int main() {
    int tv_quantity, dvd_quantity, remote_quantity, cd_quantity, av_quantity;
    double tv_total, dvd_total, remote_total, cd_total, av_total;
    double subtotal, tax, total;

    // Ask for user input for the quantity of each product
    cout << "How many TVs were sold? ";
    cin >> tv_quantity;
    cout << "How many DVD players were sold? ";
    cin >> dvd_quantity;
    cout << "How many Remote Controller units were sold? ";
    cin >> remote_quantity;
    cout << "How many CD Players were sold? ";
    cin >> cd_quantity;
    cout << "How many AV Processors were sold? ";
    cin >> av_quantity;

    // Calculate the total for each product (based on user input)
    tv_total = tv_quantity * TV_PRICE;
    dvd_total = dvd_quantity * DVD_PRICE;
    remote_total = remote_quantity * REMOTE_PRICE;
    cd_total = cd_quantity * CD_PRICE;
    av_total = av_quantity * AV_PRICE;

    // Calculate the subtotal, tax, and total
    subtotal = tv_total + dvd_total + remote_total + cd_total + av_total;
    tax = subtotal * TAX_RATE;
    total = subtotal + tax;

    // Outputs the header for the invoice/bill
    cout << endl;
    cout << setw(4) << "QTY" << setw(20) << "Description" << setw(12) << "Unit Price" << setw(12) << "Total Price" << endl;

    // Outputs the TV sales data if any were sold (greater than zero)
    if (tv_quantity > 0) {
        cout << setw(4) << tv_quantity << setw(20) << "TV" << setw(12) << setprecision(2) << fixed << TV_PRICE << setw(12) << setprecision(2) << fixed << tv_total << endl;
    }

    // Outputs the DVD sales data if any were sold (greater than zero)
    if (dvd_quantity > 0) {
        cout << setw(4) << dvd_quantity << setw(20) << "DVD" << setw(12) << setprecision(2) << fixed << DVD_PRICE << setw(12) << setprecision(2) << fixed << dvd_total << endl;
    }

    // Outputs the remote controller sales data if any were sold (greater than zero)
    if (remote_quantity > 0) {
        cout << setw(4) << remote_quantity << setw(20) << "Remote Controller" << setw(12) << setprecision(2) << fixed << REMOTE_PRICE << setw(12) << setprecision(2) << fixed << remote_total << endl;
    }   
    // Outputs the CD player sales data if any were sold (greater than zero)
    if (cd_quantity > 0) {
    cout << setw(4) << cd_quantity << setw(20) << "CD Player" << setw(12) << setprecision(2) << fixed << CD_PRICE << setw(12) << setprecision(2) << fixed << cd_total << endl;
    }
    // Outputs the AV processor sales data if any were sold (greater than zero)
    if (av_quantity > 0) {
    cout << setw(4) << av_quantity << setw(20) << "AV Processor" << setw(12) << setprecision(2) << fixed << AV_PRICE << setw(12) << setprecision(2) << fixed << av_total << endl;
    }
    // Outputs the subtotal, tax, and total
    cout << setw(36) << "SUBTOTAL" << setw(12) << setprecision(2) << fixed << subtotal << endl;
    cout << setw(36) << "TAX" << setw(12) << setprecision(2) << fixed << tax << endl;
    cout << setw(36) << "TOTAL" << setw(12) << setprecision(2) << fixed << total << endl;

    return 0;
    }


