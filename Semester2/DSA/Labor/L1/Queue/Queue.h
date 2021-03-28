#pragma once
#include <vector>
using namespace std;

//DO NOT CHANGE THIS PART
typedef int TElem;
#define NULL_TELEM -11111

class Queue
{
private:
	//TODO - Representation
	TElem *array; // pointer at the first element of our array
	int size;	  // current size
	int capacity; // maximum size
	int front;	  // the index of the first element in the queue
	int rear;	  // the index of the next/last element in the queue

public:
	Queue();

	//pushes an element to the end of the queue
	void push(TElem e);

	//returns the element from the front of the queue
	//throws exception if the queue is empty
	TElem top() const;

	//removes and returns the element from the front of the queue
	//throws exception if the queue is empty
	TElem pop();

	//checks if the queue is empty
	bool isEmpty() const;

	// destructor
	~Queue();
};
