#include "Bag.h"
#include "BagIterator.h"
#include <exception>
#include <iostream>
#include <cmath>

using namespace std;

//Theta(m)
Bag::Bag() : m{16}, current_size(0), current_deleted(0) {
    elems = new Pair[m];
    for (int i = 0; i < m; i++) {
        elems[i].value = empty();
        elems[i].frequency = 0;
    }
}

Bag::Bag(const Bag &b) : m{b.m}, current_size(b.current_size), current_deleted(b.current_deleted) {
    elems = new Pair[m];
    for (int i = 0; i < m; i++) {
        elems[i] = b.elems[i];
    }
}

//BC: Theta(1) WC: Theta(m)
void Bag::add(TElem elem) {
    if (current_size == m - 1) resize_up_rehash();
    int i = 0;
    while (i < m) {
        int pos = hash_function(elem, m, i);
        if (elems[pos].value == empty()) {
            elems[pos].value = elem;
            elems[pos].frequency = 1;
            current_size++;
            return;
        }
        if (elems[pos].value == elem) {
            elems[pos].frequency += 1;
            current_size++;
            return;
        }
        i++;
    }
    i = 0;
    while (i < m) {
        int pos = hash_function(elem, m, i);
        if (elems[pos].value == deleted()) {
            elems[pos].value = elem;
            elems[pos].frequency = 1;
            current_size++;
            return;
        }
        i++;
    }
}

//BC: Theta(1) WC: Theta(m)
bool Bag::remove(TElem elem) {
    int i = 0;
    while (i < m) {
        int pos = hash_function(elem, m, i);
        if (elems[pos].value == elem) {
            if (elems[pos].value == empty())
                return false;
            if (elems[pos].frequency == 1) {
                elems[pos].value = deleted();
                elems[pos].frequency = 0;
            } else
                elems[pos].frequency -= 1;
            current_size--;
            current_deleted++;
            return true;
        }
        i++;
    }
    if (current_size <= m / 4 && m >= 32)
        resize_down_rehash();

    if (current_deleted >= m / 4)
        rehash();
    return false;
}

//BC: Theta(1) WC: Theta(m)
bool Bag::search(TElem elem) const {
    int i = 0;
    while (i < m) {
        int pos = hash_function(elem, m, i);
        if (elems[pos].value == empty())
            return false;

        if (elems[pos].value == elem) {
            return true;
        }
        i++;
    }
    return false;
}

//BC: Theta(1) WC: Theta(m)
int Bag::nrOccurrences(TElem elem) const {
    int i = 0;
    while (i < m) {
        int pos = hash_function(elem, m, i);
        if (elems[pos].value == empty()) {
            return 0;
        }
        if (elems[pos].value == elem) {
            return elems[pos].frequency;
        }
        i++;
    }
    return 0;
}

//Theta(1)
int Bag::size() const {
    return current_size;
}

//Theta(1)
bool Bag::isEmpty() const {
    return current_size == 0;
}

//Theta(BagIterator)
BagIterator Bag::iterator() const {
    return BagIterator(*this);
}

//Theta(1)
Bag::~Bag() {
    delete[] elems;
}

//Theta(1)
int Bag::hash_function(TElem e, int m, int i) {
    float c1 = 0.5, c2 = 0.5;
    return (int) ((abs(e) % m) + c1 * i + c2 * i * i) % m;
}

//Theta(1)
int Bag::deleted() {
    return DEL_TELEM;
}

//Theta(1)
int Bag::empty() {
    return NULL_TELEM;
}

//WC: Theta(m^2) BC: Theta(m)
void Bag::resize_up_rehash() {
    m *= 2;
    Pair *new_elems = new Pair[m];
    for (int i = 0; i < m; i++) {
        new_elems[i].value = empty();
        new_elems[i].frequency = 0;
    }

    for (int i = 0; i < m / 2; i++) {
        Pair current_pair = elems[i];
        int j = 0;
        while (j < m) {
            int new_pos = hash_function(current_pair.value, m, j);
            if (new_elems[new_pos].value == empty()) {
                new_elems[new_pos].value = current_pair.value;
                new_elems[new_pos].frequency = current_pair.frequency;
                break;
            }
            j++;
        }
    }

    delete[] elems;
    elems = new_elems;
}

//WC: Theta(m^2) BC: Theta(m)
void Bag::resize_down_rehash() {
    m /= 2;
    Pair *new_elems = new Pair[m];
    for (int i = 0; i < m; i++) {
        new_elems[i].value = empty();
        new_elems[i].frequency = 0;
    }

    for (int i = 0; i < m * 2; i++) {
        Pair current_pair = elems[i];
        if (current_pair.value == deleted() || current_pair.value == empty())
            continue;
        int j = 0;
        while (j < m) {
            int new_pos = hash_function(current_pair.value, m, j);
            if (new_elems[new_pos].value == empty()) {
                new_elems[new_pos].value = current_pair.value;
                new_elems[new_pos].frequency = current_pair.frequency;
                break;
            }
            j++;
        }
    }

    delete[] elems;
    elems = new_elems;
}

//WC: Theta(m^2) BC: Theta(m)
void Bag::rehash() {
    Pair *new_elems = new Pair[m];
    for (int i = 0; i < m; i++) {
        new_elems[i].value = empty();
        new_elems[i].frequency = 0;
    }

    for (int i = 0; i < m; i++) {
        Pair current_pair = elems[i];
        if (current_pair.value == deleted() || current_pair.value == empty())
            continue;
        int j = 0;
        while (j < m) {
            int new_pos = hash_function(current_pair.value, m, j);
            if (new_elems[new_pos].value == empty()) {
                new_elems[new_pos].value = current_pair.value;
                new_elems[new_pos].frequency = current_pair.frequency;
                break;
            }
            j++;
        }
    }
    current_deleted = 0;
}

//BC: Theta(m) WC: Theta(m^2)
Bag Bag::unite(Bag b2) {
    int target_capacity = m + b2.m;
    while (b2.m < target_capacity)
        b2.resize_up_rehash();
    for (int j = 0; j < m; j++) {
        int elem = elems[j].value, freq = elems[j].frequency;
        if (elem != deleted() && elem != empty()) {
            int i = 0;
            while (i < b2.m) {
                int pos = hash_function(elem, b2.m, i);
                if (b2.elems[pos].value == empty()) {
                    b2.elems[pos].value = elem;
                    b2.elems[pos].frequency = freq;
                    b2.current_size++;
                    break;
                }
                if (b2.elems[pos].value == elem) {
                    b2.elems[pos].frequency += freq;
                    b2.current_size += freq;
                    break;
                }
                i++;
            }
            if (i == b2.m) {
                i = 0;
                while (i < b2.m) {
                    int pos = hash_function(elem, b2.m, i);
                    if (b2.elems[pos].value == deleted()) {
                        b2.elems[pos].value = elem;
                        b2.elems[pos].frequency = freq;
                        b2.current_size++;
                        break;
                    }
                }
            }
        }
    }
    return b2;
}

