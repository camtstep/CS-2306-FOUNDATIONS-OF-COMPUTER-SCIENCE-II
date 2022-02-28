#ifndef PASSWORDMANAGER_H
#define PASSWORDMANAGER_H

// File Name: PasswordDriver.h
//
// Author: Cameron Stepanski
// Date: 6/17/2020
// Assignment Number: 3
// CS 2308.501 Summer 2020
// Instructor: Dr. J. Marcos Palacios
//
// Declaration for the PasswordManager class

using namespace std;

class PasswordManager
{
    private:
            string username; // stores username
            string password; // stores password
            string encrypt(string);
            bool meetsCriteria(string);
    public:
            void setUsername(string name);
            string getUsername() const;
            void setEncryptedPassword(string pass);
            string getEncryptedPassword() const;
            bool setNewPassword(string);
            bool authenticate(string);
};

#endif
