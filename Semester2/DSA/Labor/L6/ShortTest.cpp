#include <assert.h>
#include <iostream>
#include "SortedMultiMap.h"
#include "SMMKIterator.h"
#include "SMMIterator.h"
#include <exception>
#include <vector>

using namespace std;

bool relation1(TKey cheie1, TKey cheie2) {
	if (cheie1 <= cheie2) {
		return true;
	}
	else {
		return false;
	}
}

void testAll(){
	SortedMultiMap smm = SortedMultiMap(relation1);
	assert(smm.size() == 0);
	assert(smm.isEmpty());
    smm.add(1,2);
    smm.add(1,3);
    assert(smm.size() == 2);
    assert(!smm.isEmpty());
    vector<TValue> v= smm.search(1);
    assert(v.size()==2);
    v= smm.search(3);
    assert(v.size()==0);
    SMMIterator it = smm.iterator();
    it.first();
    while (it.valid()){
    	TElem e = it.getCurrent();
    	it.next();
    }
    assert(smm.remove(1, 2) == true);
    assert(smm.remove(1, 3) == true);
    assert(smm.remove(2, 1) == false);
    assert(smm.isEmpty());

    std::cout<< "Test Key Iterator \n";
    smm.add(2,6);
    smm.add(2,5);
    smm.add(1,10);
    smm.add(-1,5);
    smm.add(50,20);
    SMMKIterator kit = smm.key_iterator();
    kit.first();
    assert(kit.getCurrent() == -1);
    kit.next();
    assert(kit.getCurrent() == 1);
    kit.next();
    assert(kit.getCurrent() == 2);
    kit.next();
    assert(kit.getCurrent() == 50);
    kit.next();
    assert(kit.valid() == false);


}

