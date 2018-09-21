#include "dequeue.h"
#include <string> // Lets me use strings
//#include <iostream> // Allows the cout and endl -- Taken out because wasn't required and used for debugging
#include <sstream> // used for strings std::stringstream ss; "to read in strings"


dequeue::dequeue() // Default constructor, sets max size to 100
{
maxSize = 100;     //If no input, sets default size to 100
myQueue = new int[maxSize]; //Makes a dequeue named myQueue of integers
positionArrayRight=0;       //Sets array input (marker) that moves left to right to 0
positionArrayLeft=-1;       //Sets array input (marker) that moves right to left to -1
for (int x = 0; x < maxSize; x++)
    {
        myQueue[x]= 0; // Sets default to 0, initilizes array
    }
}


dequeue::dequeue(int SIZE) // Overloaded constructor, sets max Size to value of Size parameter
{

maxSize=SIZE;               //Takes the size givinig and sets it as max size
myQueue = new int[maxSize]; //Makes a dequeue named myQueue of integers
positionArrayRight=0;       //Sets array input (marker) that moves left to right to 0
positionArrayLeft=-1;       //Sets array input (marker) that moves right to left to -1
for (int x = 0; x < maxSize; x++)
    {
        myQueue[x]= 0; // Sets default to 0, initilizes array
    }
}

dequeue::~dequeue() // Destructor, deletes any allocated space
{
delete []myQueue;       //Delets the array myQueue
}

void dequeue::addLeft(int value) // Adds value to the left side of the dequeue
{
 if(positionArrayLeft < 0 && isFull()==false) //Adds only if not full
        {
            int j = maxSize+positionArrayLeft; //Since posotion array starts at -1 and goes left, it has a negative value, and adds to maxsize for correct position
        myQueue[j] = value; //Takes the value in from random into value, and puts it into the myQueue at count spot j
        positionArrayLeft--; // Moves the marker down

        }
    if(positionArrayLeft >= 0&& isFull()==false) //Adds only if not full
     {
        myQueue[positionArrayLeft++] = value; //Takes the value and puts it into the myqueue at the posotion, and then increases the marker
        }

}

void dequeue::addRight(int value) // Adds value to the right side of the dequeue
{
 if(positionArrayRight >= 0 && isFull() !=true) //Ensures the position is less then number of elements
        {
            myQueue[positionArrayRight++] = value; //Takes random value and puts into queue and moves marker right
        }
 if(positionArrayRight < 0 && isFull() !=true) //Adds it not full
        {
            myQueue[maxSize+positionArrayRight] = value; //If markers is moved left, it can take the marker and move it left
            positionArrayRight--;
        }

}

int dequeue::getLeft() //Removes and returns left most element
{
    if(positionArrayLeft < 0)
    {
        int j = maxSize+positionArrayLeft+1; //Makes sure the array marker the moved left through negatives stays or gets placed in right spot. The +1 is for starting at -1
        positionArrayLeft++; //Moves the marker
        return myQueue[j];
    }

    if(positionArrayLeft >= 0)
    {
        return myQueue[positionArrayLeft++]; //If the dequeue moves the other way the left marker can move right
    }
        else
            return -1; //In case any error do nothing
}
int dequeue::getRight() // Removes and returns right most element
{
    if(positionArrayRight >= 0) //Depending where marker is sets if
            {
                positionArrayRight--; //Moves marker down one from right
                return  myQueue[positionArrayRight]; //Returns the right posotion

            }
     if(positionArrayRight < 0) //Depending where marker is sets if
            {
                positionArrayRight++; // Moves marker up one from right
                return myQueue[maxSize+positionArrayRight]; //Because in this case it can be negative, you add it for correct position
            }
    else
        return -1; //In case any error do nothing
}

bool dequeue::isEmpty() //Returns true if dequeue has no elents, false otherwise
{
if (positionArrayLeft==-1 || positionArrayRight==0) // Checks if either marker has moved
    return true;
else
    return false; // If not return false
}

bool dequeue::isFull() // Returns true if dequeue has no room for new elements, false otherwise
{
if((isEmpty()==false) && (positionArrayRight+(positionArrayLeft+1)*-1==30)) // Checks if either one is full. Array left is multiplied by *1 to change the value to compare
    return true;
else
    return false; // If not return false
}


std::string dequeue::listRightLeft() // Returns a string containing the elements listed from side to left
{

         std::string out = ""; // Out is the where the string of numbers are getting put into
int j = 0;
    for ( int i = maxSize-1; i > maxSize+1+positionArrayLeft; i--) //Starts far far right side of array and moves down to the marker
        {
            std::stringstream ss; //This alloys you to bring an arrays number into a string
            ss << myQueue[i]; // Tells array to output array as string stream
            out += ss.str() + " "; // Sends string to out
            if(i % 10 == 0) // This sets it in rows of no more then 10
            {
                out += "\n"; //Line break
            } j =i;
        }
          for ( int i = positionArrayRight; i >= 0; i--) // Starts at position of far right, and moves down to the marker
        {j--;
            std::stringstream ss;
            ss << myQueue[i]; // Tells array to output array as string stream
            out += ss.str() + " "; // Sends string to out
            if(j % 10 == 0) // This sets it in rows of no more then 10
            {
                out += "\n"; //Line break
            }
        }
    return out;
}
std::string dequeue::listLeftRight() // Returns a string containing the elements listed form left side to right
{
        int k;
         std::string out = ""; // Out is the where the string of numbers are getting put into

    for ( int i = 0; i < positionArrayRight; i++) //Starts at 0 and moves up to marker
        {
            std::stringstream ss;
            ss << myQueue[i]; // Tells array to output array as string stream
            out += ss.str() + " "; // Sends string to out
            if(i % 10 == 9) // This sets it in rows of no more then 10
            {
                out += "\n"; //Line break
            }
             k =i;
        }
        for ( int j = (maxSize+1+positionArrayLeft); j < maxSize; j++) //Starts at marker "left" and moves up to arrays size
        { k++;
            std::stringstream ss;
            ss << myQueue[j]; // Tells array to output array as string stream
            out += ss.str() + " "; // Sends string to out
            if(k % 10 == 9) // This sets it in rows of no more then 10
            {
                out += "\n"; //Line break
            }
        }
    return out;
}
std::string dequeue::dumpArray() // Debug method that dumpbs the array from 0 to size -1
{
std::string out = ""; // Out is the where the string of numbers are getting put into

    for ( int i = 0; i < maxSize; i++) //Starts at 0 and moves up to marker
        {
            std::stringstream ss;
            ss << myQueue[i]; // Tells array to output array as string stream
            out += ss.str() + " "; // Sends string to out
            if(i % 10 == 9) // This sets it in rows of no more then 10
            {
                out += "\n"; //Line break
            }
        }
    return out; //Returns out -- if the dequeue has nothing in it, nothing will display
}

void dequeue::zeroOut() // debug method that sets array to zero so you can see where items were added
{
positionArrayRight=0; //Sets marker back to original spot
positionArrayLeft=-1; //Sets marker back to original spot
for (int x = 0; x < maxSize; x++)
    {
        myQueue[x]= 0; // By setting to Null, in case a number actualy is 0
    }
}

int dequeue::showTop() //Used to look at the top of the dequeue, or stack , or array
{
   if(positionArrayLeft < 0) //Ensures the position is less then number of elements
        {
            int j = maxSize+positionArrayLeft+1;
            return myQueue[j]; //Returns top of stack, even if its negative path
        }
    if(positionArrayLeft >= 0)
        {
            return myQueue[maxSize+positionArrayLeft]; // If positive, returns top of stack
        }
    else return 0;
}



