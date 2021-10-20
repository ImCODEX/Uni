#include <exception>
#include "BagIterator.h"
#include "Bag.h"
#include <iostream>

using namespace std;

//Theta(m)
BagIterator::BagIterator(const Bag &c) : bag(c), current_position(0), current_frequency(0), last_pos(bag.m - 1) {
    while (current_position < bag.m && (bag.elems[current_position].value == bag.deleted() || bag.elems[current_position].value == bag.empty())) {
        current_position++;
    }
    first_pos = current_position;
    current_frequency = bag.elems[current_position].frequency;
}
//Theta(1)
void BagIterator::first() {
    current_position = first_pos;
    current_frequency = bag.elems[current_position].frequency;
}

//BC: Theta(1) WC: Theta(m)
void BagIterator::next() {
    if(!valid())
        throw std::exception();

    if(current_frequency > 1)
        current_frequency--;
    else{

        current_position++;
        while (current_position < bag.m && (bag.elems[current_position].value == bag.deleted() || bag.elems[current_position].value == bag.empty())) {
            current_position++;
        }
        if(valid())
            current_frequency = bag.elems[current_position].frequency;
        else
            current_frequency = 0;
    }
}

//Theta(1)
bool BagIterator::valid() const {
    return current_position < bag.m - 1 || (current_position == bag.m -1 && current_frequency >= 1);
}

//Theta(1)
TElem BagIterator::getCurrent() const {
    if(!valid())
        throw std::exception();
    return bag.elems[current_position].value;
}
