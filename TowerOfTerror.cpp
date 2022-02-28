// File Name: TowerOfTerror.cpp
//
// Author: Cameron Stepanski
// Date: 6/25/2020
// Assignment Number: 4
// CS 2308.501 Summer 2020
// Instructor: Dr. J. Marcos Palacios
//
// This program reads a file of reservation data for the Tower of Terror ride at
// Disney's Hollywood Studios and groups reservations in a first in, first out
// manner and so that a ride doesn't exceed it's maximum capacity and percentage
// capacity due to COVID-19.

#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include "Queue.h"

using namespace std;

const int MAX_CAPACITY = 50; // Maximum capacity for the ride is 50

// Prototypes
void readDataFile(float &, Queue &);
void groupReservations(float, Queue &);

int main()
{
    Queue towerOfTerror; // Queue class used to hold reservation data
    float percentCapacity; // Percentage capacity for the ride due to COVID-19

    // Read in data from file
    readDataFile(percentCapacity, towerOfTerror);

    // Group reservations
    groupReservations(percentCapacity, towerOfTerror);

    return 0;
}

//***********************************************************
// readDataFile: reads in data from "reservations.txt"
// percentCapacity percent of the capacity available for rides due to COVID-19
// towerOfTerror Queue class that holds reservation data
//***********************************************************
void readDataFile(float &percentCapacity, Queue &towerOfTerror)
{
    ifstream fin; // used to read in data from file
    string name; // name for a reservation
    int sizeOfRes; // size of a reservation

    // Open file
    fin.open("reservations.txt");

    // Read in and store data
    if(fin)
    {
        fin >> percentCapacity;

        while(fin >> name >> sizeOfRes)
        {
            towerOfTerror.enqueue(sizeOfRes, name);
        }
    }
    else
    {
        cout << "File not opened" << endl;
    }

    // Close file
    fin.close();
}

//***********************************************************
// groupReservations: groups reservations so as not to exceed the ride capacity
// and outputs the number of guests for each ride and overall and the total
// number of rides to accommodate all reservations
// percentCapacity percent of the capacity available for rides due to COVID-19
// towerOfTerror Queue class that holds reservation data
//***********************************************************
void groupReservations(float percentCapacity, Queue &towerOfTerror)
{
   int sizeOfRes; // size of reservation
   string name; // name for a reservation
   int ride = 0; // used to track number of rides
   int overallGuests = 0; // used to track guests for all rides

   while(!towerOfTerror.isEmpty())
   {
        int guests = 0; // guests for a single ride
        ride++;

        cout << "Reservations for ride #" << ride << endl;
        cout << "Name                Size" << endl;
        cout << "----------          ---------" << endl;

        while(!towerOfTerror.isEmpty() && (guests+towerOfTerror.getSizeAtFront()
              <= (MAX_CAPACITY*percentCapacity)))
        {
           towerOfTerror.dequeue(sizeOfRes,name);
           guests += sizeOfRes;
           overallGuests += sizeOfRes;
           cout << setw(20) << left << name << sizeOfRes << endl;
        }

        cout << endl;
        cout << "Total number of guests on ride #" << ride << ": " << guests;
        cout << endl << endl;;
    }

    cout << "Number of guests for all reservations: " << overallGuests << endl;
    cout << "It took " << ride << " ride(s) to accommodate all reservations."
         << endl;
}
