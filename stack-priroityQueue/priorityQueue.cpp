#include "priorityQueue.h"
#include <string> // Lets me use strings
//#include <iostream> // Allows the cout and endl -- Taken out because wasn't required and used for debugging
#include <sstream> // used for strings std::stringstream ss; "to read in strings"



priorityQueue::priorityQueue() // Default constructor, sets max size to 100
{
    maxSize=100;                //If no size is entered, the default is  100
    queArray = new int[maxSize]; // Creates a que Array
    positionIndex =0;           // Sets my posotion index to 0, so starting the array at 0
    save = 0;                   // Used to save a position in a function below
    for (int x = 0; x < maxSize; x++)
        {
            queArray[x]= 0; // By setting to Null, in case a number actualy is 0
        }
}

priorityQueue::~priorityQueue() // Destructor, delets any allocated space
{
    delete []queArray;          //Deletes queArray when its done
}

priorityQueue::priorityQueue(int size) // Overloaded constructor, sets max size to value of size parameter
{
    maxSize = size;
    queArray = new int[maxSize]; // Creates a que Array
    positionIndex =0;           // Sets my posotion index to 0, so starting the array at 0
    save = 0;                   // Used to save a position in a function below
    for (int x = 0; x < maxSize; x++)
        {
            queArray[x]= 0; // By setting to Null, in case a number actualy is 0
        }
}

void priorityQueue::addValue(int value) // Adds value, 0(1)
{
    queArray[positionIndex++] = value; // Each time add is called it adds a number
                                    // Also the position index is on the next available open spot
}

int priorityQueue::getSmallest() // Removes and returns smallest value from queue, o(N)
{
    int lowest = queArray[positionIndex-1]; // Puts a default into the lowest - also the positon index is -1 because it the index is on next "open" spot and we need the last filled
        for (int i = positionIndex; i>0; i--) // If position is smaller then the current position then keep going
            {
                int temp=queArray[i-1]; //moves the array down so there is no holes
                if(temp < lowest) // If this number is bigger then the temp, enter the loop
                {
                    save = i-1;
                    lowest=temp; // Puts new value into the lowest
                }
            }
    queArray[save] = queArray[positionIndex-1]; //Takes the top number of the queue and puts it into the lowests spot
    positionIndex--; //Because a number is removed the index is lowered by 1
    return lowest; // returns the lowest number
}

bool priorityQueue::isEmpty() // Returns true if queue is empty, false otherwise
{
if (positionIndex==0) // Because adding only 1 value moves the index marker to 1
    return true;

else                    //If position is anything besides 0, its not empty
    return false;
}

bool priorityQueue::isFull() // Returns true if no more room in queue. false otherwise
{
if (positionIndex==maxSize)
    return true;            //if position of the index is the same as the max size its full "Note max size is input-1 becaue it starts on 0"

else                        //If it has anything besides full its false
    return false;
}
std::string priorityQueue::dumpArray() // Debug method that dmpbs the array from - to size -1
{
         std::string out = ""; // Out is the where the string of numbers are getting put into
    for ( int i =0; i < positionIndex; i++)
        {
            std::stringstream ss; //This alloys you to bring an arrays number into a string
            ss << queArray[i]; // Tells array to output array as string stream
            out += ss.str() + " "; // Sends string to out
            if(i % 10 == 9) // This sets it in rows of no more then 10 just incase you want to input more
            {
                out += "\n"; //Line break
            }
        }
        return out; // Returns a string of integers out
}
