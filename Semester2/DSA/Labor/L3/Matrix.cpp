#include "Matrix.h"
#include "MatrixIterator.h"
#include <exception>

using namespace std;

//Theta(n)
Matrix::Matrix(int nrLines, int nrCols) : nr_lines{nrLines}, nr_columns{nrCols}, head{-1}, tail{-1}, current_size{0},
                                          capacity{10}, first_empty{0} {
    if (nrLines <= 0 || nrCols <= 0)
        throw std::exception();
    array = new Node[capacity];
    for (int i = 0; i < capacity - 1; i++) //initialise next "pointers"
        array[i].next = i + 1;
    array[capacity - 1].next = -1; 
    for (int i = 1; i < capacity; i++) //initialise previous "pointers"
        array[i].prev = i - 1;
    array[0].prev = -1;
}

//Theta(delete[])
Matrix::~Matrix() {
    delete[] array;
}

//Theta(1)
MatrixIterator Matrix::iterator() const {
    return MatrixIterator(*this);
}

//Theta(n)
void Matrix::resize() {
    int new_capacity = 2 * capacity;
    Node *new_array = new Node[new_capacity];
    for (int i = 0; i < current_size; i++) //copy all elements over to the new array
        new_array[i] = array[i]; 
    for (int i = capacity; i < new_capacity - 1; i++)
        new_array[i].next = i + 1; //initialise next "pointers"
    new_array[new_capacity - 1].next = -1;
    for (int i = capacity + 1; i < new_capacity; i++) //initialise previous "pointers"
        new_array[i].prev = i - 1;
    new_array[capacity].prev = -1;
    first_empty = capacity;
    capacity = new_capacity;
    delete[] array;
    array = new_array;
}

//Theta(1)
int Matrix::allocate() {
    int new_elem = first_empty;
    if (new_elem != -1) { //check if array is not full
        first_empty = array[first_empty].next; //reinitialise first empty
        if (first_empty != -1)
            array[first_empty].prev = -1; //initialise invalid next prev "pointers" (we need to find the position of the elem in the array)
        array[new_elem].next = -1;
        array[new_elem].prev = -1;
    }
    return new_elem;
}

//Theta(1)
void Matrix::free(int pos) {
    array[pos].next = first_empty;
    array[pos].prev = -1;
    if (first_empty != -1)
        array[first_empty].prev = pos;
    first_empty = pos; //set current element to first_empty
}

//Theta(1)
int Matrix::nrLines() const {
    return nr_lines;
}

//Theta(1)
int Matrix::nrColumns() const {
    return nr_columns;
}

//Theta(1) or Theta(n)
TElem Matrix::element(int i, int j) const {
    if (i < 0 || j < 0 || i >= nr_lines || j >= nr_columns) //throw exception if i, j not valid
        throw std::exception();
    int current_node = head;
    while (current_node != -1) { //search the element by i, j
        if (array[current_node].i == i && array[current_node].j == j)
            return array[current_node].value;
        current_node = array[current_node].next;
    }
    return NULL_TELEM; //return -1 if not found
}

//Theta(1) or Theta(n)
void Matrix::insert_after(int prev_node_to_insert, int i, int j, TElem e) {
    int new_node = allocate();
    if (new_node == -1) {
        resize();
        new_node = allocate();
    }
    array[new_node].value = e;
    array[new_node].i = i;
    array[new_node].j = j;
    if (prev_node_to_insert == -1) { //if prev_node_to_insert == -1 either array is empty, or elements have higher "i,j" values
        if (head == -1) { // check if array is empty
            head = new_node;
            tail = new_node; //initialise head & tail
        } else {
            array[new_node].next = head; //change head
            array[head].prev = new_node;
            head = new_node;
        }
    } else {
        int node_next = array[prev_node_to_insert].next; //save the next node after our prev_node_to_insert
        array[new_node].next = node_next; //new element will point to the next element of prev_node_to_insert
        array[new_node].prev = prev_node_to_insert; //new element prev pointer will be prev_node_to_insert
        array[prev_node_to_insert].next = new_node; //prev_node_to_insert will point to our newly added element
        if (node_next == -1) { //check if tail
            tail = new_node;
        } else {
            array[node_next].prev = new_node; //the next node after our prev_node_to_insert, prev pointer will be our newly added element
        }
    }
}

//Theta(1) or Theta(n)
TElem Matrix::modify(int i, int j, TElem e) {
    if (i < 0 || j < 0 || i >= nr_lines || j >= nr_columns) //check if i, j valid positions
        throw std::exception();
    int current_node = head, prev_node_to_insert = -1;
    while (current_node != -1) { //go trough array
        if (array[current_node].i == i && array[current_node].j == j) { //find element
            if (e != NULL_TELEM) { //check if new_value != 0
                TElem old_value = array[current_node].value; //keep old_value
                array[current_node].value = e; //change value
                return old_value;
            } else {
                TElem old_value = array[current_node].value;
                if (current_node == head) //if current_element is head
                    head = array[current_node].next; //reinitialise head
                if (current_node == tail) 
                    tail = array[current_node].prev;
                if (array[current_node].prev != -1){ //if not head or tail
                    array[array[current_node].prev].next = array[current_node].next; 
                    array[array[current_node].next].prev = array[current_node].prev; //*
                }
                free(current_node);
                current_size--;
                return old_value;
            }
        }
        if (array[current_node].i < i || (array[current_node].i == i && array[current_node].j < j)) //find elem to insert after
            prev_node_to_insert = current_node;
        current_node = array[current_node].next;
    }
    if (e != NULL_TELEM) { //case: old_value=0, new_value!=0
        insert_after(prev_node_to_insert, i, j, e);
        current_size++;
    }
    return NULL_TELEM;
}