#include "Queue.h"
#include <exception>
#include <iostream>

using namespace std;

Queue::Queue()
{
	this->capacity = 25;
	this->front = 0;
	this->rear = 0;
	this->size = 0;
	this->array = new TElem[25];
}

void Queue::push(TElem elem)
{
	if (this->size == this->capacity-1)
	{
		int *new_array = new TElem[this->capacity * 2];
		int j = 0;
		if (this->rear < this->front)
		{
			for (int i = this->front; i < this->capacity; i++)
			{
				new_array[j] = this->array[i];
				j++;
			}
			for (int i = 0; i < this->front; i++)
			{
				new_array[j] = this->array[i];
				j++;
			}
		}
		else
		{
			for (int i = this->front; i <= this->rear; i++)
			{
				new_array[j] = this->array[i];
				j++;
			}
		}
		this->capacity = this->capacity * 2;
		this->front = 0;
		this->rear = this->size - 1;
		delete[] this->array;
		this->array = new_array;
	 }
	if (this->rear < this->capacity)
	{
		this->array[rear] = elem;
		this->rear++;
	}
	if (this->rear == this->capacity)
	{
		this->array[0] = elem;
		this->rear = 1;
	}

	this->size++;
	cout<<"size: "<<this->size<<endl;
	cout<<"capacity: "<<this->capacity<<endl;
	cout<<"[ ";
	for (int i = this->front ; i <= this->rear-1; i++)
		cout<<this->array[i]<<" ";
	cout<<"]";
}

TElem Queue::top() const
{
	if (this->size == 0)
		throw std::exception();
	return this->array[this->front];
	return NULL_TELEM;
}

TElem Queue::pop()
{
	int last_front = this->front;
	if (this->size == 0)
		throw std::exception();
	if (this->front < this->capacity - 1)
		this->front++;

	if (this->front == this->capacity - 1)
		this->front = 0;

	this->size--;
	return this->array[last_front];
	return NULL_TELEM;
}

bool Queue::isEmpty() const
{
	if (this->size == 0)
		return true;
	return false;
}

Queue::~Queue()
{
	delete[] this->array;
}
