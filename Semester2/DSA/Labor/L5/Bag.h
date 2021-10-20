#pragma once
//DO NOT INCLUDE BAGITERATOR


//DO NOT CHANGE THIS PART
#define NULL_TELEM -111111;
#define DEL_TELEM INT_MIN;
typedef int TElem;
class BagIterator; 

struct Pair{
		TElem value; 
		int frequency;
	};

class Bag {

private:
	Pair *elems;
	int m, current_size, current_deleted;

	static int hash_function(TElem e, int m, int i);

	void resize_up_rehash();

	void resize_down_rehash();

	void rehash();

    static int deleted() ;

    static int empty() ;

	//DO NOT CHANGE THIS PART
	friend class BagIterator;
public:
	//constructor
	Bag();

	Bag(const Bag &);


	//adds an element to the bag
	void add(TElem e);

	//removes one occurence of an element from a bag
	//returns true if an element was removed, false otherwise (if e was not part of the bag)
	bool remove(TElem e);

	//checks if an element appearch is the bag
	bool search(TElem e) const;

	//returns the number of occurrences for an element in the bag
	int nrOccurrences(TElem e) const;

	//returns the number of elements from the bag
	int size() const;

	//returns an iterator for this bag
	BagIterator iterator() const;

	//checks if the bag is empty
	bool isEmpty() const;

    Bag unite(Bag b2);

	//destructor
	~Bag();
};