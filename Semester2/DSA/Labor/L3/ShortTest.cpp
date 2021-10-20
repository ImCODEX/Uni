#include <assert.h>
#include "Matrix.h"
#include "MatrixIterator.h"
#include <iostream>

using namespace std;

void testAll() { 
	Matrix m(4, 4);
	assert(m.nrLines() == 4);
	assert(m.nrColumns() == 4);	
	m.modify(1, 1, 5);
	assert(m.element(1, 1) == 5);
	m.modify(1, 1, 6);
	assert(m.element(1, 2) == NULL_TELEM);


	std::cout << "Test iterator\n";
    m.modify(1, 2, 3);
    m.modify(0, 1, 6);
    MatrixIterator mit = m.iterator();
    TElem expected_elements[16] = {NULL_TELEM, 6, NULL_TELEM, NULL_TELEM, NULL_TELEM, 6, 3, NULL_TELEM,
                                   NULL_TELEM, NULL_TELEM, NULL_TELEM, NULL_TELEM, NULL_TELEM, NULL_TELEM, NULL_TELEM,
                                   NULL_TELEM};
    int current_index = 0;
    while (mit.valid()) {
        TElem current_element = mit.get_current();
        assert(current_element == expected_elements[current_index]);
        current_index++;
        mit.next();
    }

    assert(current_index == 16);

	mit.last();
	current_index--;
	while (mit.valid()) {
        TElem current_element = mit.get_current();
        assert(current_element == expected_elements[current_index]);
        current_index--;
        mit.prev();
    }

    mit.first();
    assert(mit.get_current() == NULL_TELEM);
    mit.next();
    assert(mit.get_current() == 6);

	
}