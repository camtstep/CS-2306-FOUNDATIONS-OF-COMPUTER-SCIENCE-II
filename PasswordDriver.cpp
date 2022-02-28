// File Name: PasswordDriver.cpp

//
// Author: Cameron Stepanski
// Date: 6/17/2020
// Assignment Number: 3
// CS 2308.501 Summer 2020
// Instructor: Dr. J. Marcos Palacios
//
// This program lets a user change the password for a username that's already in
// a given file. It tests to make sure the username exists, that the old
// password is authenticated, and that the proposed new password matches certain
// criteria. It displays messages accordingly.

#include <iostream>
#include <string>
#include <fstream>
#include "PasswordManager.h"

using namespace std;

int main()
{
    const int OBJECTS = 3; // 3 instances of the class PasswordManager
    fstream fin; // used to read in data from file

    // Create 3 instances of PasswordManager class
    PasswordManager instance[OBJECTS]; // 3 instances of PasswordManager class

    // Open file to read in user and password information
    fin.open("passwords.txt");

    if(fin)
    {
        for(int i=0; i<OBJECTS; i++)
        {
            string username; // stores username read in from file
            string password; // stores password read in from file

            fin >> username >> password;

            (instance+i)->setUsername(username);
            (instance+i)->setEncryptedPassword(password);
        }

        fin.close();
    }
    else
    {
        cout << "Input file does not exist" << endl;

        return 0;
    }

    // Get username and password information from user
    string username; // stores username input by user
    string oldPassword; // stores old password input by user
    string newPassword; // stores new password input by user

    cout << "Please enter your username: ";
    cin >> username;
    cout << endl;

    cout << "Please enter your old password: ";
    cin >> oldPassword;
    cout << endl;

    cout << "Please enter your new password: ";
    cin >> newPassword;
    cout << endl;

    // Check validity of username

    int index; // index of the PasswordManager class that's being modified
    bool usernameValid = false; // indicates a valid username has been received

    for(int i=0; i<OBJECTS; i++)
    {
        if(username == (instance+i)->getUsername())
        {
            index = i;
            usernameValid = true;
        }
    }

    if(!usernameValid)
    {
        cout << "Username is invalid, password not changed" << endl;
    }

    // Check validity of old password

    bool passwordValid = false; // indicates a valid password has been received

    if(usernameValid)
    {
        if((instance+index)->authenticate(oldPassword))
        {
            passwordValid = true;
        }
        else
        {
            cout << "Old password is incorrect" << endl;
        }
    }

    // Check for new password criteria

    bool passwordChanged = false; // indicates a successfully changed password

    if(usernameValid == true && passwordValid == true)
    {
        if((instance+index)->setNewPassword(newPassword))
        {
            cout << "Password has been changed for username: "
                 << (instance+index)->getUsername() << endl;

            passwordChanged = true;
        }
        else
        {
            cout << "New password does not meet criteria" << endl;
        }
    }

    // Write updated password information to file
    if(passwordChanged)
    {

        ofstream fout; // used to write data to file

        fout.open("passwords.txt");

        if(fout)
        {

            for(int i=0; i<OBJECTS; i++)
            {
                fout << (instance+i)->getUsername() << " "
                     << (instance+i)->getEncryptedPassword() << endl;
            }

            fout.close();
        }
    }
    return 0;
}
