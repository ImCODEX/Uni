#include "MatrixIterator.h"
#include <exception>

MatrixIterator::MatrixIterator(const Matrix &matrix) : matrix{matrix}, current_i{0}, current_j{0},
                                                       current_node(matrix.head) {}

//Theta(1)
void MatrixIterator::first() {
    current_i = 0;
    current_j = 0;
    current_node = matrix.head;
}

//Theta(1)
void MatrixIterator::last() {
    current_i = matrix.nr_lines - 1;
    current_j = matrix.nr_columns -1;
    current_node = matrix.tail;
}

//Theta(1)
bool MatrixIterator::valid() const {
    return 0 <= current_i && current_i < matrix.nr_lines && 0 <= current_j && current_j < matrix.nr_columns;
}

//Theta(1)
void MatrixIterator::next() {
    if (!valid())
        throw std::exception();

    if (current_i == matrix.array[current_node].i && current_j == matrix.array[current_node].j && current_node != matrix.tail) //save current != 0 element for get_current()
        current_node = matrix.array[current_node].next; 

    current_j++;
    if (current_j == matrix.nr_columns) {
        current_i++;
        current_j = 0;
    }
}

//Theta(1)
void MatrixIterator::prev() {
    if (!valid())
        throw std::exception();

    if (current_i == matrix.array[current_node].i && current_j == matrix.array[current_node].j && current_node != matrix.head)
        current_node = matrix.array[current_node].prev; 

    current_j--;
    if (current_j == -1) {
        current_i--;
        current_j = matrix.nr_columns-1;
    }
    
}

//Theta(1)
TElem MatrixIterator::get_current() {
    if (!valid())
        throw std::exception();

    if (current_i == matrix.array[current_node].i && current_j == matrix.array[current_node].j) //check if in matrix i am on a non-null element
        return matrix.array[current_node].value;
    
    return NULL_TELEM;
}