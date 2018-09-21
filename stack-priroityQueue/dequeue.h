#ifndef DEQUEUE_H
#define DEQUEUE_H
#include <string>
//#include <deque>

class dequeue
{
   public:
        dequeue(); // Default constructor, sets max size to 100
        dequeue(int SIZE); // Overloaded constructor, sets max Size to value of Size parameter
        ~dequeue(); // Destructor, deletes any allocated space
        void addLeft(int value); // Adds value to the left side of the dequeue
        void addRight(int value); // Adds value to the right side of the dequeue
        int getLeft(); //Removes and returns left most element
        int getRight(); // Removes and returns right most element
        bool isEmpty(); //Returns true if dequeue has no elents, false otherwise
        bool isFull(); // Returns true if dequeue has no room for new elements, false otherwise
        std::string listRightLeft(); // Returns a string containing the elements listed from side to left
        std::string listLeftRight(); // Returns a string containing the elements listed form left side to right
        std::string dumpArray(); // Debug method that dumpbs the array from 0 to size -1
        void zeroOut(); // debug method that sets array to zero so you can see where items were added
        int showTop();
    protected:
    private:
        int *myQueue; //array queue of type doubleQueue
        int maxSize; // Variablet to take in max size from man, or set default at 100
        int positionArrayLeft; //Left marker
        int positionArrayRight; // Right marker

};

#endif // DEQUEUE_H


