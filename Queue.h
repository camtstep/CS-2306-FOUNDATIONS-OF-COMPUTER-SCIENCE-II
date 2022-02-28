// File Name: Queue.h
//
// Author: Cameron Stepanski
// Date: 6/25/2020
// Assignment Number: 4
// CS 2308.501 Summer 2020
// Instructor: Dr. J. Marcos Palacios
//
// Class declaration and functions for Queue

#ifndef QUEUE_H_INCLUDED
#define QUEUE_H_INCLUDED
#include <iostream>
#include <string>

using namespace std;

class Queue
{
private:
    struct QueueNode
    {
        string name; // name on reservation
        int sizeOfReservation; // number of people for a reservation
        QueueNode *next; // pointer to the next node
    };

    QueueNode *front; // the front of the queue
    QueueNode *rear; // the rear of the queue
    int numItems; // number of items in the queue

public:
    //***********************************************************
    // Queue: constructor for Queue class that initializes variables
    //***********************************************************
    Queue()
    {
        front = nullptr;
        rear = nullptr;
        numItems = 0;
    }

    //***********************************************************
    // ~Queue: destructor for Queue class that clears queue
    //***********************************************************
    ~Queue()
    {
        clear();
    }

    //***********************************************************
    // enqueue: queues the data passed to it
    // sizeOfRes size of reservation
    // name name on reservation
    //***********************************************************
    void enqueue(int sizeOfRes, string name)
    {
        QueueNode *newNode = nullptr; // new node for a queue

        // Create a new node and store num there
        newNode = new QueueNode;
        newNode->sizeOfReservation = sizeOfRes;
        newNode->name = name;
        newNode->next = nullptr;

        // Adjust front and rear as necessary
        if(isEmpty())
        {
            front = newNode;
            rear = newNode;
        }
        else
        {
            rear->next = newNode;
            rear = newNode;
        }

        // Update numItems
        numItems++;
    }

    //***********************************************************
    // dequeue: removes a node from the queue in a first in first out manner
    // sizeOfRes size of reservation
    // name name on reservation
    //***********************************************************
    void dequeue(int &sizeOfRes, string &name)
    {
        QueueNode *temp = nullptr; // used to delete front node when dequeuing

        if(isEmpty())
        {
            cout << "The queue is empty" << endl;
        }
        else
        {
            // Save the front node sizeOfReservation and name
            sizeOfRes = front->sizeOfReservation;
            name = front->name;

            // Remove the front node and delete it
            temp = front;
            front = front->next;
            delete temp;

            // Update numItems
            numItems--;
        }
    }

    //***********************************************************
    // isEmpty: determines if a queue is empty or not
    // returns: true if the queue is empty and false if not
    //***********************************************************
    bool isEmpty() const
    {
        bool status; // indicates if a queue is empty

        if(numItems > 0)
            status = false;
        else
            status = true;

        return status;
    }

    //***********************************************************
    // clear: clears a queue
    //***********************************************************
    void clear()
    {
        int value; // Dummy variable for dequeue
        string nameValue;// Dummy variable for dequeue

        while(!isEmpty())
            dequeue(value, nameValue);
    }

    //***********************************************************
    // getSizeAtFront: indicates the size of the reservation at the front
    // returns: size of reservation at the front of a queue
    //***********************************************************
    int getSizeAtFront()
    {
        int sizeAtFront; // Size of reservation at front of the queue

        sizeAtFront = front->sizeOfReservation;

        return sizeAtFront;
    }
};

#endif // QUEUE_H_INCLUDED
