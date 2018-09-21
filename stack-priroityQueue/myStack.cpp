#include "myStack.h"

myStack::myStack() // Default constructor, sets max size to 100
{
maxSize=100;       //Default size of array if none is declared
theStack = new dequeue(maxSize);    //Creates the stack to use from dequeue class
top = 0;       // starts top value at 0
}

myStack::myStack(int SIZE)//Overloaded constructor, sets max size to value of size parameter
{
maxSize=SIZE;  //takes the size input and sets it as the max size
theStack = new dequeue(maxSize);    //Creates the stack to use from dequeue class
top = 0;       // starts top value at 0
}
myStack::~myStack() // Destructor, deletes any allocated space
{
delete theStack;
}

void myStack::push(int value) //Pushes value on stack
{
theStack->addLeft(value);
}

int myStack::pop() // Removes and returns top value from stack
{
return theStack->getLeft(); //Uses the getLeft function which takes the farthest right value, or in the stacks case top
}

int myStack::peek() // Returns top value from stack, does not modify stack
{
return theStack->showTop(); // Shows the top of the stacks only, without deleting it
}




