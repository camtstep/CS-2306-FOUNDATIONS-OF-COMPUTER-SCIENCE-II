// File Name: program1_cts96.cpp
//
// Author: Cameron Stepanski
// Date: 6/6/2020
// Assignment Number: 1
// CS 2308.501 Summer 2020
// Instructor: Dr. J. Marcos Palacios
//
// This program displays a menu for high-end products available to Virgin
// Atlantic passengers during in-flight service. It allows users to pick
// multiple items to buy and displays the total plus tax. It gives an end-of-day
// total and displays the most bought item when the user is done shopping.

#include <iostream>
#include <iomanip>

using namespace std;

struct MenuItem
{
    string description; // description of menu item
    double price; // price of menu item
    int counter; // count of the number of times the item has been ordered
};

//***********************************************************
// displayMenu: displays the menu of high-end products
// menuItem array of product information
// size the number of products in the array
//***********************************************************

void displayMenu (MenuItem menuItem[], int size)
{
    for(int i=0; i<size; i++)
    {
        cout << "[" << i + 1 << "] ";
        cout << setw(19) << left << menuItem[i].description;
        cout << "$" << fixed << setprecision(2) << menuItem[i].price;
        cout << endl;

    }
}

//***********************************************************
// takeOrder: takes the user's order of products to purchase
// menuItem array of product information
// size the number of products in the array
// returns the total of the order pre-tax
//***********************************************************

double takeOrder(MenuItem menuItem[], int size)
{
    int selection; // user's selection of item to purchase
    double total = 0; // total of current order

    cout << "Input the item numbers for the order, 0 to quit" << endl;

    cin >> selection;

    while(selection != 0)
    {
       // Validate user input
       if(selection < 1 || selection > size)
        {
            cout << "*Error: There is no item " << selection << "." << endl;
            cout << "Processing other items..." << endl;
        }
       else
        {
            total += menuItem[selection-1].price;
            menuItem[selection-1].counter++;
        }

       cin >> selection;
    }

 return total;
}

//***********************************************************
// highestCount: determines which product was purchased most often
// menuItem array of product information
// size the number of products in the array
// returns the array index of the product ordered most often
//***********************************************************

int highestCount(MenuItem menuItem[],int size)
{
    int highest = 0; // index of product purchased most often

    for(int j=0; j<size; j++)
    {
        if(menuItem[j].counter > menuItem[highest].counter)
            highest = j;
    }

    return highest;
}

int main()
{
    const int SIZE = 6; // size of menuItem array
    const double TAX_RATE = .0825; // 8.25% tax rate
    double subtotal; // subtotal of a single order
    double endOfDayTotal = 0; // total for all orders at the end of the day
    char newOrder; // user input for new order or to exit
    int mostOrdered; // index of product ordered most often

    // Initialize MenuItem array
    MenuItem menuItem[SIZE] = {{"Rolex Watch", 1099.00, 0},
                               {"MacBook Pro", 1299.00, 0},
                               {"Men's Cufflinks", 499.00, 0},
                               {"iPad Pro 11-in", 799.00, 0},
                               {"Ladies Ring", 999.00, 0},
                               {"Watch S4", 399.00, 0}};

    // Take order(s)
    do
    {
        displayMenu(menuItem,SIZE);

        subtotal = takeOrder(menuItem,SIZE);
        endOfDayTotal += subtotal;

        cout << "Subtotal...$ " << subtotal << endl;
        cout << "Tax........$ " << subtotal * TAX_RATE << endl;
        cout << "Total......$ " << subtotal + (subtotal * TAX_RATE) << endl
             << endl;

        cout << "Please enter 'N' to take a new order and 'E' to exit: ";
        cin >> newOrder;
     } while(newOrder == 'N');

    // Determine and display end of day total with tax
    cout << "*** End of Day: " << endl;
    cout << "Total sales: $" << endOfDayTotal + (endOfDayTotal * TAX_RATE)
         << endl;

    // Determine and display most ordered item
    mostOrdered = highestCount(menuItem,SIZE);

    cout << "Item ordered most often: " << menuItem[mostOrdered].description
         << " was purchased " << menuItem[mostOrdered].counter << " times.";

    return 0;
}
