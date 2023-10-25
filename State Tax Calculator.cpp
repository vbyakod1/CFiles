#include <iostream>
#include <iomanip>

#define STATE_TAX_RATE 0.053   // The State sales tax rate
const double COUNTY_TAX_RATE = 0.031;  // The County sales tax rate

int main() {
    // Declare the variables
    int month, year;
    double total_collected, product_sales, county_sales_tax, state_sales_tax, total_sales_tax;

    // Get input from the user
    std::cout << "Please enter month: ";
    std::cin >> month >> year;
    std::cout << "How much money was collected in " << month << "?: $";
    std::cin >> total_collected;

    // Calculate the product sales, county sales tax, state sales tax, and total sales tax
    product_sales = total_collected / (1 + STATE_TAX_RATE + COUNTY_TAX_RATE);
    county_sales_tax = product_sales * COUNTY_TAX_RATE;
    state_sales_tax = product_sales * STATE_TAX_RATE;
    total_sales_tax = county_sales_tax + state_sales_tax;
    
    // Output the results after user input
    std::cout << std::fixed << std::setprecision(2);
    std::cout << std::endl;
    std::cout << "Month: " << month << ", " << year << std::endl;
    std::cout << std::setw(21) << std::setfill('-') << "" << std::setfill(' ') << std::endl;
    std::cout << std::setw(21) << std::left << "Total collected: " << "$ " << std::setw(10) << std::right << std::fixed << std::setprecision(2) << total_collected << std::endl;
    std::cout << std::setw(21) << std::left << "Total Sales: " << "$ " << std::setw(10) << std::right << std::fixed << std::setprecision(2) << product_sales << std::endl;
    std::cout << std::setw(21) << std::left << "County Sales Tax: " << "$ " << std::setw(10) << std::right << std::fixed << std::setprecision(2) << county_sales_tax << std::endl;
    std::cout << std::setw(21) << std::left << "State Sales Tax: " << "$ " << std::setw(10) << std::right << std::fixed << std::setprecision(2) << state_sales_tax << std::endl;
    std::cout << std::setw(21) << std::left << "Total Sales Tax: " << "$ " << std::setw(10) << std::right << std::fixed << std::setprecision(2) << total_sales_tax << std::endl;

    return 0;
}

