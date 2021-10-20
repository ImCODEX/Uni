#pragma once

#include "Node.h"

//DO NOT CHANGE THIS PART
typedef int TElem;
#define NULL_TELEM 0

class MatrixIterator;

class Matrix {

private:
    int nr_lines, nr_columns, current_size, capacity, head, tail, first_empty;
    Node *array;

    //Allocates a new element and returns its position
    //Theta(1)
    int allocate();

    void free(int);

    void insert_after(int, int, int, TElem);

    void resize();

    friend class MatrixIterator;

public:
    //constructor
    Matrix(int nrLines, int nrCols);

    //destructor
    ~Matrix();

    //returns the number of lines
    int nrLines() const;

    //returns the number of columns
    int nrColumns() const;

    //returns the element from line i and column j (indexing starts from 0)
    //throws exception if (i,j) is not a valid position in the Matrix
    TElem element(int i, int j) const;

    //modifies the value from line i and column j
    //returns the previous value from the position
    //throws exception if (i,j) is not a valid position in the Matrix
    TElem modify(int i, int j, TElem e);

    MatrixIterator iterator() const;
};
