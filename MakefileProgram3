# CS 2308 - Program 3
# makefile for PasswordManager class program with three files:
# PasswordManager.h,
# PasswordManager.cpp,
# PasswordDriver.cpp

a.out: PasswordDriver.o PasswordManager.o
	g++ -std=gnu++0x PasswordDriver.o PasswordManager.o

PasswordDriver.o: PasswordDriver.cpp PasswordManager.h
	g++ -std=gnu++0x -c PasswordDriver.cpp

PasswordManager.o: PasswordManager.cpp PasswordManager.h
	g++ -std=gnu++0x -c PasswordManager.cpp
