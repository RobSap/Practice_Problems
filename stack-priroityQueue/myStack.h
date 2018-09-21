#ifndef MYSTACK_H
#define MYSTACK_H
#include <string>
#include "dequeue.h"

class myStack
{
    public:
        myStack(); // Default constructor, sets max size to 100
        myStack(int SIZE); //Overloaded constructor, sets max size to value of size parameter
        ~myStack(); // Destructor, deletes any allocated space
        void push(int value); //Pushes value on stack
        int pop(); // Removes and returns top value from stack
        int peek(); // Returns top value from stack, does not modify stack


    private:
    dequeue *theStack; // Using the class dequeue creats a pointer to thestack
    int maxSize;        //Used for max size
    int top;            // Keep track of whats on top

};

#endif // MYSTACK_H
