#include <iostream> // for cout, cin
#include "dequeue.h" // functions used locally here
#include <ctime> // For my random number function (srand(time(0));)
#include <cstdlib> // For my random number function (srand(time(0));)
#include "myStack.h"
#include "priorityQueue.h"

using namespace std;

int main()
{
int temp; // Temp Variable to hold incomming values
const int SIZE = 10; //Size 1 to test for errors
const int SIZE2 =30; // sets the number of variables allowed in to 30

srand(time(0)); //Sets the random to computer time
dequeue test(SIZE); // Sets my first tester
dequeue test2(SIZE2); // Sets up my second tester


cout << "Is the array empty? Yes = 1 No = 0" << endl; // Check if array is empty
cout<< test.isEmpty() <<endl;
cout << "Is the array full? Yes = 1 No = 0" << endl; // Checks if array is full
cout<< test.isFull()<<endl;

cout << "Testing array 1" <<endl; // First Dequest to test

temp = rand()%100; // Generates a random number
test.addRight(temp); //  puts random number into fuction'
cout << "Add from Right"<<endl;
cout << test.listLeftRight()<<endl<<endl;

temp = rand()%100; // Generates a random number
test.addLeft(temp); //  puts random number into fuction'
cout << "Add from Left"<<endl;
cout << test.listLeftRight()<<endl<<endl;

temp = rand()%100; // Generates a random number
test.addRight(temp); //  puts random number into fuction'
cout << "Add from Right"<<endl;
cout << test.listLeftRight()<<endl<<endl;

temp = rand()%100; // Generates a random number
test.addLeft(temp); //  puts random number into fuction'
cout << "Add from Left"<<endl;
cout << test.listLeftRight()<<endl<<endl;

temp = rand()%100; // Generates a random number
test.addRight(temp); //  puts random number into fuction'
cout << "Add from Right"<<endl;
cout << test.listLeftRight()<<endl<<endl;

temp = rand()%100; // Generates a random number
test.addLeft(temp); //  puts random number into fuction'
cout << "Add from Left"<<endl;
cout << test.listLeftRight()<<endl<<endl;

cout << "Test get right" <<endl;
cout <<test.getRight()<<endl; // Deletes from the right marker

cout << "Test get left" <<endl;
cout <<test.getLeft()<<endl; // Deletes from the left marker

cout << "Test get right" <<endl;
cout <<test.getRight()<<endl; // Deletes from the right marker

cout << "Test get left" <<endl;
cout <<test.getLeft()<<endl; // Deletes from the left marker

cout << "Display from right to left" <<endl;
cout << test.listRightLeft()<<endl; // Show the numbers in the dequeue from right to left

cout << "Display from left to right" <<endl;
cout << test.listLeftRight()<<endl; // Show the numbers in the dequeue from left to right


cout << "Is the array empty? Yes = 1 No = 0" << endl; // Checks if array is empty
cout<< test.isEmpty() <<endl;
cout << "Is the array full? Yes = 1 No = 0" << endl; // Checks if array is full
cout<< test.isFull()<<endl;

cout << "Welcome to array test 2" <<endl<<endl;
cout << "Is the array empty? Yes = 1 No = 0" << endl; // Checks if array is empty
cout<< test2.isEmpty() <<endl;
cout << "Is the array full? Yes = 1 No = 0" << endl; // Checks if array is full
cout<< test2.isFull()<<endl;

cout << "Insert random values into new myArray, size 30" << endl;

for (int i = 0; i < SIZE2/2 ; i++) // This for loop generatese my random numbers

    {
        temp = rand()%100; // Generates a random number
        test2.addRight(temp); //  puts random number into fuction
        cout << "Add from Right"<<endl;
         cout << test2.listLeftRight()<<endl<<endl; // Display from left to right
    }

for (int i = 0; i < SIZE2/2 ; i++) // This for loop generatese my random numbers
    {

        temp = rand()%100; // Generates a random number
        test2.addLeft(temp); //  puts random number into fuction'
        cout << "Add from Left"<<endl;
        cout << test2.listLeftRight()<<endl<<endl; // Display from left to right
    }


cout << "Display from right to left" <<endl;
cout << test2.listRightLeft()<<endl; // Display the dequeue from right to left

cout << "Display from left to right" <<endl;
cout << test2.listLeftRight()<<endl; // Display from left to right


cout << "Is the array empty? Yes = 1 No = 0" << endl; // Checks if array is empty
cout<< test2.isEmpty() <<endl;
cout << "Is the array full? Yes = 1 No = 0" << endl; // Checks if array is full
cout<< test2.isFull()<<endl;


 cout << "Test get right" <<endl;
 cout <<test2.getRight()<<endl; // Moves increment of right marker down 1

 cout << "Test get left" <<endl;
 cout <<test2.getLeft()<<endl; // Moves increment of left marker down 1

 cout << "Display from left to right, showing get right/left works" <<endl;
   cout << test2.listLeftRight()<<endl; // Displays dequeue from left to right

cout << "Display from right to left, showing that reverse display works" <<endl;
 cout << test2.listRightLeft()<<endl; // Displays dequeue from right to left


cout << "Is the array empty? Yes = 1 No = 0" << endl;  // Checks if array is empty
cout<< test2.isEmpty() <<endl;
cout << "Is the array full? Yes = 1 No = 0" << endl; // Checks if array is full
cout<< test2.isFull()<<endl;


cout << "Delete Array, Nothing should show" << endl;
test2.zeroOut(); // Zeros out the array
   cout << test2.listLeftRight()<<endl; // Displays dequeue left to right

cout << "Time to test stack" << endl;

cout << " \nMake a stack size 5 \n";
myStack theStack(5); //Makes a stack of 5
cout << "Adding #6" <<endl;
 theStack.push(6); //Puts #6 on top
cout << "Adding #7" <<endl;
 theStack.push(7); // Puts #7 on top of 6
 cout << "Adding #8" <<endl;
 theStack.push(8); // Puts #8 on top of stack


cout << " Peek (top view), should be 8 = " << theStack.peek() << endl; //Show number on top of stack
cout << " First pop, should be 8 = " << theStack.pop() << endl; //Shows number on top of stack and deletes it
cout << " Second pop, should be 7 = " << theStack.pop() << endl; //Shows number on top of stack and deletes it
cout << " Last pop, should be 6 = " << theStack.pop() << endl<<endl; //Shows number on top of stack and deletes it


cout << "Now testing priority queue (7 long)"<<endl;

priorityQueue PQ(7); //Makes a priorityQueue size 7

cout << "Is the array empty? Yes = 1 No = 0" << endl; //Checks to see if its empty
cout<< PQ.isEmpty() <<endl;
cout << "Is the array full? Yes = 1 No = 0" << endl; // Checks to see if its full
cout <<PQ.isFull() <<endl;



cout << "Adding 7 values to the que: " <<endl <<endl;

PQ.addValue(34); //Adds value 34
PQ.addValue(60); //Adds value
PQ.addValue(12); //Adds value
PQ.addValue(38); //Adds value
PQ.addValue(7); //Adds value
PQ.addValue(58); //Adds value
PQ.addValue(16); //Adds value

cout << "Is the array empty? Yes = 1 No = 0" << endl; // Checks to see if its empty
cout<< PQ.isEmpty() <<endl;
cout << "Is the array full? Yes = 1 No = 0" << endl; // Checks to see if its full
cout <<PQ.isFull() <<endl;

cout << "The array looks like :" <<endl; //Shows whats in array
cout << PQ.dumpArray()<<endl;

cout << "The smallest is should be 7, removed:" <<endl; //Pulls out smallest number, and takes the last number (top) in queue and puts it in smallests place
cout <<PQ.getSmallest() <<endl;

cout << "The new array looks like :" <<endl; //Display new priority queueu
cout << PQ.dumpArray()<<endl;


cout << "Is the array empty? Yes = 1 No = 0" << endl; //Checks if its empty
cout<< PQ.isEmpty() <<endl;
cout << "Is the array full? Yes = 1 No = 0" << endl; // Checks if its full
cout <<PQ.isFull() <<endl;

return 0;

}

