// File Name: program2_cts96.cpp
//
// Cameron Stepanski
// Date: 6/10/2020
// Assignment Number: 2
// CS 2308.501 Summer 2020
// Instructor: Dr. J. Marcos Palacios
//
// This program reads in movie data from a file and allows the user to select
// whether to display movies sorted by title, display movies sorted by rating,
// look up a title and actors by id, look up an id by title and actors, or to
// quit the program. It utilizes search and sort mechanisms we've learned so far
// this summer session.

#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

struct MovieData
{
    string id; // id of movie
    string title; // title of movie
    string actor1; // actor in movie
    string actor2; // actor in movie
    int yearReleased; // release year of movie
    float rating; // rating of movie
};

// prototypes
void readData(MovieData[], int&);
void menu(int&);
void swapStructs(MovieData[], int);
void sortTitle(MovieData[], int);
void displayMovie(MovieData[], int);
void sortRating(MovieData[], int);
void sortId(MovieData[], int);
void searchId(MovieData[], int);
void searchTitleAndActor(MovieData[], int);

int main()
{
    const int MAX_SIZE = 100; // max number of movies that could be in the file
    MovieData movie[MAX_SIZE]; // array of 100 MovieData structures
    int counter; // number of movies in file
    int choice; // user's choice from menu

    // constants for menu choices
    const int SORTED_BY_TITLE = 1; // option 1 sorts by title
    const int SORTED_BY_RATING = 2; // option 2 sorts by rating
    const int LOOKUP_TITLE_AND_ACTORS = 3; // option 3 looks up by title & actor
    const int LOOKUP_ID = 4; // option 4 looks up by movie id
    const int QUIT = 5; // option 5 quits the program

    // open and read file, get movie count, and close file
    readData(movie, counter);

    do{
    // display menu and get user choice
    menu(choice);

    // validate the menu selection
    while(choice < SORTED_BY_TITLE || choice > QUIT)
    {
        cout << "Invalid selection. Please select from menu options 1-5.";
        cout << endl << endl;
        menu(choice);
    }

    // perform a task based on the user's choice
    switch(choice)
    {
        case SORTED_BY_TITLE:
             sortTitle(movie, counter);
             displayMovie(movie, counter);
             break;
        case SORTED_BY_RATING:
             sortRating(movie, counter);
             displayMovie(movie, counter);
             break;
        case LOOKUP_TITLE_AND_ACTORS:
             sortId(movie, counter);
             searchId(movie, counter);
             break;
        case LOOKUP_ID:
             searchTitleAndActor(movie, counter);
             break;
    }
    }while(choice != QUIT);

    cout << "Thank you for using the redbox.com app" << endl;

    return 0;
}

//***********************************************************
// readData: reads data from "program2_library.txt" file
// movie array of MovieData structures
// counter number of movies in the file
//***********************************************************
void readData(MovieData movie[], int &counter)
{
    // open file
    ifstream fin; // input file stream
    fin.open("program2_library.txt");

    counter = 0;

    // read in data
     while(fin >> ws && getline(fin, movie[counter].id))
    {
        fin >> ws;
        getline(fin, movie[counter].title);
        fin >> ws;
        getline(fin, movie[counter].actor1);
        fin >> ws;
        getline(fin, movie[counter].actor2);
        fin >> movie[counter].yearReleased;
        fin >> movie[counter].rating;

        counter++;
    }

    // close file
    fin.close();
}

//***********************************************************
// menu: displays menu options and allows user to select a choice
// choice option selected by user
//***********************************************************
void menu(int &choice)
{
    cout << "Menu" << endl << endl;
    cout << "1. Display movies sorted by title" << endl;
    cout << "2. Display movies sorted by rating" << endl;
    cout << "3. Lookup title and actors by id" << endl;
    cout << "4. Lookup id by title and either actor" << endl;
    cout << "5. Quit the program" << endl << endl;

    cout << "Enter your choice: ";
    cin >> choice;
}

//***********************************************************
// swapStructs: swaps order of MovieData structures in an array
// a array of MovieData structures
// index position of MovieData structure that will be swapped with
// the subsequent MovieData structure
//***********************************************************
void swapStructs(MovieData a[], int index)
{
    MovieData temp; // used to hold data during a swap

    temp.id = a[index].id;
    temp.title = a[index].title;
    temp.actor1 = a[index].actor1;
    temp.actor2 = a[index].actor2;
    temp.yearReleased = a[index].yearReleased;
    temp.rating = a[index].rating;

    a[index].id = a[index+1].id;
    a[index].title = a[index+1].title;
    a[index].actor1 = a[index+1].actor1;
    a[index].actor2 = a[index+1].actor2;
    a[index].yearReleased = a[index+1].yearReleased;
    a[index].rating = a[index+1].rating;

    a[index+1].id = temp.id;
    a[index+1].title = temp.title;
    a[index+1].actor1 = temp.actor1;
    a[index+1].actor2 = temp.actor2;
    a[index+1].yearReleased = temp.yearReleased;
    a[index+1].rating = temp.rating;
}

//***********************************************************
// sortTitle: bubble sort function that sorts movie titles in
// ascending alphabetical order
// movie array of MovieData structures
// counter number of movies in the file
//***********************************************************
void sortTitle(MovieData movie[], int counter)
{
    int maxElement; // last element in the array
    int index; // position in each array

    for(maxElement=counter-1; maxElement>0; maxElement--)
        for(index=0; index<maxElement; index++)
            if(movie[index].title > movie[index+1].title)
                swapStructs(movie, index);
}

//***********************************************************
// displayMovie: display contents of an array of MovieData structures
// movie array of MovieData structures
// counter number of movies in the file
//***********************************************************
void displayMovie(MovieData movie[], int counter)
{
    cout << endl;

    for(int i=0; i<counter; i++)
    {
        cout << left;
        cout << setw(21) << movie[i].title;
        cout << setw(20) << movie[i].actor1;
        cout << setw(15) << movie[i].actor2;
        cout << right;
        cout << setw(6) << movie[i].yearReleased;
        cout << setw(5) << movie[i].rating;
        cout << endl;
    }

    cout << endl;
}

//***********************************************************
// sortRating: bubble sort function that sorts ratings in descending order
// movie array of MovieData structures
// counter number of movies in the file
//***********************************************************
void sortRating(MovieData movie[], int counter)
{
    int maxElement; // last element in the array
    int index; // position in each array

    for(maxElement=counter-1; maxElement>0; maxElement--)
        for(index=0; index<maxElement; index++)
            if(movie[index].rating < movie[index+1].rating)
                swapStructs(movie,index);
}

//***********************************************************
// function name: short description of what the function does.
// movie array of MovieData structures
// counter number of movies in the file
//***********************************************************
void sortId(MovieData movie[], int counter)
{
    int maxElement; // last element in the array
    int index; // position in each array

    for(maxElement=counter-1; maxElement>0; maxElement--)
        for(index=0; index<maxElement; index++)
            if(movie[index].id > movie[index+1].id)
                swapStructs(movie,index);
}

//***********************************************************
// searchId: searches movie id using binary search function
// movie array of MovieData structures
// counter number of movies in the file
//***********************************************************
void searchId(MovieData movie[], int counter)
{
    string id; // movie id number

    cout << "Enter the id of the movie: ";
    cin >> id;
    cout << endl;

    int first = 0; // first index in each pass
    int last = counter-1; // last index in each pass
    int middle; // middle index in each pass
    int position = -1; // index of id if found, -1 if not found
    bool found = false; // indicates if movie number has been found

    while(!found && first <=last)
    {
        middle = (first+last)/2;
        if(movie[middle].id == id)
        {
            found = true;
            position = middle;
        }
        else if(movie[middle].id > id)
            last = middle-1;
        else
            first = middle+1;
    }

    // display data about movie corresponding to movie id
    if(position>-1)
    {
        cout << "The movie with id " << id << " is:" << endl;
        cout << movie[position].title << endl;
        cout << "Actors:" << endl;
        cout << movie[position].actor1 << endl;
        cout << movie[position].actor2 << endl;
    }
    else
    {
        cout << "No movie found with that id.";
    }

    cout << endl << endl;

}

//***********************************************************
// searchTitleAndActor: searches title and actor using linear search
// movie array of MovieData structures
// counter number of movies in the file
//***********************************************************
void searchTitleAndActor(MovieData movie[], int counter)
{
    string title; // movie title
    string actor; // actor in movie

    cout << "Enter the title: ";
    cin >> ws;
    getline(cin,title);
    cout << "Enter either actor: ";
    cin >> ws;
    getline(cin,actor);

    int index = 0; // index in array of MovieData structures
    int position = -1; // index of structure corresponding to title and actor,
                       // -1 if not found
    bool found = false; // indicates if title and actor have been found

    while(index<counter && !found)
    {
        if(movie[index].title == title && (movie[index].actor1 == actor
           || movie[index].actor2 == actor))
        {
            found = true;
            position = index;
        }
        index++;
    }

    // display movie id corresponding to title and actor
    if(position>-1)
    {
        cout << endl;
        cout << "The id of " << movie[position].title << " with "
        << movie[position].actor1 << " and " << movie[position].actor2 << " is "
        << movie[position].id;
    }
    else
    {
        cout << endl;
        cout << "No id found.";
    }

    cout << endl << endl;
}
