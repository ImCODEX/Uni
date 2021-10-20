#pragma once

#include "Matrix.h"

class MatrixIterator {
    friend class Matrix;

private:
    const Matrix &matrix;
    int current_i, current_j;
    int current_node;

    MatrixIterator(const Matrix &matrix);

public:
    void first();

    void last();

    void next();

    void prev();

    bool valid() const;

    TElem get_current();
};
