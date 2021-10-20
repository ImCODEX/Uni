#include "ShortTest.h"
#include <assert.h>
#include "Bag.h"
#include "BagIterator.h"
#include <iostream>


void testAll() { 
	Bag b;
	assert(b.isEmpty() == true);
	assert(b.size() == 0); 
	b.add(5);
	b.add(1);
	b.add(10);
	b.add(7);
	b.add(1);
	b.add(11);
	b.add(-3);
	assert(b.size() == 7);
	assert(b.search(10) == true);
	assert(b.search(16) == false);
	assert(b.nrOccurrences(1) == 2);
	assert(b.nrOccurrences(7) == 1);
	assert(b.remove(1) == true);
	assert(b.remove(6) == false);
	assert(b.size() == 6);
	assert(b.nrOccurrences(1) == 1);
	BagIterator it = b.iterator();
	it.first();
	while (it.valid()) {
		TElem e = it.getCurrent();
		it.next();
	}
    std::cout <<"Test unite \n";
	Bag b2;
    assert(b2.isEmpty() == true);
	b2.add(5);
	b2.add(3);
    b2.add(3);
    b2.add(100);
    assert(b2.size() == 4);
	Bag b3 = b.unite(b2);
	assert(b3.size() == b.size() + b2.size());

    BagIterator it3 = b3.iterator();
    it3.first();
    while (it3.valid()) {
        TElem e = it3.getCurrent();
        assert (b3.nrOccurrences(e) == (b.nrOccurrences(e) + b2.nrOccurrences(e)));
        it3.next();
    }

	Bag b4;
    for (int i = -10; i < 20; i++) {
        b4.add(i);
    }

}
