// File Name: PasswordManager.cpp
//
// Author: Cameron Stepanski
// Date: 6/17/2020
// Assignment Number: 3
// CS 2308.501 Summer 2020
// Instructor: Dr. J. Marcos Palacios
//
// Implementation of the PasswordManager class functions

#include <iostream>
#include <string>
#include <fstream>
#include "PasswordManager.h"

const int MINIMUM_LENGTH = 8; // minimum length of acceptable password

// Private members of PasswordManager class

//***********************************************************
// encrypt: encrypts a password using a Caesar Cipher
// pass unencrypted password
// returns the encrypted password
//***********************************************************
string PasswordManager::encrypt(string pass)
{
   for(int i=0; i<pass.length(); i++)
   {
       pass[i] = (((pass[i] - 33) + 25) % 94 + 33);
   }

   return pass;
}

//***********************************************************
// meetsCriteria: tests to see if a proposed password is 8+ characters
// long, contains at least one uppercase letter, one lowercase letter,
// and one digit
// password the proposed password
// returns true if all criteria has been met and false if not
//***********************************************************
bool PasswordManager::meetsCriteria(string password)
{
    bool allCriteria = false; // indicates if all criteria has been met
    bool length = false; // indicates if the password is 8+ characters
    bool uppercase = false; // indicates if there is at least 1 uppercase letter
    bool lowercase = false; // indicates if there is at least 1 lowercase letter
    bool digit = false; // indicate if there is at least 1 digit

    // Test password length
    if(password.length() >= MINIMUM_LENGTH)
    {
        length = true;
    }

    // Test for an uppercase letter
    for(int i=0; i<password.length() && !uppercase; i++)
    {
        char ch; // stores an individual character in a password

        ch = password[i];

        if(isupper(ch))
        {
            uppercase = true;
        }
    }

    // Test for a lowercase letter
    for(int i=0; i<password.length() && !lowercase; i++)
    {
        char ch; // stores an individual character in a password

        ch = password[i];

        if(islower(ch))
        {
            lowercase = true;
        }
    }

    // Test for a digit
    for(int i=0; i<password.length() && !digit; i++)
    {
        char ch; // stores an individual character in a password

        ch = password[i];

        if(isdigit(ch))
        {
            digit = true;
        }
    }

    // Tests if all password criteria has been met
    if(length && uppercase && lowercase && digit)
    {
        allCriteria = true;
    }

    return allCriteria;
}

// Public members of PasswordManager class

//***********************************************************
// setUsername: stores a username
// name username
//***********************************************************
void PasswordManager::setUsername(string name)
{
    username = name;
}

//***********************************************************
// getUsername: returns username
// returns username
//***********************************************************
string PasswordManager::getUsername() const
{
    return username;
}

//***********************************************************
// setEncryptedPassword: stores an encrypted password
// pass encrypted password
//***********************************************************
void PasswordManager::setEncryptedPassword(string pass)
{
    password = pass;
}

//***********************************************************
// getEncryptedPassword: returns encrypted password
// returns encrypted password
//***********************************************************
string PasswordManager::getEncryptedPassword() const
{
    return password;
}

//***********************************************************
// setNewPassword: tests password criteria and if it passes stores
// the encrypted password
// unencrypted proposed password
// returns true if new password has been set and false if not
//***********************************************************
bool PasswordManager::setNewPassword(string unencrypted)
{
    bool setPassword = false; // indicates if a new password has been set

    if(meetsCriteria(unencrypted))
    {
        password = encrypt(unencrypted);
        setPassword = true;
    }

    return setPassword;
}

//***********************************************************
// authenticate: tests if a password matches the encrypted password
// that is already stored in the member variable
// unencrypted password that is being tested for authentication
// returns true if password is authenticated and false if not
//***********************************************************
bool PasswordManager::authenticate(string unencrypted)
{
    bool authenticated = false; // indicates if old password is authenticated

    if(password == encrypt(unencrypted))
    {
        authenticated = true;
    }

    return authenticated;
}
