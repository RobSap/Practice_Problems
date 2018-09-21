#ifndef PRIORITYQUEUE_H
#define PRIORITYQUEUE_H
#include <string>
#include "dequeue.h"

class priorityQueue
{
    public:
        priorityQueue(); // Default constructor, sets max size to 100
        priorityQueue(int size); // Overloaded constructor, sets max size to value of size parameter
        ~priorityQueue(); // Destructor, delets any allocated space
        void addValue(int value); // Adds value, 0(1)
        int getSmallest(); // Removes and returns smallest value from queue, o(N)
        int getLargest(); // Removes and returns largest value from queue, O(N)
        bool isEmpty(); // Returns true if queue is empty, false otherwise
        bool isFull(); // Returns true if no more room in queue. false otherwise
        std::string dumpArray(); // Debug method that dmpbs the array from - to size -1

    protected:
    private:
        int maxSize; // Saves max size value
        int *queArray; // My array
        int positionIndex; // Saves posotion of array
        int save;          // Used to hold an arrays posotion

};

#endif // PRIORITYQUEUE_H
